VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsArquivoXML"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit


Private documentoXML As New MSXML2.DOMDocument


Public Function carregaArquivo(arquivo As String) As Boolean

    If Not documentoXML.Load(arquivo) Then
        
        carregaArquivo = False
        
    Else
    
        Dim noPrincipal As New clsNoXML
        noPrincipal.setNoXML documentoXML.documentElement
        
        carregaArquivo = True
        
    End If

End Function

Public Function noPrincipal() As clsNoXML
    
    Dim no As New clsNoXML
    no.setNoXML documentoXML.documentElement
    Set noPrincipal = no
    
End Function

Public Sub escreveXML(no As clsNoXML, Optional nivel As String = "")

    If Not no Is Nothing Then
                
        Debug.Print nivel & "<" & no.nome & ">"
        
        If no.valor <> "" Then
            Debug.Print nivel & "   '" & no.valor & "'"
        End If

        If no.possuiFilhos Then

            escreveXML no.primeiroFilho, nivel & "   "
        End If

        Debug.Print nivel & "</" & no.nome & ">"
                    

        escreveXML no.proximoNo, nivel
    End If

End Sub
