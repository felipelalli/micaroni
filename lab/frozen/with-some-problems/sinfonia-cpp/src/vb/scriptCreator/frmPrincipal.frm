VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Object = "{7BA52D1B-09C1-45D3-9419-C750185C2CBB}#2.0#0"; "Biblia.ocx"
Begin VB.Form frmPrincipal 
   BackColor       =   &H80000004&
   Caption         =   "Sinfonia ScriptCreator - 2.00"
   ClientHeight    =   7380
   ClientLeft      =   60
   ClientTop       =   630
   ClientWidth     =   7125
   LinkTopic       =   "Form1"
   ScaleHeight     =   7380
   ScaleWidth      =   7125
   Begin VB.Frame frmSinfonia 
      Caption         =   "Sinfonia"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   7095
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   6855
      Begin MSComDlg.CommonDialog cdAbrir 
         Left            =   6120
         Top             =   240
         _ExtentX        =   847
         _ExtentY        =   847
         _Version        =   393216
         DialogTitle     =   "Sinfonia ScriptCreator"
         Filter          =   "Arquivo da Sinfonia (*.xml)|*.xml"
         InitDir         =   "c:\"
      End
      Begin MSComctlLib.ImageList ilIconesArvore 
         Left            =   5520
         Top             =   240
         _ExtentX        =   1005
         _ExtentY        =   1005
         BackColor       =   -2147483643
         ImageWidth      =   16
         ImageHeight     =   16
         MaskColor       =   16777215
         _Version        =   393216
         BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
            NumListImages   =   34
            BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":0000
               Key             =   "evento_qualquer_um_deles"
            EndProperty
            BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":0352
               Key             =   "aplicacao"
            EndProperty
            BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":06A4
               Key             =   "dinamica_desabilitada"
            EndProperty
            BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":09F6
               Key             =   "dinamica_desabilitada_quebrado"
            EndProperty
            BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":0D48
               Key             =   "operador"
            EndProperty
            BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":109A
               Key             =   "eventos_disparadores"
            EndProperty
            BeginProperty ListImage7 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":13EC
               Key             =   "eventos_disparadores_quebrado"
            EndProperty
            BeginProperty ListImage8 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":173E
               Key             =   "eventos_gerados"
            EndProperty
            BeginProperty ListImage9 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":1A90
               Key             =   "eventos_gerados_quebrado"
            EndProperty
            BeginProperty ListImage10 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":1DE2
               Key             =   "eventos_gerados_senao"
            EndProperty
            BeginProperty ListImage11 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":2134
               Key             =   "eventos_gerados_senao_quebrado"
            EndProperty
            BeginProperty ListImage12 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":2486
               Key             =   "dinamica"
            EndProperty
            BeginProperty ListImage13 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":27D8
               Key             =   "dinamica_quebrado"
            EndProperty
            BeginProperty ListImage14 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":2B2A
               Key             =   "condicao_comparadora"
            EndProperty
            BeginProperty ListImage15 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":2E7C
               Key             =   "condicao_comparadora_quebrado"
            EndProperty
            BeginProperty ListImage16 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":31CE
               Key             =   "condicao_composta"
            EndProperty
            BeginProperty ListImage17 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":3520
               Key             =   "condicao_composta_quebrado"
            EndProperty
            BeginProperty ListImage18 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":3872
               Key             =   "evento"
            EndProperty
            BeginProperty ListImage19 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":3BC4
               Key             =   "evento_quebrado"
            EndProperty
            BeginProperty ListImage20 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":3F16
               Key             =   "evento_externo"
            EndProperty
            BeginProperty ListImage21 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":4268
               Key             =   "evento_externo_quebrado"
            EndProperty
            BeginProperty ListImage22 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":45BA
               Key             =   "estado_externo"
            EndProperty
            BeginProperty ListImage23 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":490C
               Key             =   "estado_externo_quebrado"
            EndProperty
            BeginProperty ListImage24 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":4C5E
               Key             =   "atributo"
            EndProperty
            BeginProperty ListImage25 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":4FB0
               Key             =   "aplicacao_quebrado"
            EndProperty
            BeginProperty ListImage26 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":5302
               Key             =   "apelido"
            EndProperty
            BeginProperty ListImage27 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":5654
               Key             =   "parametro"
            EndProperty
            BeginProperty ListImage28 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":59A6
               Key             =   "grupo"
            EndProperty
            BeginProperty ListImage29 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":5CF8
               Key             =   "grupo_aberto"
            EndProperty
            BeginProperty ListImage30 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":604A
               Key             =   "parametro_aberto"
            EndProperty
            BeginProperty ListImage31 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":639C
               Key             =   "grupo_quebrado"
            EndProperty
            BeginProperty ListImage32 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":66EE
               Key             =   "grupo_aberto_quebrado"
            EndProperty
            BeginProperty ListImage33 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":6A40
               Key             =   "estado"
            EndProperty
            BeginProperty ListImage34 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":6D92
               Key             =   "estado_quebrado"
            EndProperty
         EndProperty
      End
      Begin MSComctlLib.ImageList ilIconesLista 
         Left            =   4920
         Top             =   240
         _ExtentX        =   1005
         _ExtentY        =   1005
         BackColor       =   -2147483643
         ImageWidth      =   25
         ImageHeight     =   25
         MaskColor       =   12632256
         _Version        =   393216
         BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
            NumListImages   =   10
            BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":70E4
               Key             =   "condicao_comparadora"
            EndProperty
            BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":78A2
               Key             =   "condicao_composta"
            EndProperty
            BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":8060
               Key             =   "dinamica"
            EndProperty
            BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":881E
               Key             =   "estado"
            EndProperty
            BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":8FDC
               Key             =   "evento"
            EndProperty
            BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":979A
               Key             =   "apelido"
            EndProperty
            BeginProperty ListImage7 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":9F58
               Key             =   "aplicacao"
            EndProperty
            BeginProperty ListImage8 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":A716
               Key             =   "atributo"
            EndProperty
            BeginProperty ListImage9 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":AED4
               Key             =   "parametro"
            EndProperty
            BeginProperty ListImage10 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmPrincipal.frx":B692
               Key             =   "grupo"
            EndProperty
         EndProperty
      End
      Begin Biblia.ItensEArvore iaSinfonia 
         Height          =   6495
         Left            =   240
         TabIndex        =   1
         Top             =   360
         Width           =   6375
         _ExtentX        =   11245
         _ExtentY        =   11456
      End
   End
   Begin VB.Menu mnuArquivo 
      Caption         =   "Arqui&vo"
      Begin VB.Menu mnuNovo 
         Caption         =   "&Novo"
         Shortcut        =   ^N
      End
      Begin VB.Menu mnuAbrir 
         Caption         =   "&Abrir..."
         Shortcut        =   ^O
      End
      Begin VB.Menu mnuFechar 
         Caption         =   "&Fechar"
      End
      Begin VB.Menu mnuSeparador1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuSalvar 
         Caption         =   "&Salvar"
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuSalvarComo 
         Caption         =   "Salvar &como..."
      End
      Begin VB.Menu mnuSeparador2 
         Caption         =   "-"
      End
      Begin VB.Menu mnuSair 
         Caption         =   "Sai&r"
      End
   End
   Begin VB.Menu mnuVisualizar 
      Caption         =   "Visualizar"
      Begin VB.Menu mnuContexto 
         Caption         =   "Contexto"
      End
      Begin VB.Menu mnuLixeira 
         Caption         =   "&Lixeira"
         Shortcut        =   ^L
      End
   End
   Begin VB.Menu mnuAjuda 
      Caption         =   "Ajuda"
      Begin VB.Menu mnuSobre 
         Caption         =   "Sobre"
      End
   End
End
Attribute VB_Name = "frmPrincipal"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit



Private bordaFrmSinfonia As definicoes.borda
Private bordaIaSinfonia As definicoes.borda



Private Sub Form_Load()
        
    frmSplash.iniciaContagem
    frmSplash.Show vbModal, Me
        
    definicoes.configuracao.carrega
    
    Me.iaSinfonia.setNome "Sinfonia"
    Me.iaSinfonia.setImagensItens Me.ilIconesLista
    Me.iaSinfonia.setImagensArvore Me.ilIconesArvore
    Me.iaSinfonia.adicionaItem "Grupo", True, "grupo", "grupo_aberto", Array("Principal", "Grupo")
    Me.iaSinfonia.adicionaItem "Estado", True, "estado", "estado", Array("Grupo", "Principal")
    Me.iaSinfonia.adicionaItem "Evento", False, "evento", , Array("Principal", "Grupo", "Estado")
    Me.iaSinfonia.adicionaItem "Dinamica", False, "dinamica", , Array("Principal", "Grupo")
    
    bordaFrmSinfonia = definicoes.getBorda(frmSinfonia, Me)
    bordaIaSinfonia = definicoes.getBorda(iaSinfonia, frmSinfonia)
    
    definicoes.configuracao.posDimSinfonia.aplica Me
    
    fecha
    
    If definicoes.configuracao.quantosArquivos > 0 Then
            
        abre definicoes.configuracao.ultimoArquivo
    
    End If
    
End Sub



Private Sub Form_Resize()
    
On Error Resume Next

    definicoes.aplicaBorda frmSinfonia, bordaFrmSinfonia, Me
    definicoes.aplicaBorda iaSinfonia, bordaIaSinfonia, frmSinfonia

End Sub

Private Sub Form_Terminate()
    salvaTudo
    End
End Sub

Private Sub salvaTudo()
    definicoes.configuracao.posDimSinfonia.atualiza Me
    
    If frmGrupo.Visible Then
        definicoes.configuracao.posDimGrupo.atualiza frmGrupo
    End If
    
    If frmEvento.Visible Then
        definicoes.configuracao.posDimEvento.atualiza frmEvento
    End If
    
    If frmEstado.Visible Then
        definicoes.configuracao.posDimEstado.atualiza frmEstado
    End If

    If frmDinamica.Visible Then
        definicoes.configuracao.posDimDinamica.atualiza frmDinamica
    End If

    If frmLixeira.Visible Then
        definicoes.configuracao.posDimLixeira.atualiza frmLixeira
    End If

    If frmVisualizacao.Visible Then
        definicoes.configuracao.posDimContexto.atualiza frmVisualizacao
    End If

    definicoes.configuracao.salva
End Sub

Private Sub Form_Unload(Cancel As Integer)


    salvaTudo
    
    End
    
End Sub

Private Sub iaSinfonia_abriuNo(no As MSComctlLib.Node)

    If no.Tag = "Grupo" Then
        definicoes.sinfonia.getGrupos.getGrupo(no.key).confPasta.setAberto (True)
        
    ElseIf no.Tag = "Estado" Then
        definicoes.sinfonia.getEstados.getEstado(no.key).confPasta.setAberto (True)
        
    End If
End Sub

Private Sub iaSinfonia_fechouNo(no As MSComctlLib.Node)

    If no.Tag = "Grupo" Then
        definicoes.sinfonia.getGrupos.getGrupo(no.key).confPasta.setAberto (False)
        
    ElseIf no.Tag = "Estado" Then
        definicoes.sinfonia.getEstados.getEstado(no.key).confPasta.setAberto (False)
        
    End If
End Sub

Private Sub iaSinfonia_OLEDragDrop(Data As MSComctlLib.DataObject, Effect As Long, Button As Integer, shift As Integer, X As Single, Y As Single, noSobre As MSComctlLib.Node)
    
    On Error GoTo fim
    
    Dim controlPressionado As Boolean
                    
    controlPressionado = shift And &H2&
    
    
    If Data.GetFormat(vbCFText) Then

        Dim key As String
        Dim no As Node
        
        key = Data.GetData(vbCFText)
        
        Set no = iaSinfonia.nosArvore.Item(key)
        
        If Not no Is Nothing Then
        
            Dim Item As clsItem
            
            Set Item = iaSinfonia.getItens.getItemPeloNome(no.Tag)
        
            If (no.Tag = "Estado") And controlPressionado And Item.ehPai(noSobre.Tag) Then
        
                Dim estado As clsEstado
                Dim novoEstado As clsEstado
                Dim noNovoEstado As Node
                
                Set estado = definicoes.sinfonia.getEstados.getEstado(key)
                Set novoEstado = definicoes.sinfonia.getEstados.add("copiando")
                
                estado.copia novoEstado
                
                Set noNovoEstado = iaSinfonia.nosArvore.add(noSobre.key, tvwChild, novoEstado.getId, novoEstado.getNome, novoEstado.getImagem)
                noNovoEstado.Tag = "Estado"
                noNovoEstado.Expanded = True
                noNovoEstado.ExpandedImage = novoEstado.getImagem
        
        
            ElseIf (Not Item.possuiRestricaoDePai) Or Item.ehPai(noSobre.Tag) Then
                    
                Set no.Parent = noSobre
                                    
            End If
        End If
    End If
    
fim:
End Sub

Private Sub mnuContexto_Click()
    frmVisualizacao.Show
End Sub

Private Sub mnuFechar_Click()
    fecha
End Sub



Private Sub mnuLixeira_Click()
    frmLixeira.Show
End Sub

Private Sub mnuNovo_Click()
    novo
End Sub



Private Sub mnuSair_Click()
    salvaTudo
    End
End Sub



Private Sub mnuSalvar_Click()

    If definicoes.arquivoAtual <> "" Then
        salvar definicoes.arquivoAtual
    Else
        mnuSalvarComo_Click
    End If

End Sub



Private Sub mnuSalvarComo_Click()
    
    cdAbrir.ShowSave
    
    If cdAbrir.FileName <> "" Then
    
        definicoes.arquivoAtual = cdAbrir.FileName
        salvar definicoes.arquivoAtual
        
    End If
    
End Sub



Private Sub mnuAbrir_Click()

    cdAbrir.ShowOpen
    
    If cdAbrir.FileName <> "" Then
    
        abre cdAbrir.FileName
        
    End If

End Sub



Private Sub iaSinfonia_adicionouItem(no As Node)

    If no.Tag = "Estado" Then
        adicionaEstado no
        
    ElseIf no.Tag = "Grupo" Then
        adicionaGrupo no
        
    ElseIf no.Tag = "Evento" Then
        adicionaEvento no
        
    ElseIf no.Tag = "Dinamica" Then
        adicionaDinamica no
    End If
    
End Sub



Private Sub iaSinfonia_editouItem(no As Node, nome As String, key As String, novoValor As String)

    If nome = "Estado" Then
    
        definicoes.estadoAtual.setNome novoValor
        frmEstado.txtNomeEstado.Text = definicoes.estadoAtual.getNome
        
    ElseIf nome = "Grupo" Then
    
        definicoes.grupoAtual.setNome novoValor
        frmGrupo.txtNomeGrupo.Text = definicoes.grupoAtual.getNome
        
    ElseIf nome = "Evento" Then
    
        If definicoes.eventoAtual.getIntermediario Then
            definicoes.eventoAtual.setNome novoValor
            frmEvento.txtNomeEvento.Text = definicoes.eventoAtual.getNome
        Else
            no.Text = definicoes.eventoAtual.getNome
        End If
        
    ElseIf nome = "Dinamica" Then
    
        definicoes.dinamicaAtual.setNome novoValor
        frmDinamica.iaDinamica.nosArvore.Item("Principal").Text = definicoes.dinamicaAtual.getNome
        
    ElseIf nome = "Principal" Then
        definicoes.sinfonia.setNome novoValor
    End If
    
End Sub



Private Sub iaSinfonia_selecionouItem(no As Node, nome As String, key As String, botao As Integer, shift As Integer)

    If nome = "Estado" Then
    
        Dim estado As clsEstado
        
        Set estado = definicoes.sinfonia.getEstados.getEstado(key)
        
        frmEstado.carregaEstado estado, no
        
        definicoes.tipoNoAtual = tnEstado
        
    ElseIf nome = "Grupo" Then
    
        If botao And vbRightButton Then
        
            Dim grupo As clsGrupo
            
            Set grupo = definicoes.sinfonia.getGrupos.getGrupo(key)
            
            frmGrupo.carregaGrupo grupo, no
                        
            definicoes.tipoNoAtual = tnGrupo
        End If
        
    ElseIf nome = "Evento" Then
    
        Dim evento As clsEvento
        
        Set evento = definicoes.sinfonia.getEventos.getEvento(key)
        
        frmEvento.carregaEvento evento, no
        
        definicoes.tipoNoAtual = tnEvento
        
    ElseIf nome = "Dinamica" Then
        
        Dim dinamica As clsDinamica
        
        Set dinamica = definicoes.sinfonia.getDinamicas.getDinamica(key)
        
        frmDinamica.carregaDinamica dinamica, no
        
        definicoes.tipoNoAtual = tnDinamica
        
        If frmVisualizacao.Visible Then
            frmVisualizacao.carregaDinamica dinamica.getId
        End If
        
    ElseIf nome = "Aplicacao" Then
          
        definicoes.tipoNoAtual = tnAplicacao
        
    Else
        definicoes.tipoNoAtual = tnNenhum
    End If
    
End Sub



Public Sub adicionaEstado(no As Node)
                    
    Dim novoEstado As clsEstado
    
    Set novoEstado = definicoes.sinfonia.getEstados.add(inputValor("Nome do Estado", "Novo Estado"), no.key)
                
    no.Text = novoEstado.getNome
    
    no.Selected = True
    
    frmEstado.carregaEstado novoEstado, no
    
End Sub



Public Sub adicionaGrupo(no As Node)

    Dim novoGrupo As clsGrupo
    
    Set novoGrupo = definicoes.sinfonia.getGrupos.add(inputValor("Nome do Grupo", "Novo Grupo"), no.key)
                
    no.Text = novoGrupo.getNome
    
    no.Selected = True
    
    frmGrupo.carregaGrupo novoGrupo, no

End Sub



Public Sub adicionaEvento(no As Node)

    Dim novoEvento As clsEvento
    Dim nome As String
    Dim estadoRef As clsEstado
    
    If no.Parent.Tag = "Estado" Then
        nome = "__nadinha__"
        Set estadoRef = definicoes.sinfonia.getEstados.getEstado(no.Parent.key)
    Else
        nome = inputValor("Nome do Evento", "Novo Evento")
        Set estadoRef = Nothing
    End If
    
    Set novoEvento = definicoes.sinfonia.getEventos.add(nome, no.key)
                
    novoEvento.setIntermediario (no.Parent.Tag <> "Estado")
    novoEvento.setEstadoRef estadoRef
    
    no.Text = novoEvento.getNome

    no.Selected = True
    
    frmEvento.carregaEvento novoEvento, no

End Sub




Public Sub adicionaDinamica(no As Node)

    Dim dinamica As clsDinamica
    
    Set dinamica = definicoes.sinfonia.getDinamicas.add(inputValor("Dinamica", "Nova Dinamica"), no.key)
    no.Text = dinamica.getNome
    
    frmDinamica.carregaDinamica dinamica, no

End Sub



Public Sub removeNoEstado(no As Node, Optional nivel As Integer = 0)
    
    If Not no Is Nothing Then
    
        If no.children > 0 Then
        
          removeNoEstado no.Child, nivel + 1
        
        End If
        
        If nivel > 0 Then
        
            removeNoEstado no.Next, nivel
            
        End If
        
        If no.Tag = definicoes.tipoNoEstados.estado Then
        
            definicoes.sinfonia.getEstados.remove no.key
            
        End If
        
        'tvEstados.Nodes.remove no.Index
        
    End If
    
End Sub



Public Sub fecha()

    definicoes.arquivoAtual = ""

    Set definicoes.sinfonia = Nothing
                    
    habilitaMenus False
    
    frmEvento.Hide
    frmGrupo.Hide
    frmDinamica.Hide
    frmEstado.Hide
    
End Sub



Public Sub novo()

    Dim noPrincipal As Node

    fecha

    definicoes.arquivoAtual = ""

    Set definicoes.sinfonia = New clsSinfonia
    
    definicoes.sinfonia.setNome inputValor("Nome da aplicação", "Nova Aplicação")
    
    iaSinfonia.setNoPrincipal definicoes.sinfonia.getNome, "aplicacao", "aplicacao"
    iaSinfonia.habilita True

    habilitaMenus True

End Sub



Public Sub abre(arquivo As String)

    Dim carregador As New clsCarregEstados
    
    Set definicoes.sinfonia = New clsSinfonia
    
    If carregador.carregaEstados(iaSinfonia.nosArvore, definicoes.sinfonia, arquivo) Then
                
        definicoes.arquivoAtual = arquivo
        iaSinfonia.habilita True
        habilitaMenus True
    
        definicoes.configuracao.abriuArquivo arquivo
    
    Else
    
        fecha
        MsgBox "Não foi possível abrir arquivo: " & arquivo
    
    End If
    

End Sub



Public Sub salvar(arquivo As String)
    
    Dim arquivoXML As New clsSalvEstados

    arquivoXML.salvarEstados iaSinfonia.nosArvore, definicoes.sinfonia, arquivo

End Sub



Public Sub habilitaMenus(habilita As Boolean)
    mnuSalvar.Enabled = habilita
    mnuSalvarComo.Enabled = habilita
    mnuFechar.Enabled = habilita
    
    If habilita Then
        frmLixeira.Show
    Else
        frmLixeira.Hide
    End If
    
End Sub


Public Function atualizaIcones()
    pAtualizaIcones Me.iaSinfonia.nosArvore.Item(1)
End Function


Private Function pAtualizaIcones(no As Node) As Boolean
        
    If Not no Is Nothing Then
    
        Dim grupo As Boolean
        Dim quebrado As Boolean
        Dim imagem As String
        
            
        grupo = False
            
        Select Case no.Tag
        
            Case "Evento"
                imagem = definicoes.sinfonia.getEventos.getEvento(no.key).getImagem
                
            Case "Estado"
                imagem = definicoes.sinfonia.getEstados.getEstado(no.key).getImagem
                grupo = True
        
            Case "Dinamica"
                imagem = definicoes.sinfonia.getDinamicas.getDinamica(no.key).getImagem
                
            Case "Grupo"
                imagem = definicoes.sinfonia.getGrupos.getGrupo(no.key).getImagem
                grupo = True
                
            Case "Principal"
                imagem = definicoes.sinfonia.getImagem
                grupo = True
            
        End Select
        
        
        If grupo Then
            quebrado = pAtualizaIcones(no.Child)
            
            If quebrado Then
                imagem = imagem & "_quebrado"
            End If
        Else
            quebrado = InStr(1, imagem, "quebrado") <> 0
        End If
        
        no.Image = imagem
        
        If quebrado Then
        
            Select Case no.Tag
                Case "Grupo"
                    no.ExpandedImage = "grupo_aberto_quebrado"
                Case "Estado"
                    no.ExpandedImage = imagem
                Case "Principal"
                    no.ExpandedImage = "aplicacao_quebrado"
            End Select
            
        Else
        
            Select Case no.Tag
                Case "Grupo"
                    no.ExpandedImage = "grupo_aberto"
                Case "Estado"
                    no.ExpandedImage = imagem
                Case "Principal"
                    no.ExpandedImage = "aplicacao"
            End Select
        
        End If
        
        
        pAtualizaIcones = pAtualizaIcones(no.Next) Or quebrado
    End If
    
End Function






Private Sub mnuSobre_Click()
    frmSplash.Show vbModal, Me
End Sub
