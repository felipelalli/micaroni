VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDinamicas"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private dinamicas As New Collection
Private idInterno As Integer

Private dinamicasQueDisparam As New Collection
Private dinamicasQueRecebem As New Collection


Private maxDinamicasQueDisparam As Integer
Private maxDinamicasQueRecebem As Integer


Public Function getDinamicasQueDisparam() As Collection
    Set getDinamicasQueDisparam = dinamicasQueDisparam
End Function

Public Function getDinamicasQueRecebem() As Collection
    Set getDinamicasQueRecebem = dinamicasQueRecebem
End Function



Public Function getMaxDinamicasQueDisparam() As Integer
    getMaxDinamicasQueDisparam = maxDinamicasQueDisparam
End Function

Public Function getMaxDinamicasQueRecebem() As Integer
    getMaxDinamicasQueRecebem = maxDinamicasQueRecebem
End Function


Public Function atualizaMaxDinamicas()

    Dim i As Integer
    
    For i = 1 To Me.quantos
    
        Me.carregaDinamicasRelacionadas Me.getDinamicaPeloIndice(i).getId
    
        If Me.getDinamicasQueDisparam.Count > maxDinamicasQueDisparam Then
            maxDinamicasQueDisparam = Me.getDinamicasQueDisparam.Count
        End If
        
        If Me.getDinamicasQueRecebem.Count > maxDinamicasQueRecebem Then
            maxDinamicasQueRecebem = Me.getDinamicasQueRecebem.Count
        End If
    
    Next

End Function


Public Function carregaDinamicasRelacionadas(idDinamica As String)

    Dim i As Integer
    Dim dinamicaP As clsDinamica
    
    Set dinamicasQueDisparam = New Collection
    Set dinamicasQueRecebem = New Collection
    
    Set dinamicaP = Me.getDinamica(idDinamica)
    
    For i = 1 To Me.quantos
    
        Dim recebeu As Boolean
        Dim dinamicaC As clsDinamica
        
        Set dinamicaC = Me.getDinamicaPeloIndice(i)
        
        If dinamicaC.getId <> dinamicaP.getId Then
        
            Dim e As Integer
            Dim idEvento As String
            
            For e = 1 To dinamicaP.getEventosDisparadores.quantosEventos
                
                idEvento = dinamicaP.getEventosDisparadores.getEvento(e).getIdEvento
            
                If dinamicaC.getEventosGerados.possuiEvento(idEvento) Or _
                   dinamicaC.getEventosGeradosSenao.possuiEvento(idEvento) Then
                   
                    dinamicasQueDisparam.add dinamicaC
                    Exit For
                   
                End If
            
            Next
            
            recebeu = False
            
            For e = 1 To dinamicaP.getEventosGerados.quantosEventos
                
                idEvento = dinamicaP.getEventosGerados.getEvento(e).getIdEvento
            
                If dinamicaC.getEventosDisparadores.possuiEvento(idEvento) Then
                
                    dinamicasQueRecebem.add dinamicaC
                    recebeu = True
                    Exit For
                End If
            
            Next
            
            If Not recebeu Then
            
                For e = 1 To dinamicaP.getEventosGeradosSenao.quantosEventos
                    
                    idEvento = dinamicaP.getEventosGeradosSenao.getEvento(e).getIdEvento
                
                    If dinamicaC.getEventosDisparadores.possuiEvento(idEvento) Then
                    
                        dinamicasQueRecebem.add dinamicaC
                        Exit For
                    End If
                
                Next
                
            End If
        
        End If
    
    Next

End Function


Public Function add(nomeDinamica As String, Optional id As String = "__nadinha__") As clsDinamica
    
    Dim dinamica As New clsDinamica
    
    dinamica.setNome nomeDinamica
    
    If id <> "__nadinha__" Then
        dinamica.setId id
    Else
        
        Dim novoId As String
        
        Do
            novoId = "Dinamica" & idInterno
            idInterno = idInterno + 1
            
        Loop While getIndice(novoId) <> -1
        
        dinamica.setId novoId
        
    End If
    
    dinamicas.add dinamica
    
    Set add = dinamica
    
End Function



Public Sub remove(id As String)
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        dinamicas.remove indice
        
    End If
    
End Sub

Public Function quantos() As Integer
    quantos = dinamicas.Count
End Function


Public Function getDinamica(id As String) As clsDinamica
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        Set getDinamica = dinamicas.Item(indice)
        
    Else
    
        Set getDinamica = Nothing
        
    End If
    
End Function

Public Function getDinamicaPeloIndice(indice As Integer) As clsDinamica
        
    Set getDinamicaPeloIndice = dinamicas.Item(indice)
    
End Function



Private Function getIndice(id As String) As Integer
    
    Dim i As Integer
    Dim indice As Integer
    
    indice = -1
    
    For i = 1 To dinamicas.Count
    
        Dim dinamica As clsDinamica
        
        Set dinamica = dinamicas.Item(i)
        
        If dinamica.getId() = id Then
            
            indice = i
            Exit For
            
        End If
    Next
    
    getIndice = indice
    
End Function

Private Sub Class_Initialize()
    idInterno = 0
    maxDinamicasQueDisparam = 0
    maxDinamicasQueRecebem = 0
End Sub



