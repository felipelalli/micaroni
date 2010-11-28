VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsParametro"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private id As String
Private nome As String
Private apelidos As New clsApelidos
Private valorInicial As Boolean


Public Sub setId(pId As String)
    id = pId
    apelidos.setIdPai id
End Sub

Public Function getId() As String
    getId = id
End Function

Public Sub setNome(pNome As String)
    nome = pNome
End Sub

Public Function getNome() As String
    getNome = nome
End Function

Public Function getApelidos() As clsApelidos
    Set getApelidos = apelidos
End Function

Public Sub setValorInicial(pValorInicial As Boolean)
    valorInicial = pValorInicial
End Sub

Public Function getValorInicial() As Boolean
    getValorInicial = valorInicial
End Function

Public Function copia(parametro As clsParametro)

    parametro.setNome Me.getNome
    parametro.setValorInicial Me.getValorInicial
    
    Me.getApelidos.copia parametro.getApelidos

End Function

Public Function carregaXML(noXml As clsNoXML)

    Dim grupoParametro As New clsGrupoXML
    
    grupoParametro.carregaGrupoXML noXml, Array("Id", "Nome", "ValorInicial"), Array("Apelidos")
    
    Me.setNome grupoParametro.getCampo("Nome").getValor
    Me.setId grupoParametro.getCampo("Id").getValor
    Me.setValorInicial Not grupoParametro.getCampo("ValorInicial").semValor
    
    If Not grupoParametro.getGrupo("Apelidos").getNo Is Nothing Then
    
        Me.getApelidos.carregaXML grupoParametro.getGrupo("Apelidos").getNo
    
    End If
    
End Function

Public Function toNoXML() As IXMLDOMNode

    Dim salvador As New clsSalvEstados
    Dim noParametro As IXMLDOMNode
    
    Set noParametro = salvador.criaNo("Parametro")
    
    noParametro.appendChild salvador.criaNo("Id", getId)
    noParametro.appendChild salvador.criaNo("Nome", getNome)
    
    If getValorInicial Then
        noParametro.appendChild salvador.criaNo("ValorInicial")
    End If
    
    noParametro.appendChild apelidos.toNoXML

    Set toNoXML = noParametro

End Function
