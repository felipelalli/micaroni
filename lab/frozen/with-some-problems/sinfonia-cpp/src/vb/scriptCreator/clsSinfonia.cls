VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsSinfonia"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private nome As String
Private estados As New clsEstados
Private grupos As New clsGrupos
Private eventos As New clsEventos
Private dinamicas As New clsDinamicas


Public Sub setNome(pNome As String)
    nome = pNome
End Sub

Public Function getNome() As String
    getNome = nome
End Function

Public Function getEstados() As clsEstados
    Set getEstados = estados
End Function

Public Function getGrupos() As clsGrupos
    Set getGrupos = grupos
End Function

Public Function getEventos() As clsEventos
    Set getEventos = eventos
End Function

Public Function getDinamicas() As clsDinamicas
    Set getDinamicas = dinamicas
End Function

Public Function getImagem() As String
    getImagem = "aplicacao"
End Function

Public Function carregaXML(noXml As clsNoXML)

    Dim grupoSinfonia As New clsGrupoXML
    
    grupoSinfonia.carregaGrupoXML noXml, Array("Nome")
    
    Me.setNome grupoSinfonia.getCampo("Nome").getValor
   
    percorreArvore noXml.primeiroFilho
    
End Function


Private Function percorreArvore(noXml As clsNoXML)

    If Not noXml Is Nothing Then

        If noXml.nome = "Grupo" Then
        
            definicoes.sinfonia.getGrupos.add("!!_sem_nome_!!").carregaXML noXml
            
            percorreArvore noXml.primeiroFilho
            
         ElseIf noXml.nome = "Evento" Then
         
            definicoes.sinfonia.getEventos.add("!!_sem_nome_!!").carregaXML noXml
         
         ElseIf noXml.nome = "Estado" Then
         
            definicoes.sinfonia.getEstados.add("!!_sem_nome_!!").carregaXML noXml
         
         ElseIf noXml.nome = "Dinamica" Then
         
            definicoes.sinfonia.getDinamicas.add("!!_sem_nome_!!").carregaXML noXml
        
        End If
         
        percorreArvore noXml.proximoNo
         
    End If
    
End Function


























