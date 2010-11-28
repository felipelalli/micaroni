VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Object = "{7BA52D1B-09C1-45D3-9419-C750185C2CBB}#2.0#0"; "Biblia.ocx"
Begin VB.Form frmEvento 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Evento"
   ClientHeight    =   7230
   ClientLeft      =   13935
   ClientTop       =   285
   ClientWidth     =   6555
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7230
   ScaleWidth      =   6555
   ShowInTaskbar   =   0   'False
   Begin VB.Frame frmEvento 
      Caption         =   "Evento"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   6975
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   6255
      Begin VB.CheckBox chkEventoExterno 
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
         Left            =   4920
         TabIndex        =   9
         Top             =   480
         Width           =   1095
      End
      Begin VB.Frame frmModificacao 
         Caption         =   "Modificação"
         BeginProperty Font 
            Name            =   "Verdana"
            Size            =   9.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   5655
         Left            =   240
         TabIndex        =   2
         Top             =   1080
         Width           =   5775
         Begin VB.ComboBox txtAcaoEvento 
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
            ItemData        =   "frmEvento.frx":0000
            Left            =   1080
            List            =   "frmEvento.frx":0013
            TabIndex        =   4
            Text            =   "="
            Top             =   2880
            Width           =   2175
         End
         Begin Biblia.ItensEArvore iaParametroEvento 
            Height          =   2175
            Left            =   120
            TabIndex        =   3
            Top             =   3360
            Width           =   5535
            _ExtentX        =   9763
            _ExtentY        =   3836
         End
         Begin MSComctlLib.ListView lvAtributosEvento 
            Height          =   1695
            Left            =   480
            TabIndex        =   5
            Top             =   840
            Width           =   2655
            _ExtentX        =   4683
            _ExtentY        =   2990
            LabelEdit       =   1
            LabelWrap       =   -1  'True
            HideSelection   =   -1  'True
            OLEDragMode     =   1
            _Version        =   393217
            ForeColor       =   -2147483647
            BackColor       =   -2147483643
            BorderStyle     =   1
            Appearance      =   0
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "Verdana"
               Size            =   8.25
               Charset         =   0
               Weight          =   700
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            OLEDragMode     =   1
            NumItems        =   0
         End
         Begin VB.Label lbAtributosEvento 
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
            Left            =   480
            TabIndex        =   7
            Top             =   480
            Width           =   1575
         End
         Begin VB.Label lbAcaoEvento 
            Caption         =   "Ação"
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
            Left            =   480
            TabIndex        =   6
            Top             =   2880
            Width           =   1575
         End
      End
      Begin VB.TextBox txtNomeEvento 
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
         TabIndex        =   1
         Top             =   480
         Width           =   3015
      End
      Begin VB.Label lbNomeEvento 
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
         TabIndex        =   8
         Top             =   480
         Width           =   495
      End
   End
End
Attribute VB_Name = "frmEvento"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim carregando As Boolean

Public Sub carregaEvento(evento As clsEvento, no As Node)

      If Not evento Is Nothing Then
            
        If Not Me.Visible Then
            definicoes.configuracao.posDimEvento.aplica Me
        End If
        
        Me.Show
            
        carregando = True
            
        Set definicoes.noEventoAtual = no
            
        limpaEvento
            
        If evento.getExterno Then
            chkEventoExterno.Value = 1
        Else
            chkEventoExterno.Value = 0
        End If
            
        If evento.getIntermediario Then
        
            txtNomeEvento.Text = evento.getNome
            
        Else
        
            Dim i As Integer
            Dim indPrincipal As Integer
            Dim estado As clsEstado
            Dim atributos As clsAtributos
            Dim atributoSelecionado As clsAtributo
            
            Set estado = definicoes.sinfonia.getEstados.getEstado(definicoes.noEventoAtual.Parent.key)
            
            txtNomeEvento.Text = estado.getNome
            
            Set atributos = estado.getAtributos
            
            For i = 1 To atributos.quantos
            
                Dim novoItem As ListItem
                Dim atributo As clsAtributo
            
                Set atributo = atributos.getAtributo(i)
            
                Set novoItem = lvAtributosEvento.ListItems.add(, atributo.getId, atributo.getNome, "atributo", "atributo")
                
                If evento.getIdAtributo <> "__nadinha__" Then
                    
                    novoItem.Checked = (evento.getIdAtributo = atributo.getId)
                    novoItem.Bold = novoItem.Checked
                    
                    If evento.getIdAtributo = atributo.getId Then
                        Set atributoSelecionado = atributo
                    End If
                    
                End If
            Next
            
            txtAcaoEvento.Text = evento.getAcao
            
            carregaParametroEvento evento
            
        End If
            
        habilitaEvento True
            
        txtNomeEvento.Enabled = evento.getIntermediario
        frmModificacao.Visible = Not evento.getIntermediario
        
        Set definicoes.eventoAtual = evento
    
        no.Text = definicoes.eventoAtual.getNome
    
        carregando = False
    
    Else
    
        limpaEvento
    
    End If
End Sub


Public Function carregaParametroEvento(evento As clsEvento)

    If Not evento Is Nothing Then
    
        Dim noPrincipal As Node
        
        Set noPrincipal = iaParametroEvento.nosArvore.add(, , "Principal", "Principal", "evento")
        noPrincipal.Expanded = True
        noPrincipal.Tag = "Principal"
        noPrincipal.Sorted = True
    
        noPrincipal.Text = definicoes.montaEstadoDependente(frmPrincipal.iaSinfonia.nosArvore.Item(evento.getId).Parent.key, evento.getEstadoDep, noPrincipal, iaParametroEvento)
    
    End If

End Function


Public Sub limpaEvento()
    
    txtNomeEvento.Text = ""
    lvAtributosEvento.ListItems.Clear
    txtAcaoEvento.Text = "="
    iaParametroEvento.limpa
    chkEventoExterno.Value = 0
    
    habilitaEvento False
End Sub



Public Sub habilitaEvento(habilita As Boolean)

    txtNomeEvento.Enabled = habilita
    lvAtributosEvento.Enabled = habilita
    txtAcaoEvento.Enabled = habilita
    iaParametroEvento.habilita habilita
    chkEventoExterno.Enabled = habilita
    
End Sub

Private Sub Form_Load()

    Me.lvAtributosEvento.Icons = frmPrincipal.ilIconesLista
    Me.lvAtributosEvento.SmallIcons = frmPrincipal.ilIconesArvore
    Me.lvAtributosEvento.Checkboxes = True
    Me.lvAtributosEvento.View = lvwSmallIcon
    
    Me.iaParametroEvento.setNome "Parametro_Evento"
    Me.iaParametroEvento.setImagensItens frmPrincipal.ilIconesLista
    Me.iaParametroEvento.setImagensArvore frmPrincipal.ilIconesArvore
    Me.iaParametroEvento.setOrientacao vertical
    Me.iaParametroEvento.adicionaItem "EConstante", False, "estado", , Array("Estado_Dependente")
    Me.iaParametroEvento.setPossuiCheckBox True
    Me.iaParametroEvento.adicionaItemQuePodeSerCheckado "Estado"
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    definicoes.configuracao.posDimEvento.atualiza Me
End Sub

Private Sub iaParametroEvento_editouItem(no As MSComctlLib.Node, nome As String, key As String, novoValor As String)
    
    If no.Tag = "Operador" Then
    
        Dim keyPai As String
        
        If no.Parent.Tag = "Estado Dependente" Then
        
            keyPai = no.Previous.key
            
        Else
        
            keyPai = no.Parent.key
        
        End If
    
        definicoes.eventoAtual.getEstadoDep.mudaOperador keyPai, novoValor
            
    End If
End Sub

Private Sub txtAcaoEvento_Change()
    If Not carregando Then
        definicoes.eventoAtual.setAcao txtAcaoEvento.Text
        definicoes.noEventoAtual.Text = definicoes.eventoAtual.getNome
    End If
End Sub

Private Sub txtAcaoEvento_Click()
    If Not carregando Then
        definicoes.eventoAtual.setAcao txtAcaoEvento.Text
        definicoes.noEventoAtual.Text = definicoes.eventoAtual.getNome
    End If
End Sub


Private Sub chkEventoExterno_Click()
    If Not carregando Then
        definicoes.eventoAtual.setExterno chkEventoExterno.Value
        
        If definicoes.eventoAtual.getExterno Then
            definicoes.noEventoAtual.Image = "evento_externo"
        Else
            definicoes.noEventoAtual.Image = "evento"
        End If
        
    End If
End Sub


Private Sub txtNomeEvento_Change()
    
    If Not carregando Then
    
        definicoes.eventoAtual.setNome txtNomeEvento.Text
        definicoes.noEventoAtual.Text = definicoes.eventoAtual.getNome
    
    End If
    
End Sub


Private Sub lvAtributosEvento_ItemCheck(ByVal Item As MSComctlLib.ListItem)
    
    Dim i As Integer
    Dim estado As clsEstado
    Dim atributos As clsAtributos
    Dim atributo As clsAtributo
    
    Set estado = definicoes.sinfonia.getEstados.getEstado(definicoes.noEventoAtual.Parent.key)
    Set atributos = estado.getAtributos
    Set atributo = atributos.getAtributoPeloId(Item.key)

    If Item.Checked Then
        definicoes.eventoAtual.setIdAtributo atributo.getId
    Else
        definicoes.eventoAtual.setIdAtributo "__nadinha__"
    End If

    For i = 1 To lvAtributosEvento.ListItems.Count

        If i <> Item.Index Then

            lvAtributosEvento.ListItems.Item(i).Checked = False

        End If
    Next

    definicoes.noEventoAtual.Text = definicoes.eventoAtual.getNome

    Item.Selected = True
    
End Sub


Private Sub iaParametroEvento_OLEDragDrop(Data As MSComctlLib.DataObject, Effect As Long, Button As Integer, shift As Integer, X As Single, Y As Single, noSobre As MSComctlLib.Node)

  Dim controlPressionado As Boolean
                    
    controlPressionado = shift And &H2&
        
    If Data.GetFormat(vbCFText) Then
    
        If Not noSobre Is Nothing Then
                               
            If (noSobre.Tag = "Estado") Or (noSobre.Tag = "Estado Dependente") Then
        
                Dim estado As clsEstadoComposto
                                                                                                
                'Muda o tipo do estado
                If (noSobre.Tag = "Estado") And Not controlPressionado Then
                                                                            
                    Set estado = definicoes.eventoAtual.getEstadoDep.getEstadoComposto(noSobre.key)
                      
                ElseIf ((noSobre.Tag = "Estado") And controlPressionado) Or _
                       (noSobre.Tag = "Estado Dependente") Then
                                    
                    Dim estadoDependente As clsEstadoDep
                    
                    If noSobre.Tag = "Estado Dependente" Then
                        Set estadoDependente = definicoes.eventoAtual.getEstadoDep
                    Else
                        Set estadoDependente = definicoes.eventoAtual.getEstadoDep.getEstadoComposto(noSobre.key).getPai
                    End If
                    
                    Set estado = estadoDependente.add
                      
                End If
                
                
                If (Data.GetData(vbCFText) = "EConstante") Then
                                                                                            
                    estado.setConstante True
                    estado.setValor inputValor("Valor do Estado", "")
                                                                        
                ElseIf ((definicoes.tipoNoAtual = tnEstado) And (InStr(1, Data.GetData(vbCFText), "Sinfonia") <> 0)) Or _
                       (InStr(1, Data.GetData(vbCFText), "Atributos") <> 0) Or _
                       (InStr(1, Data.GetData(vbCFText), "Parametros") <> 0) Then
                                          
                    Dim estadoRef As clsEstado
                    Dim atributo As clsAtributo
                    Dim parametro As clsParametro
                    
                    Set estadoRef = definicoes.estadoAtual
                    
                    estado.setConstante False
                    estado.setIdEstado estadoRef.getId
                    
                    
                    If InStr(1, Data.GetData(vbCFText), "Atributos") <> 0 Then
                    
                        Set atributo = definicoes.atributoAtual
                        Set parametro = Nothing
                        
                    ElseIf InStr(1, Data.GetData(vbCFText), "Parametros") <> 0 Then
                    
                        Set atributo = definicoes.atributoAtual
                        Set parametro = atributo.getParametros.getParametroPeloId(Data.GetData(vbCFText))
                        
                    Else
                    
                        Set atributo = estadoRef.getAtributos.getAtributoPrincipal
                        Set parametro = Nothing
                        
                    End If
                    
                    
                    If Not atributo Is Nothing Then
                    
                        estado.setIdAtributo atributo.getId
                        
                        If Not parametro Is Nothing Then
                        
                            estado.setIdParametro parametro.getId
                        Else
                            estado.setIdParametro "__nadinha__"
                        End If
                        
                    Else
                        estado.setIdAtributo "__nadinha__"
                    End If
                End If
                carregaEvento definicoes.eventoAtual, definicoes.noEventoAtual
            End If
        End If
    End If
End Sub
