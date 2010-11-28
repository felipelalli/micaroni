VERSION 5.00
Begin VB.Form frmVisualizacao 
   BackColor       =   &H00000000&
   Caption         =   "Visualização"
   ClientHeight    =   8790
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   12210
   LinkTopic       =   "Form1"
   ScaleHeight     =   8790
   ScaleWidth      =   12210
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox pbContexto 
      Appearance      =   0  'Flat
      BackColor       =   &H00000000&
      BorderStyle     =   0  'None
      FillColor       =   &H00FF0000&
      ForeColor       =   &H0000FFFF&
      Height          =   8775
      Left            =   0
      ScaleHeight     =   8775
      ScaleWidth      =   12255
      TabIndex        =   0
      Top             =   0
      Width           =   12255
   End
End
Attribute VB_Name = "frmVisualizacao"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit


Private Type tMovimentacao
    pressionado As Boolean
    xInicial As Long
    yInicial As Long
    xRelativo As Long
    yRelativo As Long
End Type

Private movimentacao As tMovimentacao

Private xRelativo As Long
Private yRelativo As Long
Private zoom As Double
Private nivel As Long
Private dinamicaNaTela As New clsDinamicaNaTela

Dim maxNivel As Long

Private idDinamica As String

Public Function carregaDinamica(keyDinamica As String)

    idDinamica = keyDinamica

    Set dinamicaNaTela = New clsDinamicaNaTela

    xRelativo = 0
    yRelativo = 0
    zoom = 1
    nivel = 100

    maxNivel = dinamicaNaTela.carrega(idDinamica, 0, 1, nivel)
    dinamicaNaTela.atualizaPosicao 0, 0
    
    renderiza

End Function

Private Function renderiza()

    pbContexto.Cls
    dinamicaNaTela.desenha Me.pbContexto, xRelativo, yRelativo, zoom

End Function


Private Sub Form_Activate()
    mMouseWheel.WheelHook Me
    renderiza
End Sub

Private Sub Form_Deactivate()
    mMouseWheel.WheelUnHook
End Sub

Private Sub Form_Load()
definicoes.configuracao.posDimContexto.aplica Me
End Sub

Private Sub Form_MouseMove(Button As Integer, shift As Integer, X As Single, Y As Single)
    Form_Resize
End Sub

Private Sub Form_Paint()
    renderiza
End Sub

Private Sub Form_Resize()
    pbContexto.width = frmVisualizacao.width
    pbContexto.height = frmVisualizacao.height
End Sub

Private Sub Form_Unload(Cancel As Integer)
    definicoes.configuracao.posDimContexto.atualiza Me
End Sub


Private Sub pbContexto_KeyPress(KeyAscii As Integer)

'    If Chr(KeyAscii) = "z" Then
'
'        zoom = zoom - 0.1
'        If zoom <= 0.1 Then
'            zoom = 0.1
'        End If
'
'    ElseIf Chr(KeyAscii) = "x" Then
'
'        zoom = zoom + 0.1
'
'    End If
'
'    renderiza

End Sub

Private Sub pbContexto_MouseDown(Button As Integer, shift As Integer, X As Single, Y As Single)

    Dim keyDinamica As String
    
    keyDinamica = dinamicaNaTela.dinamica(CLng(X), CLng(Y))

    If keyDinamica <> "" Then
    
        Me.carregaDinamica keyDinamica
        
        frmDinamica.carregaDinamica definicoes.sinfonia.getDinamicas.getDinamica(keyDinamica), _
                                    frmPrincipal.iaSinfonia.nosArvore.Item(keyDinamica)
                                    
        Me.Show
    
    Else

        If Button = vbLeftButton Then
            movimentacao.pressionado = True
            movimentacao.xInicial = X
            movimentacao.yInicial = Y
            movimentacao.xRelativo = xRelativo
            movimentacao.yRelativo = yRelativo
            
        ElseIf Button = vbRightButton Then
            
            xRelativo = 0
            yRelativo = 0
            zoom = 1
            renderiza
        
        End If
    End If
End Sub


Private Sub pbContexto_MouseMove(Button As Integer, shift As Integer, X As Single, Y As Single)

    Dim keyDinamica As String
    
    keyDinamica = dinamicaNaTela.dinamica(CLng(X), CLng(Y))

    If keyDinamica <> "" Then
        
        Me.MousePointer = vbUpArrow
        
    Else
    
        Me.MousePointer = vbDefault
        
    End If

    If movimentacao.pressionado Then
        xRelativo = movimentacao.xRelativo + X - movimentacao.xInicial
        yRelativo = movimentacao.yRelativo + Y - movimentacao.yInicial
        renderiza
    End If
End Sub


Private Sub pbContexto_MouseUp(Button As Integer, shift As Integer, X As Single, Y As Single)
    movimentacao.pressionado = False
End Sub


Public Sub MouseWheel(ByVal MouseKeys As Long, ByVal Rotation As Long, ByVal Xpos As Long, ByVal Ypos As Long)

    Dim controlPressionado As Boolean
                    
    controlPressionado = MouseKeys And &H8&

    If controlPressionado Then
    
        If Rotation > 0 Then
            nivel = nivel + 1
            
            If nivel > (maxNivel + 1) Then
                nivel = maxNivel + 1
            End If
            
        Else
        
            If nivel = (maxNivel + 1) Then
                nivel = maxNivel - 1
            Else
                nivel = nivel - 1
                If nivel < 1 Then
                    nivel = 1
                End If
            End If
        End If
        
        
        maxNivel = dinamicaNaTela.carrega(idDinamica, 0, 1, nivel)

    Else
        If Rotation > 0 Then
            zoom = zoom + 0.1
        Else
            zoom = zoom - 0.1
            If zoom <= 0.1 Then
                zoom = 0.1
            End If
        End If
    End If
    
    renderiza

End Sub
