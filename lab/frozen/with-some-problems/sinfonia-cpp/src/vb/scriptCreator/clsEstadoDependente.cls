VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsEstadoDep"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit


Private idAtual As Integer
Private id As String
Private estadosCompostos As New Collection
Public confPasta As New clsConfPasta


Public Sub setId(pId As String)

    Dim i As Integer
    
    For i = 1 To quantos
    
        Dim idEstadoComposto As String
        Dim estadoComp As clsEstadoComposto
        
        Set estadoComp = Me.getEstadoCompostoPeloIndice(i)
        
        idEstadoComposto = Mid(estadoComp.getId, InStrRev(estadoComp.getId, "_") + 1)
        
        estadoComp.setId pId & "_" & idEstadoComposto
    
    Next
    
    id = pId
    
End Sub


Public Function getId() As String
    getId = id
End Function


Public Function add(Optional id As String = "__nadinha__") As clsEstadoComposto

    Dim estadoComposto As New clsEstadoComposto
    
    If id = "__nadinha__" Then
        estadoComposto.setId proximoId
    Else
        estadoComposto.setId id
    End If
    
    estadoComposto.setPai Me
    
    estadosCompostos.add estadoComposto

    Set add = estadoComposto

End Function

Public Sub remove(id As String)
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        estadosCompostos.remove indice
        
    End If
    
End Sub


Public Function quantos() As Integer

    quantos = estadosCompostos.Count
    
End Function



Public Function mudaOperador(id As String, novoValor As String)
    
    Dim i As Integer
            
    For i = 1 To quantos
    
        Dim estadoComposto As clsEstadoComposto
    
        Set estadoComposto = getEstadoCompostoPeloIndice(i)
        
        If estadoComposto.getId = id Then
            estadoComposto.setOperador novoValor
            Exit Function
        End If
    Next
    
End Function



Public Function getEstadoComposto(id As String) As clsEstadoComposto

    Dim indice As Integer
    
    indice = getIndice(id)

    If indice <> -1 Then
        Set getEstadoComposto = estadosCompostos.Item(indice)
    Else
        Set getEstadoComposto = Nothing
    End If
        
End Function



Public Function getEstadoCompostoPeloIndice(indice As Integer) As clsEstadoComposto

    If indice > 0 And indice <= quantos Then
    
        Set getEstadoCompostoPeloIndice = estadosCompostos.Item(indice)
        
    Else
    
        Set getEstadoCompostoPeloIndice = Nothing
        
    End If

End Function



Private Function getIndice(id As String) As Integer

    Dim i As Integer
    
    For i = 1 To quantos
    
        Dim estadoComposto As clsEstadoComposto
        
        Set estadoComposto = estadosCompostos.Item(i)
        
        If estadoComposto.getId = id Then
        
            getIndice = i
            Exit Function
            
        End If
    
    Next

    getIndice = -1

End Function

Private Sub Class_Initialize()
    idAtual = 0
    add
End Sub

Private Function proximoId() As String

    Dim novoId As String
    
    Do
        novoId = getId & "_" & idAtual
        idAtual = idAtual + 1
        
    Loop While getIndice(novoId) <> -1

    proximoId = novoId
    
End Function

Public Function getImagem() As String

    getImagem = "estado"
    
    If Me.quebrado Then
    
        getImagem = getImagem & "_quebrado"
        
    End If

End Function

Public Function quebrado() As Boolean
    
    Dim i As Integer
    
    For i = 1 To quantos
        If getEstadoCompostoPeloIndice(i).quebrado Then
            quebrado = True
            Exit Function
        End If
    Next
    
    quebrado = False
    
End Function



Public Function emString(idRelacionado As String) As String

    Dim i As Integer
    
    emString = ""
    
    For i = 1 To quantos
    
        Dim estadoComposto As clsEstadoComposto
        
        Set estadoComposto = getEstadoCompostoPeloIndice(i)
        
        emString = emString + estadoComposto.emString(idRelacionado)
        
        If i < quantos Then
            
            emString = emString + " " + estadoComposto.getOperador + " "
            
        End If
        
    Next

End Function

Public Function carregaXML(noXml As clsNoXML)

    Dim primeiraVez As Boolean
    Dim noEstadoComposto As clsNoXML
    Dim grupoEstadoDep As New clsGrupoXML
    
    grupoEstadoDep.carregaGrupoXML noXml, Array("Id"), Array("Estados_Compostos", "ConfPasta")
    
    Me.setId grupoEstadoDep.getCampo("Id").getValor
    
    Set noEstadoComposto = grupoEstadoDep.getGrupo("Estados_Compostos").getNo.primeiroFilho
    
    primeiraVez = True
    
    While Not noEstadoComposto Is Nothing
    
        
        Dim estadoComposto As clsEstadoComposto
                                
        If primeiraVez Then
        
            Set estadoComposto = Me.getEstadoCompostoPeloIndice(1)
            primeiraVez = False
            
        Else
        
            Set estadoComposto = Me.add("!!_nenhum_!!")
            
        End If
        
        estadoComposto.carregaXML noEstadoComposto
        
                
        Set noEstadoComposto = noEstadoComposto.proximoNo
    Wend
    
    Me.confPasta.carregaXML grupoEstadoDep.getGrupo("ConfPasta").getNo, False
    
End Function

Public Function toNoXML() As IXMLDOMNode
    
    Dim i As Integer
    Dim noEstadoDependente As IXMLDOMNode
    Dim noEstadosCompostos As IXMLDOMNode
    Dim salvador As New clsSalvEstados
    
    Set noEstadoDependente = salvador.criaNo("Estado_Dependente")

    noEstadoDependente.appendChild salvador.criaNo("Id", Me.getId)
    
    Set noEstadosCompostos = salvador.criaNo("Estados_Compostos")
    
    For i = 1 To quantos
    
        Dim estadoComposto As clsEstadoComposto
        
        Set estadoComposto = estadosCompostos.Item(i)
             
        noEstadosCompostos.appendChild estadoComposto.toNoXML
        
    Next

    noEstadoDependente.appendChild noEstadosCompostos
    
    noEstadoDependente.appendChild Me.confPasta.toNoXML
    
    Set toNoXML = noEstadoDependente

End Function
