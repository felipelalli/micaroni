VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsEstados"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private estados As New Collection
Private idInterno As Integer



Public Function add(nomeEstado As String, Optional id As String = "__nadinha__") As clsEstado
    
    Dim estado As New clsEstado
    
    estado.setNome nomeEstado
    
    If id <> "__nadinha__" Then
        estado.setId id
    Else
    
        Dim novoId As String
        
        Do
            novoId = "Sinfonia_Estado" & idInterno
            idInterno = idInterno + 1
            
        Loop While getIndice(novoId) <> -1
        
        estado.setId novoId
        
    End If
    
    estados.add estado
    
    Set add = estado
    
End Function



Public Sub remove(id As String)
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        estados.remove indice
        
    End If
    
End Sub

Public Function quantos() As Integer
    quantos = estados.Count
End Function


Public Function getEstado(id As String) As clsEstado
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        Set getEstado = estados.Item(indice)
        
    Else
    
        Set getEstado = Nothing
        
    End If
    
End Function

Public Function getEstadoPeloIndice(indice As Integer) As clsEstado
        
    Set getEstadoPeloIndice = estados.Item(indice)
    
End Function



Private Function getIndice(id As String) As Integer
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To estados.Count
    
        Dim estado As clsEstado
        
        Set estado = estados.Item(i)
        
        If estado.getId() = id Then
            
            indice = i
            Exit For
            
        End If
    Next
    
    getIndice = indice
    
End Function

Private Sub Class_Initialize()
    idInterno = 0
End Sub
