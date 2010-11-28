VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsEventosAss"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private id As String
Private idInterno As Integer

Private eventos As New Collection

Public Function possuiEvento(idEvento As String) As Boolean

    Dim i As Integer
    
    For i = 1 To Me.quantosEventos
    
        If Me.getEvento(i).getIdEvento = idEvento Then
            possuiEvento = True
            Exit Function
        End If
    
    Next
    
    possuiEvento = False

End Function


Public Function getImagem() As String

    getImagem = Me.getId

    If Me.quebrado Then
        getImagem = getImagem & "_quebrado"
    End If

End Function

Public Function quebrado() As Boolean

    Dim i As Integer
    
    For i = 1 To quantosEventos
    
        If getEvento(i).quebrado Then
            quebrado = True
            Exit Function
        End If
    
    Next

    quebrado = False

End Function


Public Function getId() As String
    getId = id
End Function

Public Function setId(pId As String)
    id = pId
End Function

Public Function addEvento(idEvento As String, Optional id As String = "__nadinha__") As clsEventoAss
    
    Dim evento As New clsEventoAss
    
    If id = "__nadinha__" Then
        evento.setId proximoId
    Else
        evento.setId id
    End If
    
    evento.setIdEvento idEvento
    
    eventos.add evento
    
    Set addEvento = evento
    
End Function

Public Function quantosEventos() As Integer

    quantosEventos = eventos.Count

End Function

Public Function getEventoPeloID(id As String) As clsEventoAss

    Dim i As Integer
    
    For i = 1 To quantosEventos
    
        If getEvento(i).getId = id Then
            Set getEventoPeloID = getEvento(i)
            Exit Function
        End If
    
    Next

    Set getEventoPeloID = Nothing
    

End Function

Public Function getEvento(indice As Integer) As clsEventoAss
    Set getEvento = eventos.Item(indice)
End Function

Public Sub removeEvento(id As String)
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To eventos.Count
    
        Dim evento As clsEventoAss
        
        Set evento = eventos.Item(i)
        
        If evento.getId = id Then
        
            indice = i
            Exit For
            
        End If
    Next
    
    If indice <> -1 Then
    
        eventos.remove indice
        
    End If
    
End Sub



Private Function proximoId() As String
    
    Dim i As Integer
    Dim existe As Boolean
    
    Do
        existe = False
    
        proximoId = id & idInterno
    
        idInterno = idInterno + 1
        
        For i = 1 To quantosEventos
        
            If getEvento(i).getId = proximoId Then
                existe = True
                Exit For
            End If
        Next
    
    Loop While existe
    
End Function

Private Sub Class_Initialize()
    idInterno = 0
End Sub


Public Function carregarXML(noXml As clsNoXML)
    
    Dim noEvento As clsNoXML
    
    Set noEvento = noXml.primeiroFilho
        
    While Not noEvento Is Nothing
        
        Dim grupoEventoAss As New clsGrupoXML
        
        grupoEventoAss.carregaGrupoXML noEvento, Array("Id", "IdEvento")
        
        Me.addEvento grupoEventoAss.getCampo("IdEvento").getValor, _
                     grupoEventoAss.getCampo("Id").getValor
                                     
        Set noEvento = noEvento.proximoNo
    Wend
End Function

Public Function toNoXML(nome As String) As IXMLDOMNode

    Dim i As Integer
    Dim salvador As New clsSalvEstados
    Dim noEventos As IXMLDOMNode

    Set noEventos = salvador.criaNo(nome)
    
    For i = 1 To quantosEventos
    
        noEventos.appendChild getEvento(i).toNoXML
    Next
    
    Set toNoXML = noEventos
    
End Function
