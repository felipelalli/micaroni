VERSION 5.00
Begin VB.Form frmLixeira 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Lixeira"
   ClientHeight    =   1440
   ClientLeft      =   13935
   ClientTop       =   7770
   ClientWidth     =   1275
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1440
   ScaleWidth      =   1275
   ShowInTaskbar   =   0   'False
   Begin VB.Image lixeira 
      BorderStyle     =   1  'Fixed Single
      Height          =   1440
      Left            =   0
      OLEDropMode     =   1  'Manual
      Picture         =   "frmLixeira.frx":0000
      Stretch         =   -1  'True
      Top             =   0
      Width           =   1275
   End
End
Attribute VB_Name = "frmLixeira"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
    definicoes.configuracao.posDimLixeira.aplica Me
End Sub

Private Sub Form_Unload(Cancel As Integer)
    definicoes.configuracao.posDimLixeira.atualiza Me
End Sub

Private Sub lixeira_OLEDragOver(Data As DataObject, Effect As Long, Button As Integer, shift As Integer, X As Single, Y As Single, State As Integer)
    Effect = vbDropEffectCopy
End Sub

Private Sub lixeira_OLEDragDrop(Data As DataObject, Effect As Long, Button As Integer, shift As Integer, X As Single, Y As Single)

    If Data.GetFormat(vbCFText) Then

        Dim key As String
        Dim deletar As Boolean
        
        key = Data.GetData(vbCFText)

        deletar = True

        If InStr(1, key, "Sinfonia") <> 0 Then
    
            If InStr(1, key, "Estado_Dependente") = 0 Then
            
                Select Case definicoes.tipoNoAtual
                
                    Case tnEvento
                        definicoes.sinfonia.getEventos.remove (key)
                        frmEvento.Hide
                        
                    Case tnEstado
                        definicoes.sinfonia.getEstados.remove (key)
                        frmEstado.Hide
                                                
                    Case tnDinamica
                        definicoes.sinfonia.getDinamicas.remove (key)
                        frmDinamica.Hide
                        
                    Case tnGrupo
                        definicoes.sinfonia.getGrupos.remove (key)
                        frmGrupo.Hide
                        
                    Case tnAplicacao
                        deletar = False
                End Select
                
                If deletar Then
                    frmPrincipal.iaSinfonia.nosArvore.remove (key)
                    frmPrincipal.atualizaIcones
                End If
            
            ElseIf (InStr(1, key, "Estado_Dependente_") <> 0) And _
                   (Mid(key, Len(key)) <> "0") Then
            
                definicoes.eventoAtual.getEstadoDep.remove key
                frmEvento.carregaEvento definicoes.eventoAtual, definicoes.noEventoAtual
                frmPrincipal.atualizaIcones
            End If
                
        ElseIf InStr(1, key, "Atributos") <> 0 Then
        
            definicoes.estadoAtual.getAtributos.remove (key)
            frmEstado.iaAtributos.nosArvore.remove key
            frmEstado.limpaAtributo
            frmPrincipal.atualizaIcones
        
        ElseIf InStr(1, key, "Parametros") <> 0 Then
        
            definicoes.atributoAtual.getParametros.remove key
            frmEstado.iaParametros.nosArvore.remove key
            frmPrincipal.atualizaIcones
            
        Else
            
            If (InStr(1, key, "Condicao") <> 0) And _
               (InStr(1, key, "Estado") = 0) And _
               (InStr(1, key, "Operador") = 0) And _
               (key <> "Condicao_Principal") Then
               
                definicoes.dinamicaAtual.getCondicao.getCondicao(key).getPai.remove (key)
                frmDinamica.carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
                frmPrincipal.atualizaIcones
                
            ElseIf (InStr(1, key, "Condicao") <> 0) And _
                    (InStr(1, key, "Estado") <> 0) And _
                    (InStr(1, key, "__") <> 0) And _
                    (Mid(key, Len(key)) <> "0") Then
                                    
                                                                    
                definicoes.dinamicaAtual.getCondicao.getEstadoComposto(key).getPai.remove (key)
                frmDinamica.carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
                frmPrincipal.atualizaIcones
                
            Else
            
                definicoes.dinamicaAtual.getEventosGerados.removeEvento key
                definicoes.dinamicaAtual.getEventosGeradosSenao.removeEvento key
                definicoes.dinamicaAtual.getEventosDisparadores.removeEvento key
                                                        
                frmDinamica.carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
                frmPrincipal.atualizaIcones
                                    
            End If
            
        End If
    End If
End Sub
