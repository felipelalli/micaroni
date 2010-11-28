VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.UserControl ItensEArvore 
   ClientHeight    =   6285
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   4620
   ScaleHeight     =   6285
   ScaleWidth      =   4620
   Begin VB.Timer timerMudarNo 
      Interval        =   1
      Left            =   4200
      Top             =   0
   End
   Begin MSComctlLib.TreeView tvArvore 
      Height          =   5295
      Left            =   0
      TabIndex        =   1
      Top             =   960
      Width           =   4575
      _ExtentX        =   8070
      _ExtentY        =   9340
      _Version        =   393217
      Indentation     =   0
      Sorted          =   -1  'True
      Style           =   7
      BorderStyle     =   1
      Appearance      =   0
      OLEDragMode     =   1
      OLEDropMode     =   1
   End
   Begin MSComctlLib.ListView lvItens 
      Height          =   855
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   4575
      _ExtentX        =   8070
      _ExtentY        =   1508
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
End
Attribute VB_Name = "ItensEArvore"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit


Private Enum Constantes
    borda = 100
    espacoInterno = 50
End Enum

Public Enum Orientacoes
    horizontal = 1
    vertical = 2
End Enum

Public Enum TipoMarcacao
    nenhuma = 1
    CheckBox = 2
    radiobutton = 3
End Enum

Private nome As String

Private itens As New clsItens
Private orientacao As Orientacoes
Private tamanhoDoListView As Integer

Private noAtual As Node
Private noAMover As Node
Private itemSelecionado As ListItem

Private possuiPrincipal As Boolean

Private keyAtual As Integer

Private noTirarMarcacao As Node
Private noColocarBold As Node

Private itensQuePodemSerCheckados As New Collection

Private ordemAlfabetica As Boolean

Public Event adicionouItem(no As Node)
Public Event abriuNo(no As Node)
Public Event fechouNo(no As Node)
Public Event editouItem(no As Node, nome As String, key As String, novoValor As String)
Public Event selecionouItem(no As Node, nome As String, key As String, botao As Integer, shift As Integer)
Public Event duploClique(no As Node, nome As String, key As String)
Public Event marcouItem(no As Node, nome As String, key As String)
Public Event desmarcouItem(no As Node, nome As String, key As String)
Public Event OLEDragDrop(Data As MSComctlLib.DataObject, Effect As Long, Button As Integer, shift As Integer, x As Single, y As Single, noSobre As Node)
Public Event OLEDragOver(Data As MSComctlLib.DataObject, Effect As Long, Button As Integer, shift As Integer, x As Single, y As Single, State As Integer, noSobre As Node)

Public Function setOrdemAlfabetica(pOrdemAlfabetica As Boolean)
    ordemAlfabetica = pOrdemAlfabetica
    tvArvore.Sorted = ordemAlfabetica
End Function

Public Function getOrdemAlfabetica() As Boolean
    getOrdemAlfabetica = ordemAlfabetica
End Function

Public Function getItens() As clsItens
    Set getItens = itens
End Function

Public Sub setNome(pNome As String)
    nome = pNome
End Sub

Public Function getNome() As String
    getNome = nome
End Function

Public Sub setPossuiCheckBox(possui As Boolean)
    tvArvore.Checkboxes = possui
End Sub

Public Function getPossuiCheckBox() As Boolean
    getPossuiCheckBox = tvArvore.Checkboxes
End Function

Public Function adicionaItemQuePodeSerCheckado(item As String)
    itensQuePodemSerCheckados.add item
End Function

Public Function itemPodeSerCheckado(item As String) As Boolean

    Dim i As Integer

    For i = 1 To itensQuePodemSerCheckados.Count
    
        If itensQuePodemSerCheckados.item(i) = item Then
            itemPodeSerCheckado = True
            Exit Function
        End If
    
    Next
    
    itemPodeSerCheckado = False
    
End Function

Private Sub timerMudarNo_Timer()

    timerMudarNo.Enabled = False
    
    
    If Not noTirarMarcacao Is Nothing Then
    
        noTirarMarcacao.Checked = False
        noTirarMarcacao.Bold = False
        Set noTirarMarcacao = Nothing
    End If
    
    
    If Not noColocarBold Is Nothing Then
        
        noColocarBold.Bold = noColocarBold.Checked
        Set noColocarBold = Nothing
    End If
    
End Sub

Public Sub setOrientacao(pOrientacao As Orientacoes)
    orientacao = pOrientacao
    UserControl_Resize
End Sub

Private Sub tvArvore_Collapse(ByVal Node As MSComctlLib.Node)
    If Not Node Is Nothing Then
        RaiseEvent fechouNo(Node)
    End If
End Sub

Private Sub tvArvore_DblClick()
    If Not noAtual Is Nothing Then
        RaiseEvent duploClique(noAtual, noAtual.Tag, noAtual.key)
    End If
End Sub

Private Sub tvArvore_Expand(ByVal Node As MSComctlLib.Node)
    If Not Node Is Nothing Then
        RaiseEvent abriuNo(Node)
    End If
End Sub

Private Sub UserControl_Initialize()

    nome = ""

    limpa
    
    Set lvItens.Icons = Nothing
    Set tvArvore.ImageList = Nothing

    orientacao = horizontal
    UserControl_Resize
    
    Me.setOrdemAlfabetica True
    
    
    
    tamanhoDoListView = 735
    
End Sub




Public Sub setImagensItens(imagens As Object)

    lvItens.Icons = imagens

End Sub

Public Sub setImagensArvore(imagens As Object)

    tvArvore.ImageList = imagens

End Sub

Public Sub setNoPrincipal(nome As String, imagem As String, imagemAberto As String, Optional emOrdemAlfabetica As Boolean = True)
    
    Dim noPrincipal As Node
    
    limpa
    
    Set noPrincipal = tvArvore.Nodes.add(, , "Principal", nome, imagem)
    noPrincipal.Bold = True
    noPrincipal.Expanded = True
    noPrincipal.ExpandedImage = imagemAberto
    noPrincipal.Tag = "Principal"
    noPrincipal.Sorted = emOrdemAlfabetica
    
    possuiPrincipal = True

End Sub

Public Sub habilita(habilitado As Boolean)
    tvArvore.Enabled = habilitado
    lvItens.Enabled = habilitado
End Sub

Public Sub limpa()

    keyAtual = 0
    tvArvore.Nodes.Clear
    possuiPrincipal = False
    
    Set noAtual = Nothing
    Set noAMover = Nothing
    
End Sub

Public Sub adicionaItem(nome As String, _
                        grupo As Boolean, _
                        Optional imagem As String = "__nadinha__", _
                        Optional imagemAberto As String = "__nadinha__", _
                        Optional paisPossiveis As Variant, _
                        Optional marcacao As TipoMarcacao = nenhuma)
    
    Dim item As clsItem
    
    Set item = itens.add(nome)
    
    item.setGrupo grupo
    
    item.setMarcacao marcacao
    
    If item.getMarcacao <> nenhuma Then
        tvArvore.Checkboxes = True
    End If
    
    If imagem <> "__nadinha__" Then
        item.setImagem imagem
    Else
        item.setImagem nome
    End If
    
    If imagemAberto <> "__nadinha__" Then
        item.setImagemAberto imagemAberto
    Else
        item.setImagemAberto nome
    End If

    If Not IsMissing(paisPossiveis) Then
        
        Dim i As Integer
        
        For i = 0 To UBound(paisPossiveis)
        
            item.addPaiPossivel CStr(paisPossiveis(i))
        
        Next
    End If

    If Not IsNull(lvItens.Icons) Then
        lvItens.ListItems.add , item.getNome, item.getNome, item.getImagem
    Else
        lvItens.ListItems.add , item.getNome, item.getNome
    End If
    
    atualizaTamanhoDoListView
    UserControl_Resize
    alinhar
    
End Sub


Public Function nosArvore() As Nodes

    Set nosArvore = tvArvore.Nodes

End Function


Private Sub UserControl_Resize()
    
    Dim novaLargura As Integer
    Dim novaAltura As Integer
    
    If orientacao = horizontal Then
    
        lvItens.Left = borda
        lvItens.Top = borda
        lvItens.Height = tamanhoDoListView
        
        tvArvore.Left = borda
        tvArvore.Top = tamanhoDoListView + (2 * borda)
        
        novaLargura = UserControl.Width - (2 * borda)
        
        If novaLargura >= tamanhoDoListView Then
        
            lvItens.Width = novaLargura
            tvArvore.Width = novaLargura
            
        Else
        
            lvItens.Width = tamanhoDoListView
            tvArvore.Width = tamanhoDoListView
            
        End If
        
        novaAltura = UserControl.Height - (tamanhoDoListView + (3 * borda))
        
        If novaAltura >= tamanhoDoListView Then
        
            tvArvore.Height = novaAltura
            
        Else
                    
            tvArvore.Height = tamanhoDoListView
            
        End If
    Else
        lvItens.Top = borda
        lvItens.Left = borda
        lvItens.Width = tamanhoDoListView
        
        tvArvore.Top = borda
        tvArvore.Left = tamanhoDoListView + (2 * borda)
        
        novaAltura = UserControl.Height - (2 * borda)
        
        If novaAltura >= tamanhoDoListView Then
        
            lvItens.Height = novaAltura
            tvArvore.Height = novaAltura
            
        Else
        
            lvItens.Height = tamanhoDoListView
            tvArvore.Height = tamanhoDoListView
            
        End If
        
        novaLargura = UserControl.Width - (tamanhoDoListView + (3 * borda))
        
        If novaLargura >= tamanhoDoListView Then
        
            tvArvore.Width = novaLargura
            
        Else
                    
            tvArvore.Width = tamanhoDoListView
            
        End If
    End If
        
End Sub

Private Sub alinhar()

    Dim i As Integer
    Dim item As ListItem
    Dim distancia As Integer
    Dim itemAnterior As ListItem
    
    If orientacao = horizontal Then
    
        distancia = 200
        
        Set itemAnterior = Nothing
    
        For i = 1 To lvItens.ListItems.Count
            
            Set item = lvItens.ListItems.item(i)
        
            If itemAnterior Is Nothing Then
            
                item.Top = espacoInterno
                item.Left = distancia
                
            Else
            
                item.Top = espacoInterno
                item.Left = itemAnterior.Left + itemAnterior.Width + distancia
            End If
            
            Set itemAnterior = item
        
        Next
    Else
    
        distancia = 200
        
        Set itemAnterior = Nothing
    
        For i = 1 To lvItens.ListItems.Count
            
            Set item = lvItens.ListItems.item(i)
        
            If itemAnterior Is Nothing Then
            
                item.Left = espacoInterno
                item.Top = distancia
                
            Else
            
                item.Left = espacoInterno
                item.Top = itemAnterior.Top + itemAnterior.Height + distancia
            End If
            
            Set itemAnterior = item
        
        Next
    End If
End Sub


Private Sub atualizaTamanhoDoListView()
    
    Dim i As Integer
    Dim item As ListItem
    
    tamanhoDoListView = 0
    
    For i = 1 To lvItens.ListItems.Count
    
        Set item = lvItens.ListItems.item(i)
    
        If orientacao = horizontal Then
            If item.Height > tamanhoDoListView Then
                tamanhoDoListView = item.Height
            End If
        Else
            If item.Width > tamanhoDoListView Then
                tamanhoDoListView = item.Width
            End If
        End If
    Next
    
    tamanhoDoListView = tamanhoDoListView + (espacoInterno * 2)
    
End Sub






Private Sub lvItens_ItemClick(ByVal item As MSComctlLib.ListItem)
    Set itemSelecionado = item
End Sub

Private Sub lvItens_OLEStartDrag(Data As MSComctlLib.DataObject, AllowedEffects As Long)

    If itemSelecionado Is Nothing Then
        AllowedEffects = vbDropEffectNone
    Else
        AllowedEffects = vbDropEffectCopy
        Data.SetData itemSelecionado.key, vbCFText
    End If
    
End Sub


Private Sub tvArvore_MouseDown(Button As Integer, shift As Integer, x As Single, y As Single)
    
    Set noAtual = tvArvore.HitTest(x, y)
    
    If Not noAtual Is Nothing Then
            
        RaiseEvent selecionouItem(noAtual, noAtual.Tag, noAtual.key, Button, shift)
        
    End If
        
    Set noAMover = noAtual
            
End Sub




Private Sub tvArvore_AfterLabelEdit(Cancel As Integer, NewString As String)
        
    Dim noRef As Node
    
    Set noRef = tvArvore.SelectedItem
        
    RaiseEvent editouItem(noRef, noRef.Tag, noRef.key, NewString)
        
End Sub



Private Sub tvArvore_NodeCheck(ByVal Node As MSComctlLib.Node)

    Dim i As Integer
    Dim nos As Nodes
    Dim item As clsItem
        
    Set item = itens.getItemPeloNome(Node.Tag)
        
    If item Is Nothing Then
        
        If itemPodeSerCheckado(Node.Tag) Then
        
            RaiseEvent marcouItem(Node, Node.Tag, Node.key)
            
        Else
        
            Set noTirarMarcacao = Node
            timerMudarNo.Enabled = True
            
        End If
        
    Else
    
        If item.getMarcacao = nenhuma Then
                    
            Set noTirarMarcacao = Node
            timerMudarNo.Enabled = True
        
        Else

            Set noColocarBold = Node
            timerMudarNo.Enabled = True
            
            RaiseEvent marcouItem(Node, Node.Tag, Node.key)
            
            'Se esse item se comporta como um radiobutton, desmarca todos os outros
            If item.getMarcacao = radiobutton Then
                                
                Set nos = tvArvore.Nodes
                
                For i = 1 To nos.Count
                                
                    If i <> Node.Index Then
                                
                        Dim no As Node
                                            
                        Set no = nos.item(i)
                        
                        If (no.Tag = item.getNome) And (no.Checked) Then
                            
                            no.Checked = False
                            no.Bold = False
                            
                            RaiseEvent desmarcouItem(no, no.Tag, no.key)
                            
                        End If
                    End If
                Next
                
            End If
            
        End If
    End If
    
End Sub


Private Sub tvArvore_OLEDragDrop(Data As MSComctlLib.DataObject, Effect As Long, Button As Integer, shift As Integer, x As Single, y As Single)
            
    Dim achou As Boolean
    
    achou = False
    
    If Data.GetFormat(vbCFText) Then
        
        Dim item As clsItem
        
        Set item = itens.getItemPeloNome(Data.GetData(vbCFText))
    
        If Not item Is Nothing Then
        
            'ADICIONA NA ARVORE
            '**************************************************
            '**************************************************
            Dim novoNo As Node
            
            If noAtual Is Nothing Then
                If Not item.possuiRestricaoDePai Or (possuiPrincipal And item.ehPai("Principal")) Then
                
                    If possuiPrincipal Then
                        Set novoNo = tvArvore.Nodes.add("Principal", tvwChild, proximaKey, "Novo " & item.getNome, item.getImagem)
                    Else
                        Set novoNo = tvArvore.Nodes.add(, , proximaKey, "Novo " & item.getNome, item.getImagem)
                    End If
                    
                    novoNo.Tag = item.getNome
                    novoNo.Sorted = Me.getOrdemAlfabetica
                    
                    If item.getGrupo Then
                        novoNo.Expanded = True
                        novoNo.ExpandedImage = item.getImagemAberto
                    End If
                    
                    RaiseEvent adicionouItem(novoNo)
                    
                End If
            Else
            
                Dim itemNoAtual As clsItem
                Dim podeIncluir As Boolean
                                
                Set itemNoAtual = itens.getItemPeloNome(noAtual.Tag)
                
                If Not item.possuiRestricaoDePai Then
                    podeIncluir = True
                Else
                    If Not itemNoAtual Is Nothing Then
                        podeIncluir = item.ehPai(itemNoAtual.getNome)
                    Else
                        If noAtual.key = "Principal" Then
                            podeIncluir = item.ehPai(noAtual.key)
                        End If
                    End If
                End If
            
                If podeIncluir Then
                
                    Dim relacao As Integer
                    
                    If Not itemNoAtual Is Nothing Then
                        If itemNoAtual.getGrupo Then
                            relacao = tvwChild
                        Else
                            relacao = tvwNext
                        End If
                    Else
                        relacao = tvwChild
                    End If
                
                    Set novoNo = tvArvore.Nodes.add(noAtual.key, relacao, proximaKey, "Novo " & item.getNome, item.getImagem)
                    
                    novoNo.Tag = item.getNome
                    novoNo.Sorted = Me.getOrdemAlfabetica
                    
                    If item.getGrupo Then
                        novoNo.Expanded = True
                        novoNo.ExpandedImage = item.getImagemAberto
                    End If
                    
                    RaiseEvent adicionouItem(novoNo)
                    
                End If
            End If
            '**************************************************
            '**************************************************
                        
            achou = True
        End If
        
        If Not achou Then
                            
            If Mid(Data.GetData(vbCFText), 1, 9) = "NoArvore_" Then
                achou = True
            End If
            
        End If
                    
    End If
        
    Effect = vbDropEffectCopy
    RaiseEvent OLEDragDrop(Data, Effect, Button, shift, x, y, noAtual)
    
End Sub

Private Sub tvArvore_OLEDragOver(Data As MSComctlLib.DataObject, Effect As Long, Button As Integer, shift As Integer, x As Single, y As Single, State As Integer)

    Dim noSobre As Node

    tvArvore.SetFocus

    Set noSobre = tvArvore.HitTest(x, y)
    
    If Not noAtual Is Nothing Then
        noAtual.Selected = False
    End If
    
    If Not noSobre Is Nothing Then
    
        noSobre.Selected = True
        
    End If
            
    Set noAtual = noSobre

    If State = vbEnter Then
        
    ElseIf State = vbLeave Then
            
        
    ElseIf State = vbOver Then
    
        Dim achou As Boolean
    
        achou = False
        
        If Data.GetFormat(vbCFText) Then
            
            Dim i As Integer
            
            For i = 1 To itens.quantos
            
                Dim item As clsItem
                
                Set item = itens.getItem(i)
            
                If Data.GetData(vbCFText) = item.getNome Then
                    achou = True
                    Exit For
                End If
            Next
            
            If Not achou Then
                                
                If Mid(Data.GetData(vbCFText), 1, 9) = "NoArvore_" Then
                    achou = True
                End If
                
            End If
                        
        End If
        
    End If
    
    Effect = vbDropEffectCopy
    RaiseEvent OLEDragOver(Data, Effect, Button, shift, x, y, State, noAtual)
    
End Sub

Private Sub tvArvore_OLEStartDrag(Data As MSComctlLib.DataObject, AllowedEffects As Long)

    If noAMover Is Nothing Then
    
        AllowedEffects = vbDropEffectNone
        
    Else
    
        AllowedEffects = vbDropEffectCopy
        Data.SetData noAMover.key, vbCFText
        
    End If
    
End Sub

Private Function proximaKey() As String
    
    On Error Resume Next
    
    Do
        proximaKey = "NoArvore_" & nome & "_key" & keyAtual
        keyAtual = keyAtual + 1
        
    Loop While Not tvArvore.Nodes.item(proximaKey) Is Nothing

End Function



