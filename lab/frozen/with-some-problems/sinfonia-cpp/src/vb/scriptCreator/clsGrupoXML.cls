VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsGrupoXML"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private resultCampo As Collection
Private resultGrupo As Collection


Public Sub carregaGrupoXML(noPrincipal As clsNoXML, Optional parametros As Variant, Optional grupos As Variant)

    Dim noAtual As clsNoXML
    
    criaVazio parametros, grupos
    
    Set noAtual = noPrincipal.primeiroFilho
    
    While Not noAtual Is Nothing
    
        Dim campo As clsCampoValor
        Dim grupo As clsGrupoNo
        
    
        Set campo = getCampo(noAtual.nome)
        
        If Not campo Is Nothing Then
        
            campo.setValor noAtual.valor
            
        Else
        
            Set grupo = getGrupo(noAtual.nome)
        
            If Not grupo Is Nothing Then
        
                grupo.setNo noAtual
            
            End If
            
        End If
    
        Set noAtual = noAtual.proximoNo
    
    Wend

End Sub

Public Function getCampo(campo As String) As clsCampoValor

    Dim i As Integer

    Set getCampo = Nothing

    For i = 1 To resultCampo.Count
    
        Dim result As clsCampoValor
        
        Set result = resultCampo.Item(i)
        
        If result.getCampo = campo Then
        
            Set getCampo = result
        
        End If
    
    Next

End Function

Public Function getGrupo(grupo As String) As clsGrupoNo

    Dim i As Integer

    Set getGrupo = Nothing

    For i = 1 To resultGrupo.Count
    
        Dim result As clsGrupoNo
        
        Set result = resultGrupo.Item(i)
        
        If result.getGrupo() = grupo Then
        
            Set getGrupo = result
        
        End If
    
    Next

End Function

Private Sub criaVazio(Optional parametros As Variant, Optional grupos As Variant)

    Dim i As Integer

    Set resultCampo = New Collection

    If Not IsMissing(parametros) Then
        For i = 0 To UBound(parametros)
        
            Dim campo As clsCampoValor
            
            Set campo = New clsCampoValor
            
            campo.setCampo CStr(parametros(i))
            
            resultCampo.add campo
        Next
    End If
    
    Set resultGrupo = New Collection
    
    If Not IsMissing(grupos) Then
        For i = 0 To UBound(grupos)
        
            Dim grupo As clsGrupoNo
            
            Set grupo = New clsGrupoNo
            
            grupo.setGrupo CStr(grupos(i))
            
            resultGrupo.add grupo
        Next
    End If
End Sub
