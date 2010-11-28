VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsApelido"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private id As String
Private nome As String


Public Sub setId(pId As String)
    id = pId
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

Public Function copia(apelido As clsApelido)

    apelido.setNome Me.getNome

End Function

Public Function carregaXML(noXml As clsNoXML)
 
    Dim grupoApelido As New clsGrupoXML
    
    grupoApelido.carregaGrupoXML noXml, Array("Id", "Nome")
    
    Me.setNome grupoApelido.getCampo("Nome").getValor
    Me.setId grupoApelido.getCampo("Id").getValor

End Function

Public Function toNoXML() As IXMLDOMNode

    Dim salvador As New clsSalvEstados
    Dim noApelido As IXMLDOMNode
    
    Set noApelido = salvador.criaNo("Apelido")
    
    noApelido.appendChild salvador.criaNo("Id", getId)
    noApelido.appendChild salvador.criaNo("Nome", getNome)

    Set toNoXML = noApelido

End Function
