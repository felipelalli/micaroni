VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsItens"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Items As New Collection
Private id As Integer


Public Function add(nomeItem As String) As clsItem
        
    Dim indice As Integer
    
    indice = getIndice(nomeItem)
    
    If indice = -1 Then
        
        Dim item As New clsItem
        
        item.setNome nomeItem
        
        Items.add item
        
        Set add = item
        
    End If
    
End Function

Public Sub remove(nome As String)
    Dim indice As Integer
    
    indice = getIndice(nome)
    
    If indice <> -1 Then
        Items.remove indice
    End If
End Sub

Public Function quantos() As Integer
    quantos = Items.Count
End Function

Public Function getItemPeloNome(nome As String) As clsItem

    Dim indice As Integer
    
    indice = getIndice(nome)
    
    If indice <> -1 Then
        Set getItemPeloNome = Items.item(indice)
    Else
        Set getItemPeloNome = Nothing
    End If
    
End Function

Public Function getItem(indice As Integer) As clsItem

    Set getItem = Items.item(indice)
End Function


Private Function getIndice(nome As String) As Integer
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To Items.Count
    
        Dim item As clsItem
        
        Set item = Items.item(i)
        
        If item.getNome() = nome Then
            
            indice = i
            Exit For
            
        End If
    Next
    
    getIndice = indice
    
End Function

Private Sub Class_Initialize()
    id = 0
End Sub
