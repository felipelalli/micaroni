VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsCampoValor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private campo As String
Private valor As String

Public Sub setCampo(pCampo As String)
    campo = pCampo
End Sub

Public Sub setValor(pValor As String)
    valor = pValor
End Sub

Public Function getCampo() As String
    getCampo = campo
End Function

Public Function getValor() As String
    getValor = valor
End Function

Public Function semValor() As Boolean
    semValor = (valor = "nadinha---")
End Function

Private Sub Class_Initialize()
    valor = "nadinha---"
End Sub
