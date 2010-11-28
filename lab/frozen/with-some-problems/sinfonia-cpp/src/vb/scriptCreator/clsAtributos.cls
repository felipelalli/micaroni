VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsAtributos"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private atributos As New Collection
Private idInterno As Integer

Public Function add(nomeAtributo As String, Optional id As String = "__nadinha__") As clsAtributo
        
    Dim atributo As New clsAtributo
    
    atributo.setNome nomeAtributo
    
    If id <> "__nadinha__" Then
        atributo.setId id
    Else
        
        Dim novoId As String
        
        Do
            novoId = "Atributos " & idInterno
            idInterno = idInterno + 1
            
        Loop While getIndice(novoId) <> -1
        
        atributo.setId novoId
        
    End If
    
    atributos.add atributo
    
    Set add = atributo
    
End Function

Public Sub remove(id As String)
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
        atributos.remove indice
    End If
End Sub

Public Sub removeIndice(indice As Integer)

    atributos.remove indice

End Sub

Public Function quantos() As Integer
    quantos = atributos.Count
End Function

Public Function getAtributoPeloId(id As String) As clsAtributo

    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
        Set getAtributoPeloId = atributos.Item(indice)
    Else
        Set getAtributoPeloId = Nothing
    End If
    
End Function

Public Function getAtributo(indice As Integer) As clsAtributo
    
    If atributos.Count > 0 Then
    
        Set getAtributo = atributos.Item(indice)
        
    Else
        Set getAtributo = Nothing
    End If
End Function

Public Function getAtributoPrincipal() As clsAtributo

    Dim i As Integer
    Dim atributo As clsAtributo
    
    If quantos > 0 Then
    
        For i = 1 To quantos
        
            Set atributo = getAtributo(i)
            
            If atributo.getPrincipal Then
            
                Set getAtributoPrincipal = atributo
                Exit Function
            
            End If
        
        Next
        
        Set getAtributoPrincipal = getAtributo(1)
        
    Else
    
        Set getAtributoPrincipal = Nothing
    
    End If
End Function

Private Function getIndice(id As String) As Integer
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To atributos.Count
    
        Dim atributo As clsAtributo
        
        Set atributo = atributos.Item(i)
        
        If atributo.getId() = id Then
            
            indice = i
            Exit For
            
        End If
    Next
    
    getIndice = indice
    
End Function

Public Function carregaXML(noXml As clsNoXML)
        
    Dim noAtributoAtual As clsNoXML
                
    Set noAtributoAtual = noXml.primeiroFilho
    
    While Not noAtributoAtual Is Nothing
    
        Me.add("!!_sem_nome_!!").carregaXML noAtributoAtual
        
        Set noAtributoAtual = noAtributoAtual.proximoNo
        
    Wend
    
End Function

Public Function toNoXML() As IXMLDOMNode

    Dim i As Integer
    Dim noAtributos As IXMLDOMNode
    Dim salvador As New clsSalvEstados
    
    Set noAtributos = salvador.criaNo("Atributos")

    For i = 1 To quantos
    
        noAtributos.appendChild getAtributo(i).toNoXML
    
    Next

    Set toNoXML = noAtributos

End Function

Public Function copia(atributos As clsAtributos)

    Dim i As Integer
    
    For i = 1 To Me.quantos
    
        Dim atributoAtual As clsAtributo
        Dim novoAtributo As clsAtributo
    
        Set atributoAtual = Me.getAtributo(i)
        
        Set novoAtributo = atributos.add("copiando")
        
        atributoAtual.copia novoAtributo
    
    Next

End Function


Private Sub Class_Initialize()
    idInterno = 0
End Sub
