VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsGrupo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private id As String
Private nome As String
Private descricao As String
Private cor As Long
Public confPasta As New clsConfPasta

Public Function getImagem() As String
    getImagem = "grupo"
End Function

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

Public Sub setDescricao(pDescricao As String)
    descricao = pDescricao
End Sub

Public Function getDescricao() As String
    getDescricao = descricao
End Function

Public Function getCor() As Long
    getCor = cor
End Function

Public Function setCor(pCor As Long)
    cor = pCor
End Function

Public Function carregaXML(noXml As clsNoXML)
 
    Dim grupoGrupo As New clsGrupoXML
           
    grupoGrupo.carregaGrupoXML noXml, Array("Id", "Nome", "Descricao", "Cor"), Array("ConfPasta")
            
    Me.setNome grupoGrupo.getCampo("Nome").getValor
    Me.setId grupoGrupo.getCampo("Id").getValor
    Me.setDescricao grupoGrupo.getCampo("Descricao").getValor
    
    If grupoGrupo.getCampo("Cor").semValor Then
        Me.setCor RGB((255 * Rnd) + 1, (255 * Rnd) + 1, (255 * Rnd) + 1)
    Else
        Me.setCor CLng(grupoGrupo.getCampo("Cor").getValor)
    End If
        
    Me.confPasta.carregaXML grupoGrupo.getGrupo("ConfPasta").getNo, False
    
    
End Function



Public Function toNoXML() As IXMLDOMNode

    Dim salvador As New clsSalvEstados
    Dim noGrupo As IXMLDOMNode
    
    Set noGrupo = salvador.criaNo("Grupo")
    
    noGrupo.appendChild salvador.criaNo("Id", getId)
    noGrupo.appendChild salvador.criaNo("Nome", getNome)
    noGrupo.appendChild salvador.criaNo("Descricao", getDescricao)
    noGrupo.appendChild salvador.criaNo("Cor", Str(getCor))
    noGrupo.appendChild Me.confPasta.toNoXML
    
    Set toNoXML = noGrupo

End Function

