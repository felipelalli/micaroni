VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsConfiguracao"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private MAX_ARQUIVOS As Integer
Private arqConfiguracao As String

Private arquivos As New Collection

Public posDimSinfonia As New clsPosDim
Public posDimGrupo As New clsPosDim
Public posDimEstado As New clsPosDim
Public posDimEvento As New clsPosDim
Public posDimDinamica As New clsPosDim
Public posDimLixeira As New clsPosDim
Public posDimContexto As New clsPosDim

Public Function ultimoArquivo() As String
    
    If arquivos.Count = 0 Then
        ultimoArquivo = ""
    Else
        ultimoArquivo = arquivos.Item(arquivos.Count)
    End If
    
End Function

Public Function abriuArquivo(arquivo As String)

    Dim i As Integer

    For i = 1 To arquivos.Count
        If arquivos.Item(i) = arquivo Then
            arquivos.remove i
            Exit For
        End If
    Next

    arquivos.add arquivo
    
    If arquivos.Count > MAX_ARQUIVOS Then
        arquivos.remove (1)
    End If
    
    

End Function

Public Function arquivo(qual As Integer) As String

    arquivo = arquivos.Item(qual)

End Function

Public Function quantosArquivos() As Integer

    quantosArquivos = arquivos.Count

End Function

Public Function carregaXML(noXml As clsNoXML)

    Dim noArquivo As clsNoXML
    Dim grupoConfiguracao As New clsGrupoXML
    
    grupoConfiguracao.carregaGrupoXML noXml, , Array("PosDimGrupo", "PosDimEvento", "PosDimEstado", "PosDimDinamica", "PosDimSinfonia", "PosDimLixeira", "PosDimContexto", "UltimosArquivos")
    
    Me.posDimSinfonia.carregarXML grupoConfiguracao.getGrupo("PosDimSinfonia").getNo
    Me.posDimGrupo.carregarXML grupoConfiguracao.getGrupo("PosDimGrupo").getNo
    Me.posDimEvento.carregarXML grupoConfiguracao.getGrupo("PosDimEvento").getNo
    Me.posDimEstado.carregarXML grupoConfiguracao.getGrupo("PosDimEstado").getNo
    Me.posDimDinamica.carregarXML grupoConfiguracao.getGrupo("PosDimDinamica").getNo
    Me.posDimLixeira.carregarXML grupoConfiguracao.getGrupo("PosDimLixeira").getNo
    Me.posDimContexto.carregarXML grupoConfiguracao.getGrupo("PosDimContexto").getNo
    
    Set noArquivo = grupoConfiguracao.getGrupo("UltimosArquivos").getNo.primeiroFilho
    
    While Not noArquivo Is Nothing
    
        If noArquivo.nome = "Arquivo" Then
            arquivos.add noArquivo.valor
        End If
    
        Set noArquivo = noArquivo.proximoNo
    
    Wend
    
End Function

Public Function toNoXML() As IXMLDOMNode

    Dim salvador As New clsSalvEstados
    Dim noConfiguracao As IXMLDOMNode
    Dim noArquivos As IXMLDOMNode
    Dim i As Integer
    
    Set noConfiguracao = salvador.criaNo("Configuracao")
    
    noConfiguracao.appendChild Me.posDimSinfonia.toNoXML("PosDimSinfonia")
    noConfiguracao.appendChild Me.posDimGrupo.toNoXML("PosDimGrupo")
    noConfiguracao.appendChild Me.posDimEvento.toNoXML("PosDimEvento")
    noConfiguracao.appendChild Me.posDimEstado.toNoXML("PosDimEstado")
    noConfiguracao.appendChild Me.posDimDinamica.toNoXML("PosDimDinamica")
    noConfiguracao.appendChild Me.posDimLixeira.toNoXML("PosDimLixeira")
    noConfiguracao.appendChild Me.posDimContexto.toNoXML("PosDimContexto")
    
    Set noArquivos = salvador.criaNo("UltimosArquivos")
    
    For i = 1 To arquivos.Count
    
        noArquivos.appendChild salvador.criaNo("Arquivo", arquivos.Item(i))
    
    Next
    
    noConfiguracao.appendChild noArquivos

    Set toNoXML = noConfiguracao

End Function


Public Function carrega() As Boolean

    Dim arquivoXML As New clsArquivoXML
    
    If Not arquivoXML.carregaArquivo(arqConfiguracao) Then

        carrega = False
        
    Else
        
        Me.carregaXML arquivoXML.noPrincipal
                    
        carrega = True
    
    End If

End Function

Public Function salva() As Boolean
   
    Dim documentoXML As New MSXML2.DOMDocument
    
    documentoXML.appendChild Me.toNoXML
    
    documentoXML.save arqConfiguracao
    
End Function


Private Sub Class_Initialize()

    MAX_ARQUIVOS = 5
    arqConfiguracao = Environ("APPDATA") & "\SCCConf_2.0.xml"
    
End Sub


