VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsGrupoNo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private grupo As String
Private no As clsNoXML

Public Sub setGrupo(pGrupo As String)
    grupo = pGrupo
End Sub

Public Sub setNo(pNo As clsNoXML)
    Set no = pNo
End Sub

Public Function getGrupo() As String
    getGrupo = grupo
End Function

Public Function getNo() As clsNoXML
    Set getNo = no
End Function

Private Sub Class_Initialize()
    Set no = Nothing
End Sub
