VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsGrupos"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private grupos As New Collection
Private idInterno As Integer


Public Function getGrupoPeloNomeCompleto(nome As String)

    Dim i As Integer

    For i = 1 To Me.quantos
    
        Dim nomeGrupo As String
        Dim grupo As clsGrupo
        
        Set grupo = Me.getGrupoPeloIndice(i)
        
        nomeGrupo = definicoes.caminhoCompleto(grupo.getId)
        
        If nomeGrupo <> "" Then
            nomeGrupo = nomeGrupo & "." & grupo.getNome
            
        Else
            nomeGrupo = grupo.getNome
        End If
        
        If nome = nomeGrupo Then
            Set getGrupoPeloNomeCompleto = grupo
            Exit Function
        End If
    Next

    Set getGrupoPeloNomeCompleto = Nothing

End Function



Public Function add(nomeGrupo As String, Optional id As String = "__nadinha__") As clsGrupo
    
    Dim grupo As New clsGrupo
    
    grupo.setNome nomeGrupo
    
    If id <> "__nadinha__" Then
        grupo.setId id
    Else
        grupo.setId "Grupo" & idInterno
        idInterno = idInterno + 1
    End If
    
    grupo.setCor RGB((255 * Rnd) + 1, (255 * Rnd) + 1, (255 * Rnd) + 1)
    
    grupos.add grupo
    
    Set add = grupo
    
End Function



Public Sub remove(id As String)
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        grupos.remove indice
        
    End If
    
End Sub

Public Function quantos() As Integer
    quantos = grupos.Count
End Function


Public Function getGrupo(id As String) As clsGrupo
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        Set getGrupo = grupos.Item(indice)
        
    Else
    
        Set getGrupo = Nothing
        
    End If
    
End Function

Public Function getGrupoPeloIndice(indice As Integer) As clsGrupo
        
    Set getGrupoPeloIndice = grupos.Item(indice)
    
End Function



Private Function getIndice(id As String) As Integer
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To grupos.Count
    
        Dim grupo As clsGrupo
        
        Set grupo = grupos.Item(i)
        
        If grupo.getId() = id Then
            
            indice = i
            Exit For
            
        End If
    Next
    
    getIndice = indice
    
End Function

Private Sub Class_Initialize()
    idInterno = 0
End Sub

