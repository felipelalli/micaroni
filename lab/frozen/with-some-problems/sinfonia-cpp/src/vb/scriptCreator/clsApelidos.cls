VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsApelidos"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private apelidos As New Collection
Private idParametro As String
Private idInterno As Integer

Public Sub setIdPai(pIdParametro As String)
    idParametro = pIdParametro
End Sub

Public Function add(nomeApelido As String, Optional id As String = "__nadinha__") As clsApelido
        
    Dim apelido As New clsApelido
    
    apelido.setNome nomeApelido
    
    If id <> "__nadinha__" Then
        apelido.setId id
    Else
    
        Dim novoId As String
        
        Do
            novoId = idParametro & "-Apelido" & idInterno
            idInterno = idInterno + 1
            
        Loop While getIndice(novoId) <> -1
        
        apelido.setId novoId
        
    End If
    
    apelidos.add apelido
    
    Set add = apelido
    
End Function

Public Sub remove(id As String)
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
        apelidos.remove indice
    End If
End Sub

Public Function quantos() As Integer
    quantos = apelidos.Count
End Function

Public Function getApelidoPeloId(id As String) As clsApelido

    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
        Set getApelidoPeloId = apelidos.Item(indice)
    Else
        Set getApelidoPeloId = Null
    End If
    
End Function

Public Function getApelido(indice As Integer) As clsApelido

    Set getApelido = apelidos.Item(indice)
End Function


Private Function getIndice(id As String) As Integer
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To apelidos.Count
    
        Dim apelido As clsApelido
        
        Set apelido = apelidos.Item(i)
        
        If apelido.getId() = id Then
            
            indice = i
            Exit For
            
        End If
    Next
    
    getIndice = indice
    
End Function

Public Function copia(apelidos As clsApelidos)

    Dim i As Integer
    
    For i = 1 To Me.quantos
    
        Dim apelidoAtual As clsApelido
        Dim novoApelido As clsApelido
        
        Set apelidoAtual = Me.getApelido(i)
        
        Set novoApelido = apelidos.add("Copiando")
        
        apelidoAtual.copia novoApelido
    
    Next

End Function

Public Function carregaXML(noXml As clsNoXML)
    
    Dim noApelidoAtual As clsNoXML
    
    Set noApelidoAtual = noXml.primeiroFilho
    
    While Not noApelidoAtual Is Nothing
    
        Me.add("!!_nenhum_!!").carregaXML noApelidoAtual
        
        Set noApelidoAtual = noApelidoAtual.proximoNo
    
    Wend
    
End Function

Public Function toNoXML() As IXMLDOMNode

    Dim i As Integer
    Dim noApelidos As IXMLDOMNode
    Dim salvador As New clsSalvEstados
    
    Set noApelidos = salvador.criaNo("Apelidos")

    For i = 1 To quantos
    
        noApelidos.appendChild getApelido(i).toNoXML
    
    Next
    
    Set toNoXML = noApelidos

End Function

Private Sub Class_Initialize()
    idInterno = 0
End Sub
