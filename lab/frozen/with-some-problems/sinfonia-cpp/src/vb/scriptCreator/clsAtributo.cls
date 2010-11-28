VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsAtributo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private id As String
Private nome As String
Private parametros As New clsParametros
Private principal As Boolean
Private somenteEsses As Boolean

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

Public Function getSomenteEsses() As Boolean
    getSomenteEsses = somenteEsses
End Function

Public Function setSomenteEsses(psomenteEsses As Boolean)
    somenteEsses = psomenteEsses
End Function


Public Function getParametros() As clsParametros
    Set getParametros = parametros
End Function

Public Sub setPrincipal(pPrincipal As Boolean)
    principal = pPrincipal
End Sub

Public Function getPrincipal() As Boolean
    getPrincipal = principal
End Function


Public Function emString() As String

    Dim i As Integer

    emString = Me.getNome
        
    For i = 1 To Me.getParametros.quantos
    
        Dim parametro As clsParametro
        
        Set parametro = Me.getParametros.getParametro(i)
        
        If parametro.getValorInicial Then
            emString = emString + " (" + parametro.getNome + ")"
            Exit For
        End If
    Next
End Function

Public Function copia(atributo As clsAtributo)

    atributo.setNome Me.getNome
    atributo.setPrincipal Me.getPrincipal
    atributo.setSomenteEsses Me.getSomenteEsses
    
    Me.getParametros.copia atributo.getParametros

End Function

Public Function carregaXML(noXml As clsNoXML)

    Dim grupoAtributo As New clsGrupoXML
    
    grupoAtributo.carregaGrupoXML noXml, Array("Id", "Nome", "Principal", "SomenteEsses"), Array("Parametros")
    
    Me.setNome grupoAtributo.getCampo("Nome").getValor
    Me.setId grupoAtributo.getCampo("Id").getValor
    Me.setPrincipal Not grupoAtributo.getCampo("Principal").semValor
            
    Me.setSomenteEsses Not grupoAtributo.getCampo("SomenteEsses").semValor
    
    If Not grupoAtributo.getGrupo("Parametros").getNo Is Nothing Then
    
        Me.getParametros.carregaXML grupoAtributo.getGrupo("Parametros").getNo
    
    End If
    
End Function

Public Function toNoXML() As IXMLDOMNode

    Dim salvador As New clsSalvEstados
    Dim noAtributo As IXMLDOMNode
    
    Set noAtributo = salvador.criaNo("Atributo")
    
    noAtributo.appendChild salvador.criaNo("Id", getId)
    noAtributo.appendChild salvador.criaNo("Nome", getNome)
    
    If Me.getSomenteEsses Then
        noAtributo.appendChild salvador.criaNo("SomenteEsses")
    End If
    
    If getPrincipal Then
        noAtributo.appendChild salvador.criaNo("Principal")
    End If
    
    noAtributo.appendChild parametros.toNoXML

    Set toNoXML = noAtributo

End Function
