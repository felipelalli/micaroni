VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form frmGrupo 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Grupo"
   ClientHeight    =   2895
   ClientLeft      =   12300
   ClientTop       =   10125
   ClientWidth     =   6735
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2895
   ScaleWidth      =   6735
   ShowInTaskbar   =   0   'False
   Begin VB.Frame frmGrupo 
      Caption         =   "Grupo"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   2655
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   6495
      Begin VB.PictureBox pbCor 
         Appearance      =   0  'Flat
         BackColor       =   &H80000007&
         ForeColor       =   &H80000008&
         Height          =   855
         Left            =   4200
         ScaleHeight     =   825
         ScaleWidth      =   2025
         TabIndex        =   5
         Top             =   360
         Width           =   2055
      End
      Begin MSComDlg.CommonDialog cdCor 
         Left            =   3480
         Top             =   840
         _ExtentX        =   847
         _ExtentY        =   847
         _Version        =   393216
      End
      Begin VB.TextBox txtDescricaoGrupo 
         Appearance      =   0  'Flat
         BeginProperty Font 
            Name            =   "Comic Sans MS"
            Size            =   9.75
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   975
         Left            =   240
         MultiLine       =   -1  'True
         ScrollBars      =   2  'Vertical
         TabIndex        =   2
         Top             =   1440
         Width           =   6015
      End
      Begin VB.TextBox txtNomeGrupo 
         Appearance      =   0  'Flat
         BeginProperty Font 
            Name            =   "Comic Sans MS"
            Size            =   9.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   345
         Left            =   960
         TabIndex        =   1
         Top             =   480
         Width           =   3015
      End
      Begin VB.Label lbDescricaoGrupo 
         Caption         =   "Descrição"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   9
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   4
         Top             =   1080
         Width           =   1095
      End
      Begin VB.Label lbNomeGrupo 
         Caption         =   "Nome"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   9
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   3
         Top             =   480
         Width           =   495
      End
   End
End
Attribute VB_Name = "frmGrupo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Sub carregaGrupo(grupo As clsGrupo, no As Node)

      If Not grupo Is Nothing Then
         
        Set definicoes.noGrupoAtual = no
            
        If Not Me.Visible Then
            definicoes.configuracao.posDimGrupo.aplica Me
        End If
            
        Me.Show
            
        limpaGrupo
            
        txtNomeGrupo.Text = grupo.getNome
        txtDescricaoGrupo.Text = grupo.getDescricao
        pbCor.BackColor = grupo.getCor
        pbCor.Cls
        
        habilitaGrupo True
    
        Set definicoes.grupoAtual = grupo
    
    Else
    
        limpaGrupo
    
    End If
End Sub


Public Sub limpaGrupo()

    Set definicoes.grupoAtual = Nothing
    
    txtNomeGrupo.Text = ""
    txtDescricaoGrupo.Text = ""
    habilitaGrupo False
End Sub


Public Sub habilitaGrupo(habilita As Boolean)

    txtNomeGrupo.Enabled = habilita
    txtDescricaoGrupo.Enabled = habilita
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    definicoes.configuracao.posDimGrupo.atualiza Me
End Sub

Private Sub pbCor_Click()
On Error Resume Next
    cdCor.Flags = cdlCCRGBInit
    cdCor.ShowColor
    definicoes.grupoAtual.setCor cdCor.Color
    pbCor.BackColor = definicoes.grupoAtual.getCor
    pbCor.Cls
End Sub

Private Sub txtNomeGrupo_Change()
    If Not definicoes.grupoAtual Is Nothing Then
        definicoes.grupoAtual.setNome txtNomeGrupo.Text
        definicoes.noGrupoAtual.Text = definicoes.grupoAtual.getNome
    End If
End Sub

Private Sub txtDescricaoGrupo_Change()
    If Not definicoes.grupoAtual Is Nothing Then
        definicoes.grupoAtual.setDescricao txtDescricaoGrupo.Text
    End If
End Sub
