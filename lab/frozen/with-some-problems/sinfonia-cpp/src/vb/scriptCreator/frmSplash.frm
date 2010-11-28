VERSION 5.00
Begin VB.Form frmSplash 
   BorderStyle     =   3  'Fixed Dialog
   ClientHeight    =   5865
   ClientLeft      =   255
   ClientTop       =   1410
   ClientWidth     =   7440
   ClipControls    =   0   'False
   ControlBox      =   0   'False
   Icon            =   "frmSplash.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5865
   ScaleWidth      =   7440
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.Timer timerSair 
      Enabled         =   0   'False
      Interval        =   2100
      Left            =   6960
      Top             =   0
   End
   Begin VB.Image imgLogo 
      Height          =   5835
      Left            =   0
      Picture         =   "frmSplash.frx":000C
      Top             =   0
      Width           =   7440
   End
End
Attribute VB_Name = "frmSplash"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Public Function iniciaContagem()
    timerSair.Enabled = True
End Function

Private Sub Form_KeyPress(KeyAscii As Integer)
    Unload Me
End Sub

Private Sub imgLogo_Click()
    Unload Me
End Sub

Private Sub timerSair_Timer()
    timerSair.Enabled = False
    Unload Me
End Sub
