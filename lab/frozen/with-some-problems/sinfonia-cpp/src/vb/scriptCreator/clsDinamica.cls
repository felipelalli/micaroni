VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDinamica"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False

Option Explicit

Private id As String
Private nome As String

Private idInterno As Integer

Private eventosDisparadores As New clsEventosAss
Private eventosGerados As New clsEventosAss
Private eventosGeradosSenao As New clsEventosAss

Private condicao As New clsCondicao
Private habilitada As Boolean

Public Sub setId(pId As String)

    id = pId
    
    eventosDisparadores.setId "eventos_disparadores"
    eventosGerados.setId "eventos_gerados"
    eventosGeradosSenao.setId "eventos_gerados_senao"
    
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

Public Function getImagem() As String

    getImagem = "dinamica"

    If Not Me.getHabilitada Then
        getImagem = getImagem & "_desabilitada"
    End If
    
    If Me.quebrado Then
        getImagem = getImagem & "_quebrado"
    End If

End Function

Public Function setHabilitada(pHabilitada As Boolean)
    habilitada = pHabilitada
End Function

Public Function getHabilitada() As Boolean
    getHabilitada = habilitada
End Function


Public Function getCondicao() As clsCondicao
    Set getCondicao = condicao
End Function

Public Function quebrado() As Boolean
    quebrado = Me.getCondicao.quebrado Or _
               Me.getEventosDisparadores.quebrado Or _
               Me.getEventosGerados.quebrado Or _
               Me.getEventosGeradosSenao.quebrado
End Function


Public Function getEventosDisparadores() As clsEventosAss
    Set getEventosDisparadores = eventosDisparadores
End Function

Public Function getEventosGerados() As clsEventosAss
    Set getEventosGerados = eventosGerados
End Function

Public Function getEventosGeradosSenao() As clsEventosAss
    Set getEventosGeradosSenao = eventosGeradosSenao
End Function


Public Function carregaXML(noXml As clsNoXML)

    Dim dinamica As clsDinamica
    Dim grupoEventoAss As New clsGrupoXML
    Dim grupoDinamica As New clsGrupoXML
    
    grupoDinamica.carregaGrupoXML noXml, _
                                  Array("Id", "Nome", "Desabilitada"), _
                                  Array("Eventos_Disparadores", "Condição", "Eventos_Gerados", "Eventos_Gerados_Senão")
    
    Me.setNome grupoDinamica.getCampo("Nome").getValor
    
    Me.setId grupoDinamica.getCampo("Id").getValor
    
    Me.setHabilitada grupoDinamica.getCampo("Desabilitada").semValor
        
    Me.getEventosDisparadores.carregarXML grupoDinamica.getGrupo("Eventos_Disparadores").getNo
    
    Me.getCondicao.carregaXML grupoDinamica.getGrupo("Condição").getNo
    
    Me.getEventosGerados.carregarXML grupoDinamica.getGrupo("Eventos_Gerados").getNo
    
    Me.getEventosGeradosSenao.carregarXML grupoDinamica.getGrupo("Eventos_Gerados_Senão").getNo
    
End Function




Public Function toNoXML() As IXMLDOMNode

    Dim i As Integer
    Dim salvador As New clsSalvEstados
    Dim noDinamica As IXMLDOMNode
    Dim noEventos As IXMLDOMNode
    
    Set noDinamica = salvador.criaNo("Dinamica")
    
    noDinamica.appendChild salvador.criaNo("Id", getId)
    noDinamica.appendChild salvador.criaNo("Nome", getNome)
    
    If Not getHabilitada Then
    
        noDinamica.appendChild salvador.criaNo("Desabilitada")
    
    End If
    
    noDinamica.appendChild eventosDisparadores.toNoXML("Eventos_Disparadores")
        
    noDinamica.appendChild condicao.toNoXML
        
    noDinamica.appendChild eventosGerados.toNoXML("Eventos_Gerados")
        
    noDinamica.appendChild eventosGeradosSenao.toNoXML("Eventos_Gerados_Senão")
    
    Set toNoXML = noDinamica

End Function



Private Sub Class_Initialize()
    condicao.setTipoCondicao tcComparacao
    condicao.setOperador "="
    condicao.setId "Condicao_Principal"
    setHabilitada True
End Sub

