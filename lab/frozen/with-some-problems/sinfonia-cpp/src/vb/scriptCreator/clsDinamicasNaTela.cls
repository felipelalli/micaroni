VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDinNaTela"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private dinamicas As New Collection

Public Function quantas() As Integer

    quantas = dinamicas.Count

End Function

Public Function getDinamica(qual As Integer) As clsDinamicaNaTela
    Set getDinamica = dinamicas.Item(qual)
End Function

Public Function addDinamica(dinamica As clsDinamicaNaTela)
    dinamicas.add dinamica
End Function
