VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsEvento"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private id As String
Private nome As String
Private externo As Boolean
Private idAtributo As String
Private acao As String
Private intermediario As Boolean
Private estadoRef As clsEstado
Private estadoDep As New clsEstadoDep

Public Sub setId(pId As String)
    id = pId
    estadoDep.setId getId & "_Estado_Dependente"
End Sub

Public Function getId() As String
    getId = id
End Function

Public Sub setNome(pNome As String)
    nome = pNome
End Sub

Public Function quebrado() As Boolean

    quebrado = estadoDep.quebrado
    
    If Not Me.getIntermediario And (estadoRef Is Nothing) Then
    
        quebrado = True
    
    End If
End Function

Public Function getImagem() As String
    If Me.getExterno Then
        getImagem = "evento_externo"
    Else
        getImagem = "evento"
    End If
    
    If Me.quebrado Then
        getImagem = getImagem & "_quebrado"
    End If
End Function

Public Function getNome(Optional idRelacionado As String = "__nadinha__") As String

    If idRelacionado = "__nadinha__" Then
    
        getNome = ""
        
    Else
        getNome = definicoes.vCaminhoCompleto(idRelacionado, Me.getId)
    End If

    If getIntermediario Then
    
        getNome = getNome & nome
        
    ElseIf estadoRef Is Nothing Then
    
        getNome = "Estado relacionado não encontrado!"
        
    Else

        Dim strModificacao As String
        
        If getIdAtributo = "__nadinha__" Then
            strModificacao = ""
        
        Else
            Dim nomeAtributo As String
            Dim strParametro As String
            
            If estadoDep.quantos = 0 Then
                strParametro = ""
            Else
                
                If Not estadoDep.quebrado Then
                                    
                    strParametro = estadoDep.emString(Me.getEstadoRef.getId)
                
                Else
                
                    strParametro = "Estado dependente não encontrado!"
                
                End If
                
            End If
                        
            nomeAtributo = estadoRef.getAtributos().getAtributoPeloId(getIdAtributo).getNome
            
            strModificacao = " (" & nomeAtributo & acao & strParametro & ")"
        End If
                
        getNome = estadoRef.getNome(idRelacionado) & strModificacao
        
        Exit Function
        
        getNome = estadoRef.getNome(idRelacionado)
        
    End If
    
    
    
End Function

Public Function getExterno() As Boolean
    getExterno = externo
End Function

Public Function setExterno(pExterno As Boolean)
    externo = pExterno
End Function


Public Sub setIdAtributo(pIdAtributo As String)
    idAtributo = pIdAtributo
End Sub

Public Function getIdAtributo() As String
    getIdAtributo = idAtributo
End Function

Public Sub setAcao(pAcao As String)
    acao = pAcao
End Sub

Public Function getAcao() As String
    getAcao = acao
End Function


Public Sub setIntermediario(pIntermediario As Boolean)
    intermediario = pIntermediario
End Sub

Public Function getIntermediario() As Boolean
    getIntermediario = intermediario
End Function

Public Sub setEstadoRef(pEstado As clsEstado)
    Set estadoRef = pEstado
End Sub

Public Function getEstadoRef() As clsEstado
    Set getEstadoRef = estadoRef
End Function

Public Function getEstadoDep() As clsEstadoDep
    Set getEstadoDep = estadoDep
End Function

Public Function carregaXML(noXml As clsNoXML)

    Dim evento As clsEvento
    Dim grupoEvento As New clsGrupoXML
    
    grupoEvento.carregaGrupoXML noXml, Array("Id", "Nome", "Intermediario", "Externo", "IdEstado", "IdAtributo", "Acao", "Parametro"), Array("Estado_Dependente")
        
    Me.setId grupoEvento.getCampo("Id").getValor
    
    Me.setIntermediario Not grupoEvento.getCampo("Intermediario").semValor
    Me.setExterno Not grupoEvento.getCampo("Externo").semValor
    
    If Me.getIntermediario Then
        
        Me.setNome grupoEvento.getCampo("Nome").getValor
        
    Else
    
        Me.setEstadoRef definicoes.sinfonia.getEstados.getEstado(grupoEvento.getCampo("IdEstado").getValor)
        Me.setIdAtributo grupoEvento.getCampo("IdAtributo").getValor
        Me.setAcao grupoEvento.getCampo("Acao").getValor
        
        Me.getEstadoDep.carregaXML grupoEvento.getGrupo("Estado_Dependente").getNo
        
    End If
    
End Function

Public Function toNoXML() As IXMLDOMNode

On Error Resume Next

    Dim salvador As New clsSalvEstados
    Dim noEvento As IXMLDOMNode
    
    Set noEvento = salvador.criaNo("Evento")
    
    noEvento.appendChild salvador.criaNo("Id", getId)
    noEvento.appendChild salvador.criaNo("Nome", getNome)
    
    If getExterno Then
        noEvento.appendChild salvador.criaNo("Externo")
    End If
    
    If getIntermediario Then
        noEvento.appendChild salvador.criaNo("Intermediario")
    Else
        noEvento.appendChild salvador.criaNo("IdEstado", getEstadoRef.getId)
        noEvento.appendChild salvador.criaNo("IdAtributo", getIdAtributo)
        noEvento.appendChild salvador.criaNo("Acao", getAcao)
        noEvento.appendChild estadoDep.toNoXML
    End If

    Set toNoXML = noEvento

End Function

Private Sub Class_Initialize()
    acao = "="
    idAtributo = "__nadinha__"
    Set estadoRef = Nothing
End Sub
