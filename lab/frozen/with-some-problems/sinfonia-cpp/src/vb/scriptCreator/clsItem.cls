VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsItem"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private nome As String
Private grupo As Boolean
Private imagem As String
Private imagemAberto As String
Private marcacao As TipoMarcacao
Private paisPossiveis As New Collection

Public Sub setNome(pNome As String)
    nome = pNome
End Sub

Public Function getNome() As String
    getNome = nome
End Function

Public Sub setGrupo(pGrupo As Boolean)
    grupo = pGrupo
End Sub

Public Sub setMarcacao(pMarcacao As TipoMarcacao)
    marcacao = pMarcacao
End Sub

Public Function getGrupo() As Boolean
    getGrupo = grupo
End Function

Public Sub setImagem(pImagem As String)
    imagem = pImagem
End Sub

Public Function getImagem() As String
    getImagem = imagem
End Function

Public Sub setImagemAberto(pImagemAberto As String)
    imagemAberto = pImagemAberto
End Sub

Public Function getImagemAberto() As String
    getImagemAberto = imagemAberto
End Function

Public Function getMarcacao() As TipoMarcacao
    getMarcacao = marcacao
End Function

Public Sub addPaiPossivel(pai As String)
    paisPossiveis.add pai
End Sub

Public Function possuiRestricaoDePai() As Boolean
    possuiRestricaoDePai = (paisPossiveis.Count > 0)
End Function

Public Function ehPai(nomePai As String) As Boolean

    Dim i As Integer
    Dim achouPai As Boolean
    
    achouPai = False
    
    For i = 1 To paisPossiveis.Count
    
        If nomePai = paisPossiveis(i) Then
            achouPai = True
            Exit For
        End If
    Next
    
    ehPai = achouPai
    
End Function
