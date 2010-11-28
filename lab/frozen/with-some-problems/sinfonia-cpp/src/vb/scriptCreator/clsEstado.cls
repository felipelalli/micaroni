VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsEstado"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private id As String
Private nome As String
Private classe As String
Private descricao As String
Private externo As Boolean
Private atributos As New clsAtributos
Public confPasta As New clsConfPasta

Public Sub setId(pId As String)
    id = pId
End Sub

Public Function getId() As String
    getId = id
End Function


Public Sub setNome(pNome As String)
    nome = pNome
End Sub

Public Function getNome(Optional idRelacionado As String = "__nadinha__") As String
    
    If idRelacionado = "__nadinha__" Then
        getNome = nome
    Else
        getNome = definicoes.vCaminhoCompleto(idRelacionado, Me.getId) & nome
    End If
End Function

Public Function getImagem() As String

    If Me.getExterno Then
        getImagem = "estado_externo"
    Else
        getImagem = "estado"
    End If

End Function

Public Sub setClasse(pClasse As String)
    classe = pClasse
End Sub

Public Function getClasse() As String
    getClasse = classe
End Function



Public Sub setDescricao(pDescricao As String)
    descricao = pDescricao
End Sub

Public Function getDescricao() As String
    getDescricao = descricao
End Function


Public Sub setExterno(pExterno As Boolean)
    externo = pExterno
End Sub

Public Function getExterno() As Boolean
    getExterno = externo
End Function

Public Function getAtributos() As clsAtributos
    Set getAtributos = atributos
End Function

Private Sub Class_Initialize()
    classe = "MultiFuncional"
End Sub

Public Function copia(estado As clsEstado)

    estado.setClasse Me.getClasse
    estado.setNome "Copia " & Me.getNome
    estado.setExterno estado.getExterno
    estado.setDescricao estado.getDescricao
    
    Me.confPasta.copia estado.confPasta
    Me.getAtributos.copia estado.getAtributos
    
End Function

Public Function carregaXML(noXml As clsNoXML)
    
    Dim grupoEstado As New clsGrupoXML
    
    grupoEstado.carregaGrupoXML noXml, Array("Id", "Nome", "Classe", "Descricao", "Externo"), Array("Atributos", "Eventos", "ConfPasta")
            
    Me.setNome grupoEstado.getCampo("Nome").getValor
    Me.setId grupoEstado.getCampo("Id").getValor
                    
    Me.setClasse grupoEstado.getCampo("Classe").getValor
    Me.setDescricao grupoEstado.getCampo("Descricao").getValor
    Me.setExterno Not grupoEstado.getCampo("Externo").semValor
    
    If Not grupoEstado.getGrupo("Atributos").getNo Is Nothing Then
    
        Me.getAtributos.carregaXML grupoEstado.getGrupo("Atributos").getNo
        
    End If
    
    If Not grupoEstado.getGrupo("Eventos").getNo Is Nothing Then
                    
        definicoes.sinfonia.getEventos.carregaXML grupoEstado.getGrupo("Eventos").getNo
                
    End If
    
    Me.confPasta.carregaXML grupoEstado.getGrupo("ConfPasta").getNo, True
    
End Function

Public Function toNoXML() As IXMLDOMNode

    Dim salvador As New clsSalvEstados
    Dim noEstado As IXMLDOMNode
    
    Set noEstado = salvador.criaNo("Estado")
    
    noEstado.appendChild salvador.criaNo("Id", getId)
    noEstado.appendChild salvador.criaNo("Nome", getNome)
    noEstado.appendChild salvador.criaNo("Classe", getClasse)
    noEstado.appendChild salvador.criaNo("Descricao", getDescricao)
    
    If getExterno Then
            noEstado.appendChild salvador.criaNo("Externo")
    End If
    
    noEstado.appendChild atributos.toNoXML

    noEstado.appendChild Me.confPasta.toNoXML

    Set toNoXML = noEstado

End Function
