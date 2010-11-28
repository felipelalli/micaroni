VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsEventos"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private eventos As New Collection
Private idInterno As Integer




Public Function add(nomeEvento As String, Optional id As String = "__nadinha__") As clsEvento
    
    Dim evento As New clsEvento
    
    evento.setNome nomeEvento
    
    If id <> "__nadinha__" Then
        evento.setId id
    Else
        
        Dim novoId As String
        
        Do
            novoId = "Evento" & idInterno
            idInterno = idInterno + 1
            
        Loop While getIndice(novoId) <> -1
        
        evento.setId novoId
        
    End If
    
    eventos.add evento
    
    Set add = evento
    
End Function



Public Sub remove(id As String)
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        eventos.remove indice
        
    End If
    
End Sub

Public Function quantos() As Integer
    quantos = eventos.Count
End Function


Public Function getEvento(id As String) As clsEvento
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        Set getEvento = eventos.Item(indice)
        
    Else
    
        Set getEvento = Nothing
        
    End If
    
End Function

Public Function getEventoPeloIndice(indice As Integer) As clsEvento
        
    Set getEventoPeloIndice = eventos.Item(indice)
    
End Function



Private Function getIndice(id As String) As Integer
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To eventos.Count
    
        Dim evento As clsEvento
        
        Set evento = eventos.Item(i)
        
        If evento.getId() = id Then
            
            indice = i
            Exit For
            
        End If
    Next
    
    getIndice = indice
    
End Function

Private Sub Class_Initialize()
    idInterno = 0
End Sub


Public Function carregaXML(noXml As clsNoXML)
        
    Dim noEventoAtual As clsNoXML
                
    Set noEventoAtual = noXml.primeiroFilho
    
    While Not noEventoAtual Is Nothing
    
        Me.add("!!_sem_nome_!!").carregaXML noEventoAtual
        
        Set noEventoAtual = noEventoAtual.proximoNo
    Wend
    
End Function

