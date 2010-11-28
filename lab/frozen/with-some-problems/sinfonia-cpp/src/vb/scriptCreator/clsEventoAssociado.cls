VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsEventoAss"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private id As String
Private idEvento As String

Public Sub setId(pId As String)
    id = pId
End Sub

Public Function getId() As String
    getId = id
End Function

Public Sub setIdEvento(pIdEvento As String)
    idEvento = pIdEvento
End Sub

Public Function getIdEvento() As String
    getIdEvento = idEvento
End Function

Public Function getImagem() As String

    Dim evento As clsEvento
    
    Set evento = definicoes.sinfonia.getEventos.getEvento(getIdEvento)
    
    If Not evento Is Nothing Then
    
        getImagem = evento.getImagem
    
        If evento.quebrado Then
            getImagem = getImagem & "_quebrado"
        End If
    
    Else
    
        getImagem = "evento_quebrado"
    
    End If
    
End Function

Public Function emString(idRelacionado As String) As String
 
    Dim evento As clsEvento
    
    Set evento = definicoes.sinfonia.getEventos.getEvento(getIdEvento)
    
    If Not evento Is Nothing Then
    
        emString = evento.getNome(idRelacionado)
            
    Else
            
        emString = "Não encontrado! (" & Me.getIdEvento & ")"
        
    End If
    

End Function

Public Function quebrado() As String

    Dim evento As clsEvento
    
    Set evento = definicoes.sinfonia.getEventos.getEvento(getIdEvento)
    
    If evento Is Nothing Then
    
        quebrado = True
        
    Else
    
        quebrado = evento.quebrado
        
    End If

End Function

Public Function toNoXML() As IXMLDOMNode

    Dim i As Integer
    Dim salvador As New clsSalvEstados
    Dim noEvento As IXMLDOMNode
    
    Set noEvento = salvador.criaNo("Evento_Associado")
    
    noEvento.appendChild salvador.criaNo("Id", getId)
    noEvento.appendChild salvador.criaNo("IdEvento", getIdEvento)
    
    Set toNoXML = noEvento

End Function
