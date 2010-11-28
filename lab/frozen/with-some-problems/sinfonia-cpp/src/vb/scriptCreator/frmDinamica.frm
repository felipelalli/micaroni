VERSION 5.00
Object = "{7BA52D1B-09C1-45D3-9419-C750185C2CBB}#2.0#0"; "Biblia.ocx"
Begin VB.Form frmDinamica 
   BorderStyle     =   5  'Sizable ToolWindow
   Caption         =   "Dinamica"
   ClientHeight    =   5925
   ClientLeft      =   240
   ClientTop       =   8910
   ClientWidth     =   11580
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5925
   ScaleWidth      =   11580
   ShowInTaskbar   =   0   'False
   Begin VB.Frame frmDinamica 
      Caption         =   "Dinâmica"
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
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   11295
      Begin Biblia.ItensEArvore iaDinamica 
         Height          =   5295
         Left            =   120
         TabIndex        =   1
         Top             =   240
         Width           =   11055
         _ExtentX        =   19500
         _ExtentY        =   9340
      End
   End
End
Attribute VB_Name = "frmDinamica"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private bordaFrmDinamica As definicoes.borda
Private bordaIaDinamica As definicoes.borda

Public Sub carregaDinamica(dinamica As clsDinamica, no As Node)

    If Not dinamica Is Nothing Then
    
        Dim i As Integer
        Dim eventoAss As clsEventoAss
        Dim noPrincipal As Node
        Dim noEventosDisparadores As Node
        Dim noCondicao As Node
        Dim noEventosGerados As Node
        Dim noEventosGeradosSenao As Node
        Dim nome As String
        Dim pai As Node
        Dim evento As clsEvento
        Dim imagem As String
                
        If Me.Visible Then
        
            definicoes.configuracao.posDimDinamica.atualiza Me
        
        End If
        
        Me.Visible = False
        definicoes.configuracao.posDimDinamica.aplica Me
        definicoes.aplicaBorda Me.frmDinamica, bordaFrmDinamica, Me
        definicoes.aplicaBorda iaDinamica, bordaIaDinamica, Me.frmDinamica
        Me.Visible = True
        
        Me.Show
        
        Set definicoes.noDinamicaAtual = no
        definicoes.noDinamicaAtual.Selected = True
        
        iaDinamica.limpa
                
        Set noPrincipal = iaDinamica.nosArvore.add(, , "Principal", dinamica.getNome, dinamica.getImagem)
        
        noPrincipal.Expanded = True
        noPrincipal.Bold = True
        noPrincipal.Tag = "Principal"
        noPrincipal.Checked = Not dinamica.getHabilitada
        noPrincipal.Sorted = False
        
        
        '***************************************************
        'EVENTOS DISPARADORES
        
            Set noEventosDisparadores = iaDinamica.nosArvore.add(noPrincipal.key, tvwChild, "EventosDisparadores", "Eventos Disparadores", dinamica.getEventosDisparadores.getImagem)
            noEventosDisparadores.Expanded = True
            noEventosDisparadores.Tag = "EventosDisparadores"
            noEventosDisparadores.Sorted = True
            
            If dinamica.getEventosDisparadores.quantosEventos = 0 Then
            
                iaDinamica.nosArvore.add noEventosDisparadores.key, tvwChild, "Qualquer_Um_Deles", _
                                 "QUALQUER UM DELES", _
                                 "evento_qualquer_um_deles"
            
            Else
                For i = 1 To dinamica.getEventosDisparadores.quantosEventos
                    
                    Set eventoAss = dinamica.getEventosDisparadores.getEvento(i)
                
                    iaDinamica.nosArvore.add(noEventosDisparadores.key, tvwChild, eventoAss.getId, _
                                 eventoAss.emString(dinamica.getId), _
                                 eventoAss.getImagem).Tag = "Evento"
                Next
            End If
        '***************************************************
        
        
        '***************************************************
        'CONDIÇÕES
                        
            montaCondicao dinamica, dinamica.getCondicao, noPrincipal
            
        '***************************************************
    
    
        '***************************************************
        'EVENTOS GERADOS
    
            Set noEventosGerados = iaDinamica.nosArvore.add(noPrincipal.key, tvwChild, "EventosGerados", "Eventos Gerados", dinamica.getEventosGerados.getImagem)
            noEventosGerados.Expanded = True
            noEventosGerados.Tag = "EventosGerados"
            noEventosGerados.Sorted = True
            
            For i = 1 To dinamica.getEventosGerados.quantosEventos
            
                Set eventoAss = dinamica.getEventosGerados.getEvento(i)
                                      
                iaDinamica.nosArvore.add(noEventosGerados.key, tvwChild, eventoAss.getId, _
                             eventoAss.emString(dinamica.getId), _
                             eventoAss.getImagem).Tag = "Evento"
                
            Next
        '***************************************************
        
        
        '***************************************************
        'EVENTOS GERADOS SENÃO
    
            Set noEventosGeradosSenao = iaDinamica.nosArvore.add(noPrincipal.key, tvwChild, "EventosGeradosSenao", "Eventos Gerados Senão", dinamica.getEventosGeradosSenao.getImagem)
            noEventosGeradosSenao.Expanded = True
            noEventosGeradosSenao.Tag = "EventosGeradosSenao"
            noEventosGeradosSenao.Sorted = True
            
            For i = 1 To dinamica.getEventosGeradosSenao.quantosEventos
            
                Set eventoAss = dinamica.getEventosGeradosSenao.getEvento(i)
                
                iaDinamica.nosArvore.add(noEventosGeradosSenao.key, tvwChild, eventoAss.getId, _
                             eventoAss.emString(dinamica.getId), _
                             eventoAss.getImagem).Tag = "Evento"
                
            Next
        '***************************************************
        
        
        Set definicoes.dinamicaAtual = dinamica
    
    End If

End Sub

Public Sub montaCondicao(dinamica As clsDinamica, condicao As clsCondicao, noPai As Node)

    Dim nomeCondicao As String
    Dim noCondicao As Node
    Dim noOperador As Node
    
    Set noCondicao = iaDinamica.nosArvore.add(noPai.key, tvwChild, condicao.getId, "", condicao.getImagem)
    noCondicao.ExpandedImage = condicao.getImagem
    noCondicao.Tag = "Condição"
    noCondicao.Sorted = False
    
    noCondicao.Checked = condicao.getModificador

    If condicao.getModificador Then
        nomeCondicao = "Not "
    Else
        nomeCondicao = ""
    End If

    Select Case condicao.getTipoCondicao
            
        Case tcComparacao
        
            noCondicao.Expanded = condicao.confPasta.getAberto
                        
            nomeCondicao = nomeCondicao + montaEstadoDependente(dinamica.getId, condicao.getEstado1, noCondicao, iaDinamica)
            
            Set noOperador = iaDinamica.nosArvore.add(noCondicao, tvwChild, condicao.getId & "_Operador", condicao.getOperador, "operador")
            noOperador.Tag = "Operador"
            noOperador.Sorted = True
            
            nomeCondicao = nomeCondicao + " " + condicao.getOperador + " "
            
            nomeCondicao = nomeCondicao + montaEstadoDependente(dinamica.getId, condicao.getEstado2, noCondicao, iaDinamica)
        
            If nomeCondicao = " = " Then
            
                nomeCondicao = ""
                
            End If
        
        Case tcComposta
        
            Dim i As Integer
        
            noCondicao.Expanded = condicao.confPasta.getAberto
            
            Set noOperador = iaDinamica.nosArvore.add(noCondicao, tvwChild, condicao.getId & "_Operador", condicao.getOperadorBooleano, "operador")
            noOperador.Tag = "Operador"
            noOperador.Sorted = True
            
            For i = 1 To condicao.quantasCondicoes
            
                montaCondicao dinamica, condicao.getCondicaoPeloIndice(i), noCondicao
            Next
            
    End Select

    noCondicao.Text = nomeCondicao

End Sub


Private Sub Form_Load()

    Me.iaDinamica.setNome "Dinamica"
    Me.iaDinamica.setImagensItens frmPrincipal.ilIconesLista
    Me.iaDinamica.setImagensArvore frmPrincipal.ilIconesArvore
    Me.iaDinamica.setOrientacao vertical
    Me.iaDinamica.adicionaItem "Comparação", True, "condicao_comparadora", "condicao_comparadora", Array("Condição Composta")
    Me.iaDinamica.adicionaItem "Composta", True, "condicao_composta", "condicao_composta", Array("Condição Composta")
    Me.iaDinamica.adicionaItem "EConstante", False, "estado", , Array("Estado_Dependente")
    Me.iaDinamica.setPossuiCheckBox True
    Me.iaDinamica.adicionaItemQuePodeSerCheckado "Estado"
    Me.iaDinamica.adicionaItemQuePodeSerCheckado "Condição"
    Me.iaDinamica.adicionaItemQuePodeSerCheckado "Principal"
    
    bordaFrmDinamica = definicoes.getBorda(Me.frmDinamica, Me)
    bordaIaDinamica = definicoes.getBorda(iaDinamica, Me.frmDinamica)
    
End Sub


Private Sub Form_Resize()
    If Me.Visible Then
        definicoes.aplicaBorda Me.frmDinamica, bordaFrmDinamica, Me
        definicoes.aplicaBorda iaDinamica, bordaIaDinamica, Me.frmDinamica
    End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
    If Not definicoes.dinamicaAtual Is Nothing Then
        definicoes.configuracao.posDimDinamica.atualiza Me
    End If
End Sub

Private Sub iaDinamica_abriuNo(no As MSComctlLib.Node)

    If no.Tag = "Condição" Then
        definicoes.dinamicaAtual.getCondicao.getCondicao(no.key).confPasta.setAberto True
    
    ElseIf no.Tag = "Estado Dependente" Then
        definicoes.dinamicaAtual.getCondicao.procuraEstadoDependente(no.key).confPasta.setAberto True
    
    End If
End Sub

Private Sub iaDinamica_desmarcouItem(no As MSComctlLib.Node, nome As String, key As String)
    
    If nome = "Estado" Then
    
        definicoes.dinamicaAtual.getCondicao.getEstadoComposto(key).setValorAtual (no.Checked)
        carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
        
    ElseIf nome = "Condição" Then
    
        definicoes.dinamicaAtual.getCondicao.getCondicao(key).setModificador (no.Checked)
        carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
        
    ElseIf nome = "Principal" Then
    
        definicoes.dinamicaAtual.setHabilitada Not no.Checked
        carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
    End If
End Sub

Private Sub iaDinamica_duploClique(no As MSComctlLib.Node, nome As String, key As String)
    
    Dim dinamica As clsDinamica
    
    Set dinamica = definicoes.dinamicaAtual
    
    If nome = "Estado" Then
    
        Dim estadoComposto As clsEstadoComposto
        
        Set estadoComposto = dinamica.getCondicao.getEstadoComposto(key)
        
        If Not estadoComposto.getConstante Then
        
            Dim estado As clsEstado
            Set estado = definicoes.sinfonia.getEstados.getEstado(estadoComposto.getIdEstado)
            
            If Not estado Is Nothing Then
                frmEstado.carregaEstado estado, frmPrincipal.iaSinfonia.nosArvore.Item(estado.getId)
            End If
        End If
        
    ElseIf nome = "Evento" Then
    
        Dim evento As clsEvento
        Dim eventoAss As clsEventoAss
        
        Set eventoAss = dinamica.getEventosDisparadores.getEventoPeloID(key)

        If eventoAss Is Nothing Then
        
            Set eventoAss = dinamica.getEventosGerados.getEventoPeloID(key)
            
            If eventoAss Is Nothing Then
            
                Set eventoAss = dinamica.getEventosGeradosSenao.getEventoPeloID(key)
            End If
        End If

        Set evento = definicoes.sinfonia.getEventos.getEvento(eventoAss.getIdEvento)
        
        If Not evento Is Nothing Then
            frmEvento.carregaEvento evento, frmPrincipal.iaSinfonia.nosArvore.Item(evento.getId)
        End If

    End If
    
End Sub

Private Sub iaDinamica_editouItem(no As MSComctlLib.Node, nome As String, key As String, novoValor As String)

    If no.Tag = "Principal" Then
    
        definicoes.dinamicaAtual.setNome novoValor
        definicoes.noDinamicaAtual.Text = definicoes.dinamicaAtual.getNome
            
    ElseIf no.Tag = "Operador" Then
    
        Dim keyPai As String
        
        If no.Parent.Tag = "Estado Dependente" Then
        
            keyPai = no.Previous.key
            
        Else
        
            keyPai = no.Parent.key
        
        End If
    
        definicoes.dinamicaAtual.getCondicao.mudaOperador keyPai, novoValor
            
    End If
End Sub

Private Sub iaDinamica_fechouNo(no As MSComctlLib.Node)
    If no.Tag = "Condição" Then
        definicoes.dinamicaAtual.getCondicao.getCondicao(no.key).confPasta.setAberto False
    
    ElseIf no.Tag = "Estado Dependente" Then
        definicoes.dinamicaAtual.getCondicao.procuraEstadoDependente(no.key).confPasta.setAberto False
    
    End If
End Sub

Private Sub iaDinamica_marcouItem(no As MSComctlLib.Node, nome As String, key As String)

    If nome = "Estado" Then
    
        definicoes.dinamicaAtual.getCondicao.getEstadoComposto(key).setValorAtual (no.Checked)
        carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
        
    ElseIf nome = "Condição" Then
    
        definicoes.dinamicaAtual.getCondicao.getCondicao(key).setModificador (no.Checked)
        carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
    
    ElseIf nome = "Principal" Then
    
        definicoes.dinamicaAtual.setHabilitada Not no.Checked
        carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
        
        If definicoes.dinamicaAtual.getHabilitada Then
            definicoes.noDinamicaAtual.Image = "dinamica"
        Else
            definicoes.noDinamicaAtual.Image = "dinamica_desabilitada"
        End If
    End If

End Sub

Private Sub iaDinamica_OLEDragDrop(Data As MSComctlLib.DataObject, Effect As Long, Button As Integer, shift As Integer, X As Single, Y As Single, noSobre As Node)

    Dim controlPressionado As Boolean
                    
    controlPressionado = shift And &H2&
        
    If Data.GetFormat(vbCFText) Then
    
        If Not noSobre Is Nothing Then
        
            If (definicoes.tipoNoAtual = tnEvento) And (InStr(1, Data.GetData(vbCFText), "Sinfonia") <> 0) Then
                                        
                Dim eventoAss As clsEventoAss
                Dim noEvento As Node
                                        
                If noSobre.Tag = "EventosDisparadores" Then
                                                                                            
                    Set eventoAss = definicoes.dinamicaAtual.getEventosDisparadores.addEvento(definicoes.noEventoAtual.key)
                    
                    Set noEvento = iaDinamica.nosArvore.add(noSobre.key, tvwChild, eventoAss.getId, _
                                                            eventoAss.emString(definicoes.dinamicaAtual.getId), _
                                                            eventoAss.getImagem)
                                                                                                                                 
                    noEvento.Tag = "Evento"
                    
                ElseIf noSobre.Tag = "EventosGerados" Then
                                                
                    Set eventoAss = definicoes.dinamicaAtual.getEventosGerados.addEvento(definicoes.noEventoAtual.key)
                    
                    Set noEvento = iaDinamica.nosArvore.add(noSobre.key, tvwChild, eventoAss.getId, _
                                                            eventoAss.emString(definicoes.dinamicaAtual.getId), _
                                                            eventoAss.getImagem)
                    
                    noEvento.Tag = "Evento"
                    
                ElseIf noSobre.Tag = "EventosGeradosSenao" Then
                                
                    Set eventoAss = definicoes.dinamicaAtual.getEventosGeradosSenao.addEvento(definicoes.noEventoAtual.key)
                    
                    Set noEvento = iaDinamica.nosArvore.add(noSobre.key, tvwChild, eventoAss.getId, _
                                                            eventoAss.emString(definicoes.dinamicaAtual.getId), _
                                                            eventoAss.getImagem)
                    
                    noEvento.Tag = "Evento"
                    
                End If
                
                carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
                
            Else
            
                If (noSobre.Tag = "Estado") Or (noSobre.Tag = "Estado Dependente") Then
            
                    Dim estado As clsEstadoComposto
                                                                                                    
                    'Muda o tipo do estado
                    If (noSobre.Tag = "Estado") And Not controlPressionado Then
                                                                                
                        Set estado = definicoes.dinamicaAtual.getCondicao.procuraEstadoComposto(noSobre.key)
                          
                    ElseIf ((noSobre.Tag = "Estado") And controlPressionado) Or _
                           (noSobre.Tag = "Estado Dependente") Then
                                        
                        Dim estadoDependente As clsEstadoDep
                        
                        If noSobre.Tag = "Estado Dependente" Then
                            Set estadoDependente = definicoes.dinamicaAtual.getCondicao.procuraEstadoDependente(noSobre.key)
                        Else
                            Set estadoDependente = definicoes.dinamicaAtual.getCondicao.procuraEstadoComposto(noSobre.key).getPai
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
                    
                    carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
                    
                    
                    
                ElseIf noSobre.Tag = "Condição" Then
                                    
                    Dim mudarTipo As Boolean
                    Dim condicao As clsCondicao
                        
                    Set condicao = definicoes.dinamicaAtual.getCondicao.getCondicao(noSobre.key)
                
                    If controlPressionado Then
                    
                        mudarTipo = True
                    
                    ElseIf condicao.getTipoCondicao = tcComposta Then
                                                    
                        Set condicao = condicao.addCondicao
                        mudarTipo = True
                        
                    End If
                    
                    If mudarTipo Then
                    
                        If Data.GetData(vbCFText) = "Composta" Then
                                                        
                            condicao.setTipoCondicao tcComposta
                                                        
                        ElseIf Data.GetData(vbCFText) = "Comparação" Then
                        
                            condicao.setTipoCondicao tcComparacao
                        
                        End If
                    End If
                    
                    carregaDinamica definicoes.dinamicaAtual, definicoes.noDinamicaAtual
                    
                End If
            End If
        End If
        
        
    End If
    
End Sub

