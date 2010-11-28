VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsParametros"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private parametros As New Collection
Private idInterno As Integer

Public Function add(nomeParametro As String, Optional id As String = "__nadinha__") As clsParametro
        
    Dim parametro As New clsParametro
    
    parametro.setNome nomeParametro
    
    If id <> "__nadinha__" Then
        parametro.setId id
    Else
    
        Dim novoId As String
        
        Do
            novoId = "Parametros " & idInterno
            idInterno = idInterno + 1
            
        Loop While getIndice(novoId) <> -1
        
        parametro.setId novoId
        
    End If
    
    parametros.add parametro
    
    Set add = parametro
    
End Function

Public Sub remove(id As String)
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
        parametros.remove indice
        
    Else
        Dim i As Integer
        
        For i = 1 To quantos
        
            getParametro(i).getApelidos.remove id
        Next
        
    End If
End Sub

Public Function quantos() As Integer
    quantos = parametros.Count
End Function

Public Function getParametroPeloId(id As String) As clsParametro

    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
        Set getParametroPeloId = parametros.Item(indice)
    Else
        Set getParametroPeloId = Nothing
    End If
    
End Function

Public Function getParametro(indice As Integer) As clsParametro

    Set getParametro = parametros.Item(indice)
End Function

Public Function proximoParametro()

    Dim iValorInicial As Integer
    
    iValorInicial = getIndiceValorInicial

    If iValorInicial = -1 Then
        If Me.quantos > 0 Then
            Me.getParametro(1).setValorInicial True
        End If
    Else
        Me.getParametro(iValorInicial).setValorInicial False
        
        If (iValorInicial + 1) > Me.quantos Then
            Me.getParametro(1).setValorInicial True
        Else
            Me.getParametro(iValorInicial + 1).setValorInicial True
        End If
    End If
End Function

Private Function getIndiceValorInicial() As Integer
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To parametros.Count
    
        Dim parametro As clsParametro
        
        Set parametro = parametros.Item(i)
        
        If parametro.getValorInicial Then
            
            indice = i
            Exit For
            
        End If
    Next
    
    getIndiceValorInicial = indice
    
End Function

Private Function getIndice(id As String) As Integer
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To parametros.Count
    
        Dim parametro As clsParametro
        
        Set parametro = parametros.Item(i)
        
        If parametro.getId() = id Then
            
            indice = i
            Exit For
            
        End If
    Next
    
    getIndice = indice
    
End Function

Public Function copia(parametros As clsParametros)

    Dim i As Integer
    
    For i = 1 To Me.quantos
    
        Dim parametroAtual As clsParametro
        Dim novoParametro As clsParametro
        
        Set parametroAtual = Me.getParametro(i)
        
        Set novoParametro = parametros.add("copia ")
        
        parametroAtual.copia novoParametro
    
    Next

End Function

Public Function carregaXML(noXml As clsNoXML)

    Dim noParametroAtual As clsNoXML
        
    Set noParametroAtual = noXml.primeiroFilho
    
    While Not noParametroAtual Is Nothing
    
        Me.add("!!_sem_nome_!!").carregaXML noParametroAtual
    
        Set noParametroAtual = noParametroAtual.proximoNo
    
    Wend
    
End Function

Public Function toNoXML() As IXMLDOMNode

    Dim i As Integer
    Dim noParametros As IXMLDOMNode
    Dim salvador As New clsSalvEstados
    
    Set noParametros = salvador.criaNo("Parametros")

    For i = 1 To quantos
    
        noParametros.appendChild getParametro(i).toNoXML
    
    Next

    Set toNoXML = noParametros

End Function

Private Sub Class_Initialize()
    idInterno = 0
End Sub
