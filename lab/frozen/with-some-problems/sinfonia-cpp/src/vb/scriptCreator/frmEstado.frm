VERSION 5.00
Object = "{7BA52D1B-09C1-45D3-9419-C750185C2CBB}#2.0#0"; "Biblia.ocx"
Begin VB.Form frmEstado 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Estado"
   ClientHeight    =   7395
   ClientLeft      =   7395
   ClientTop       =   675
   ClientWidth     =   6810
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7395
   ScaleWidth      =   6810
   ShowInTaskbar   =   0   'False
   Begin VB.Frame frmEstado 
      Caption         =   "Estado"
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
      Width           =   6495
      Begin VB.CheckBox chkSomenteEsses 
         Caption         =   "Somente Esses"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   9
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   4440
         TabIndex        =   12
         Top             =   6600
         Width           =   1695
      End
      Begin VB.TextBox txtNomeEstado 
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
         TabIndex        =   5
         Top             =   480
         Width           =   3015
      End
      Begin VB.CheckBox chkEstadoExterno 
         Appearance      =   0  'Flat
         BackColor       =   &H80000000&
         Caption         =   "Externo"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   9
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H80000008&
         Height          =   375
         Left            =   3000
         TabIndex        =   4
         Top             =   1440
         Width           =   1095
      End
      Begin VB.TextBox txtDescricaoEstado 
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
         TabIndex        =   3
         Top             =   2040
         Width           =   6015
      End
      Begin VB.ComboBox txtClasseEstado 
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
         Height          =   405
         ItemData        =   "frmEstado.frx":0000
         Left            =   960
         List            =   "frmEstado.frx":0010
         TabIndex        =   2
         Text            =   "MultiFuncional"
         Top             =   960
         Width           =   3015
      End
      Begin Biblia.ItensEArvore iaAtributos 
         Height          =   3495
         Left            =   120
         TabIndex        =   1
         Top             =   3480
         Width           =   3015
         _ExtentX        =   5318
         _ExtentY        =   6165
      End
      Begin Biblia.ItensEArvore iaParametros 
         Height          =   3135
         Left            =   3240
         TabIndex        =   6
         Top             =   3480
         Width           =   3015
         _ExtentX        =   5318
         _ExtentY        =   5530
      End
      Begin VB.Label lbValoresPossiveis 
         Caption         =   "Valores Possíveis"
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
         Left            =   3360
         TabIndex        =   11
         Top             =   3240
         Width           =   1575
      End
      Begin VB.Label lbNomeEstado 
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
         TabIndex        =   10
         Top             =   480
         Width           =   495
      End
      Begin VB.Label lbClasseEstado 
         Caption         =   "Classe"
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
         TabIndex        =   9
         Top             =   960
         Width           =   615
      End
      Begin VB.Label lbDescricaoEstado 
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
         TabIndex        =   8
         Top             =   1680
         Width           =   1095
      End
      Begin VB.Label lbAtributos 
         Caption         =   "Atributos"
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
         TabIndex        =   7
         Top             =   3240
         Width           =   1575
      End
   End
End
Attribute VB_Name = "frmEstado"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub chkSomenteEsses_Click()
    If Not definicoes.atributoAtual Is Nothing Then
        definicoes.atributoAtual.setSomenteEsses chkSomenteEsses.Value
    End If
End Sub

Private Sub Form_Load()

    Me.iaAtributos.setNome "Atributos"
    Me.iaAtributos.setImagensItens frmPrincipal.ilIconesLista
    Me.iaAtributos.setImagensArvore frmPrincipal.ilIconesArvore
    Me.iaAtributos.adicionaItem "Atributo", False, "atributo", , , radiobutton
    Me.iaAtributos.setOrdemAlfabetica False
                
    Me.iaParametros.setNome "Parametros"
    Me.iaParametros.setImagensItens frmPrincipal.ilIconesLista
    Me.iaParametros.setImagensArvore frmPrincipal.ilIconesArvore
    Me.iaParametros.adicionaItem "Parametro", True, "parametro", "parametro", Array("Principal"), radiobutton
    Me.iaParametros.adicionaItem "Apelido", False, "apelido", , Array("Parametro")
    Me.iaParametros.setOrdemAlfabetica False
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    definicoes.configuracao.posDimEstado.atualiza Me
End Sub

Private Sub iaAtributos_adicionouItem(no As MSComctlLib.Node)
    If no.Tag = "Atributo" Then
        adicionaAtributo no
    End If
End Sub

Private Sub iaAtributos_duploClique(no As MSComctlLib.Node, nome As String, key As String)
    If nome = "Atributo" Then
        definicoes.atributoAtual.getParametros.proximoParametro
        definicoes.noAtributoAtual.Text = definicoes.atributoAtual.emString
        carregaAtributo definicoes.estadoAtual.getAtributos.getAtributoPeloId(definicoes.atributoAtual.getId)
    End If
End Sub

Private Sub iaAtributos_editouItem(no As Node, nome As String, key As String, novoValor As String)
    
    If nome = "Atributo" Then
    
        definicoes.atributoAtual.setNome novoValor
        carregaAtributo definicoes.estadoAtual.getAtributos.getAtributoPeloId(definicoes.atributoAtual.getId)
    End If
    
End Sub

Private Sub iaAtributos_selecionouItem(no As MSComctlLib.Node, nome As String, key As String, botao As Integer, shift As Integer)
    
    If nome = "Atributo" Then
    
        Dim atributo As clsAtributo
        Set atributo = definicoes.estadoAtual.getAtributos().getAtributoPeloId(key)
        Set definicoes.noAtributoAtual = no
        carregaAtributo atributo
        
    Else
        MsgBox "limpaAtributo"
    End If
    
End Sub

Public Sub limpaAtributo()

    Set definicoes.atributoAtual = Nothing
    Set definicoes.noAtributoAtual = Nothing
    
    iaParametros.limpa
    
End Sub

Private Sub iaAtributos_marcouItem(no As MSComctlLib.Node, nome As String, key As String)
    
    If nome = "Atributo" Then
    
        definicoes.estadoAtual.getAtributos().getAtributoPeloId(key).setPrincipal (no.Checked)
    
    End If
    
End Sub

Private Sub iaAtributos_desmarcouItem(no As MSComctlLib.Node, nome As String, key As String)
    
    If nome = "Atributo" Then
    
        definicoes.estadoAtual.getAtributos().getAtributoPeloId(key).setPrincipal (no.Checked)
    
    End If
    
End Sub


Private Sub iaParametros_adicionouItem(no As MSComctlLib.Node)

    If no.Tag = "Parametro" Then
        adicionaParametro no
        
    ElseIf no.Tag = "Apelido" Then
        adicionaApelido no
    End If
End Sub

Private Sub iaParametros_editouItem(no As Node, nome As String, key As String, novoValor As String)

    If nome = "Parametro" Then
        definicoes.atributoAtual.getParametros.getParametroPeloId(key).setNome novoValor
        iaAtributos.nosArvore.Item(definicoes.atributoAtual.getId).Text = definicoes.atributoAtual.emString
        
    ElseIf nome = "Apelido" Then
        definicoes.atributoAtual.getParametros.getParametroPeloId(no.Parent.key).getApelidos.getApelidoPeloId(key).setNome novoValor
        
    ElseIf nome = "Principal" Then
    
        definicoes.atributoAtual.setNome novoValor
        definicoes.noAtributoAtual.Text = definicoes.atributoAtual.getNome
    End If
End Sub

Private Sub iaParametros_selecionouItem(no As MSComctlLib.Node, nome As String, key As String, botao As Integer, shift As Integer)
    'Não faz nada
End Sub

Private Sub iaParametros_marcouItem(no As MSComctlLib.Node, nome As String, key As String)
    
    If nome = "Parametro" Then
    
        definicoes.atributoAtual.getParametros().getParametroPeloId(key).setValorInicial (no.Checked)
        iaAtributos.nosArvore.Item(definicoes.atributoAtual.getId).Text = definicoes.atributoAtual.emString
    
    End If
    
End Sub

Private Sub iaParametros_desmarcouItem(no As MSComctlLib.Node, nome As String, key As String)
    
    If nome = "Parametro" Then
    
        definicoes.atributoAtual.getParametros().getParametroPeloId(key).setValorInicial (no.Checked)
        iaAtributos.nosArvore.Item(definicoes.atributoAtual.getId).Text = definicoes.atributoAtual.emString
    End If
    
End Sub


Public Sub carregaEstado(estado As clsEstado, no As Node)
        
    If Not estado Is Nothing Then
                
        Dim i As Integer
        Dim indPrincipal As Integer
        Dim atributos As clsAtributos
            
        If Not Me.Visible Then
            definicoes.configuracao.posDimEstado.aplica Me
        End If
        
        Me.Show
            
        Set definicoes.noEstadoAtual = no
            
        Set definicoes.atributoAtual = Nothing
            
        limpaEstado
            
        txtNomeEstado.Text = estado.getNome
        txtClasseEstado.Text = estado.getClasse
        txtDescricaoEstado.Text = estado.getDescricao
        
        If estado.getExterno Then
            chkEstadoExterno.Value = 1
        Else
            chkEstadoExterno.Value = 0
        End If
    
        Set atributos = estado.getAtributos
        
        indPrincipal = 1
        
        For i = 1 To atributos.quantos
                        
            Dim atributo As clsAtributo
            Dim noAtributo As Node
            
            Set atributo = atributos.getAtributo(i)
            
            Set noAtributo = iaAtributos.nosArvore.add(, , atributo.getId, atributo.emString, "atributo")
            noAtributo.Tag = "Atributo"
            noAtributo.Checked = atributo.getPrincipal
            noAtributo.Bold = atributo.getPrincipal
            
            If atributo.getPrincipal Then
                indPrincipal = i
            End If
            
        Next
        
        carregaAtributo atributos.getAtributo(indPrincipal)
        
        habilitaEstado True
    
        Set definicoes.estadoAtual = estado
    
    Else
    
        limpaEstado
    
    End If
End Sub

Public Sub carregaAtributo(atributo As clsAtributo)

    If Not atributo Is Nothing Then

        Dim i As Integer
        Dim parametros As clsParametros
        Dim noPrincipal As Node
            
        Set definicoes.atributoAtual = Nothing
            
        
        If atributo.getSomenteEsses Then
            Me.chkSomenteEsses.Value = 1
        Else
            Me.chkSomenteEsses.Value = 0
        End If
        
        Me.iaParametros.habilita True
    
        Set parametros = atributo.getParametros
            
        iaParametros.limpa
                
        iaParametros.setNoPrincipal atributo.getNome, "atributo", "atributo", False
        Set noPrincipal = iaParametros.nosArvore.Item(1)
        noPrincipal.Bold = True
            
        For i = 1 To parametros.quantos
            
            Dim a As Integer
            Dim parametro As clsParametro
            Dim apelidos As clsApelidos
            Dim noParametro As Node
            
            Set parametro = parametros.getParametro(i)
            
            Set noParametro = iaParametros.nosArvore.add(noPrincipal.key, tvwChild, parametro.getId, parametro.getNome, "parametro")
            noParametro.Expanded = True
            noParametro.Tag = "Parametro"
            noParametro.Sorted = False
            
            Set apelidos = parametro.getApelidos
            
            For a = 1 To apelidos.quantos
                
                Dim apelido As clsApelido
                Dim noApelido As Node
                
                Set apelido = apelidos.getApelido(a)
                
                Set noApelido = iaParametros.nosArvore.add(parametro.getId, tvwChild, apelido.getId, apelido.getNome, "apelido")
                noApelido.Tag = "Apelido"
                noApelido.Sorted = False
                
            Next
            
            noParametro.Checked = parametro.getValorInicial
            noParametro.Bold = parametro.getValorInicial
        Next
    
        Set definicoes.atributoAtual = atributo
    
    End If
    
End Sub

Public Sub limpaEstado()

    Set definicoes.estadoAtual = Nothing

    txtNomeEstado.Text = ""
    txtClasseEstado.Text = ""
    txtDescricaoEstado.Text = ""
    chkEstadoExterno.Value = False
    iaAtributos.limpa
    iaParametros.limpa
    chkSomenteEsses.Value = False
    habilitaEstado False
End Sub

Public Sub habilitaEstado(habilita As Boolean)
    
    txtNomeEstado.Enabled = habilita
    txtClasseEstado.Enabled = habilita
    txtDescricaoEstado.Enabled = habilita
    chkEstadoExterno.Enabled = habilita
    chkSomenteEsses.Enabled = habilita
    iaAtributos.habilita habilita
    iaParametros.habilita habilita
    
End Sub


Private Sub txtClasseEstado_Change()
    If Not definicoes.estadoAtual Is Nothing Then
    
        Dim diferente As Boolean
        
        diferente = definicoes.estadoAtual.getClasse <> txtClasseEstado.Text
        
        definicoes.estadoAtual.setClasse txtClasseEstado.Text
        
        If diferente Then
            If definicoes.estadoAtual.getClasse = "Timer" Then
            
                EstadoWizard.criaTimer definicoes.estadoAtual
                Me.carregaEstado definicoes.sinfonia.getEstados.getEstado(definicoes.estadoAtual.getId), definicoes.noEstadoAtual
                
            ElseIf definicoes.estadoAtual.getClasse = "Animação" Then
            
                EstadoWizard.criaAnimacao definicoes.estadoAtual
                Me.carregaEstado definicoes.sinfonia.getEstados.getEstado(definicoes.estadoAtual.getId), definicoes.noEstadoAtual
                
            ElseIf definicoes.estadoAtual.getClasse = "Som" Then
            
                EstadoWizard.criaSom definicoes.estadoAtual
                Me.carregaEstado definicoes.sinfonia.getEstados.getEstado(definicoes.estadoAtual.getId), definicoes.noEstadoAtual
                
            End If
        End If
    End If
End Sub

Private Sub chkEstadoExterno_Click()
    If Not definicoes.estadoAtual Is Nothing Then
        definicoes.estadoAtual.setExterno chkEstadoExterno.Value
        
        If definicoes.estadoAtual.getExterno Then
            definicoes.noEstadoAtual.Image = "estado_externo"
            definicoes.noEstadoAtual.ExpandedImage = "estado_externo"
        Else
            definicoes.noEstadoAtual.Image = "estado"
            definicoes.noEstadoAtual.ExpandedImage = "estado"
        End If
    End If
End Sub

Private Sub txtClasseEstado_Click()
    txtClasseEstado_Change
End Sub

Private Sub txtDescricaoEstado_Change()
    If Not definicoes.estadoAtual Is Nothing Then
        definicoes.estadoAtual.setDescricao txtDescricaoEstado.Text
    End If
End Sub

Private Sub txtNomeEstado_Change()

    If Not definicoes.estadoAtual Is Nothing Then
        
        definicoes.estadoAtual.setNome txtNomeEstado.Text
        definicoes.noEstadoAtual.Text = definicoes.estadoAtual.getNome
    End If
    
End Sub


Public Sub adicionaParametro(no As Node)
    
    If Not definicoes.atributoAtual Is Nothing Then
    
        Dim parametro As clsParametro
        
        Set parametro = definicoes.atributoAtual.getParametros().add(inputValor("Possibilidade", "Nova Possibilidade"), no.key)
                
        no.Text = parametro.getNome
        
    End If
    
End Sub



Public Sub adicionaAtributo(no As Node)
    
    Dim atributo As clsAtributo
    Dim novoNo As Node
    
    Set atributo = definicoes.estadoAtual.getAtributos().add(inputValor("Atributo", "Novo Atributo"), no.key)
    no.Text = atributo.getNome

    Set definicoes.noAtributoAtual = no
    
    carregaAtributo atributo
    
End Sub

Public Sub adicionaApelido(no As Node)
    
    If Not definicoes.atributoAtual Is Nothing Then
                                  
        Dim parametros As clsParametros
        Dim parametro As clsParametro
        Dim apelidos As clsApelidos
        Dim apelido As clsApelido
                                  
        Set parametros = definicoes.atributoAtual.getParametros()
        Set parametro = parametros.getParametroPeloId(no.Parent.key)
        Set apelidos = parametro.getApelidos
        Set apelido = apelidos.add(inputValor("Apelido", "Novo Apelido"), no.key)
        
        no.Text = apelido.getNome
            
    End If
End Sub


