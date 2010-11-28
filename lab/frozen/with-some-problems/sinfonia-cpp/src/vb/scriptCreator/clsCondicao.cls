VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsCondicao"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public Enum TTipoCondicao
    tcComposta = 1
    tcComparacao = 2
End Enum

Private idAtual As Integer

Private id As String
Private tipoCondicao As TTipoCondicao
Private modificador As Boolean
Private operador As String
Private operadorBooleano As String
Private estado1 As New clsEstadoDep
Private estado2 As New clsEstadoDep
Private condicoes As New Collection
Public confPasta As New clsConfPasta

Private pai As clsCondicao

Public Function getImagem() As String

    Select Case Me.getTipoCondicao
    
        Case tcComparacao
            getImagem = "condicao_comparadora"
            
        Case tcComposta
            getImagem = "condicao_composta"
    End Select
    
    If Me.quebrado Then
        getImagem = getImagem & "_quebrado"
    End If

End Function

Public Function quebrado() As Boolean

    If tipoCondicao = tcComparacao Then
        quebrado = estado1.quebrado Or estado2.quebrado
        
    Else
    
        Dim i As Integer
    
        For i = 1 To quantasCondicoes
            If getCondicaoPeloIndice(i).quebrado Then
                quebrado = True
                Exit Function
            End If
        Next
        
        quebrado = False
        Exit Function
        
    End If
    
End Function

Public Sub setId(pId As String)

    id = pId
    
    estado1.setId getId & "_Estado1_"
    
    estado2.setId getId & "_Estado2_"
    
End Sub

Public Function getId() As String
    getId = id
End Function


Public Function setPai(condicao As clsCondicao)
    Set pai = condicao
End Function

Public Function getPai() As clsCondicao
    Set getPai = pai
End Function


Public Sub setTipoCondicao(pTipoCondicao As TTipoCondicao)
    tipoCondicao = pTipoCondicao
End Sub

Public Function getTipoCondicao() As TTipoCondicao
    getTipoCondicao = tipoCondicao
End Function



Public Sub setModificador(pModificador As Boolean)
    modificador = pModificador
End Sub

Public Function getModificador() As Boolean
    getModificador = modificador
End Function



Public Sub setOperador(pOperador As String)
    operador = pOperador
End Sub

Public Function getOperador() As String
    getOperador = operador
End Function



Public Sub setOperadorBooleano(pOperadorBooleano As String)
    operadorBooleano = pOperadorBooleano
End Sub

Public Function getOperadorBooleano() As String
    getOperadorBooleano = operadorBooleano
End Function




Public Function getEstado1() As clsEstadoDep
    Set getEstado1 = estado1
End Function

Public Function getEstado2() As clsEstadoDep
    Set getEstado2 = estado2
End Function



Public Function addCondicao(Optional id As String = "__nadinha__") As clsCondicao

    Dim condicao As New clsCondicao
    
    If id = "__nadinha__" Then
        condicao.setId proximoId
    Else
        condicao.setId id
    End If
    
    condicao.setPai Me
    
    condicoes.add condicao
    
    Set addCondicao = condicao
    
End Function


Public Sub remove(id As String)
    
    Dim indice As Integer
    
    indice = getIndice(id)
    
    If indice <> -1 Then
    
        condicoes.remove indice
        
    End If
    
End Sub

Public Function quantasCondicoes() As Integer

    quantasCondicoes = condicoes.Count

End Function



Public Function getCondicao(id As String) As clsCondicao
    
    If id = Me.getId Then
    
        Set getCondicao = Me
        Exit Function
        
    Else
        Dim indice As Integer
        
        indice = getIndice(id)
    
        If indice <> -1 Then
        
            Set getCondicao = getCondicaoPeloIndice(indice)
            Exit Function
            
        Else
    
            Dim i As Integer
            
            For i = 1 To quantasCondicoes
            
                Set getCondicao = getCondicaoPeloIndice(i).getCondicao(id)
                
                If Not getCondicao Is Nothing Then
                    Exit Function
                End If
            Next
        End If
    End If
    
    Set getCondicao = Nothing
    
End Function


Public Function getEstadoComposto(id As String) As clsEstadoComposto
    
    Set getEstadoComposto = estado1.getEstadoComposto(id)
    
    If getEstadoComposto Is Nothing Then
    
        Set getEstadoComposto = estado2.getEstadoComposto(id)
        
        If getEstadoComposto Is Nothing Then
                                        
            Dim i As Integer
            
            For i = 1 To quantasCondicoes
            
                Dim condicao As clsCondicao
            
                Set condicao = getCondicaoPeloIndice(i)
                
                Set getEstadoComposto = condicao.getEstadoComposto(id)
                
                If Not getEstadoComposto Is Nothing Then
                    Exit Function
                End If
            Next
        End If
    End If
    
End Function

Public Function mudaOperador(id As String, novoValor As String)
    
    Dim i As Integer
    
    If getId = id Then
        
        Select Case tipoCondicao
        
            Case tcComposta
                operadorBooleano = novoValor
                
            Case tcComparacao
                operador = novoValor
                
        End Select
        
        Exit Function
    
    End If
    
    estado1.mudaOperador id, novoValor
    estado2.mudaOperador id, novoValor
            
    For i = 1 To quantasCondicoes
    
        Dim condicao As clsCondicao
    
        Set condicao = getCondicaoPeloIndice(i)
        
        condicao.mudaOperador id, novoValor
    Next
    
End Function


Public Function getCondicaoPeloIndice(indice As Integer) As clsCondicao

    If indice > 0 And indice <= quantasCondicoes Then
    
        Set getCondicaoPeloIndice = condicoes.Item(indice)
        
    Else
    
        Set getCondicaoPeloIndice = Nothing
        
    End If

End Function



Private Function getIndice(id As String) As Integer

    Dim i As Integer
    
    For i = 1 To quantasCondicoes
    
        Dim condicao As clsCondicao
        
        Set condicao = condicoes.Item(i)
        
        If condicao.getId = id Then
        
            getIndice = i
            Exit Function
            
        End If
    
    Next

    getIndice = -1

End Function

Public Function procuraEstadoComposto(id As String) As clsEstadoComposto

    Set procuraEstadoComposto = estado1.getEstadoComposto(id)

    If procuraEstadoComposto Is Nothing Then
    
        Set procuraEstadoComposto = estado2.getEstadoComposto(id)

        If procuraEstadoComposto Is Nothing Then
                    
            Dim i As Integer
    
            For i = 1 To quantasCondicoes
            
                Dim condicao As clsCondicao
                
                Set condicao = getCondicaoPeloIndice(i)
                
                Set procuraEstadoComposto = condicao.procuraEstadoComposto(id)
                
                If Not procuraEstadoComposto Is Nothing Then
                                    
                    Exit Function
                    
                End If
            
            Next
        End If
    End If

End Function

Public Function procuraEstadoDependente(id As String) As clsEstadoDep

    Dim estadoComposto As clsEstadoComposto

    If id = estado1.getId Then
    
        Set procuraEstadoDependente = estado1
        Exit Function
        
    ElseIf id = estado2.getId Then
    
        Set procuraEstadoDependente = estado2
        Exit Function
        
    Else
        Dim i As Integer
    
        For i = 1 To quantasCondicoes
        
            Dim condicao As clsCondicao
            
            Set condicao = getCondicaoPeloIndice(i)
            
            Set procuraEstadoDependente = condicao.procuraEstadoDependente(id)
            
            If Not procuraEstadoDependente Is Nothing Then
                                
                Exit Function
                
            End If
        
        Next
    End If
        
     Set procuraEstadoDependente = Nothing

End Function


Private Sub Class_Initialize()
            
    idAtual = 0
            
    setOperador "="
    setOperadorBooleano "And"
           
    setTipoCondicao tcComparacao
           
End Sub

Private Function proximoId() As String

    Dim novoId As String
    
    Do
        novoId = getId & "_" & idAtual
        idAtual = idAtual + 1
        
    Loop While getIndice(novoId) <> -1

    proximoId = novoId

End Function

Public Function carregaXML(noXml As clsNoXML)

    Dim grupoCondicao As New clsGrupoXML
        
    grupoCondicao.carregaGrupoXML noXml, Array("Id", "Tipo_Condição", "Modificador", "Operador", "Operador_Booleano"), _
                                         Array("Estados_Dependentes", "Condições", "ConfPasta")
                                             
    Me.setId grupoCondicao.getCampo("Id").getValor
    Me.setModificador Not grupoCondicao.getCampo("Modificador").semValor
                                             
    If grupoCondicao.getCampo("Tipo_Condição").getValor = "Comparação" Then
    
        Dim noEstadoDependente As clsNoXML
    
        Me.setTipoCondicao tcComparacao
        Me.setOperador grupoCondicao.getCampo("Operador").getValor
        
        Set noEstadoDependente = grupoCondicao.getGrupo("Estados_Dependentes").getNo.primeiroFilho
        
        Me.getEstado1.carregaXML noEstadoDependente
        Me.getEstado2.carregaXML noEstadoDependente.proximoNo
        Me.confPasta.carregaXML grupoCondicao.getGrupo("ConfPasta").getNo, False
        
    
    ElseIf grupoCondicao.getCampo("Tipo_Condição").getValor = "Composta" Then
    
        Dim noCondicaoComposta As clsNoXML
    
        Me.setTipoCondicao tcComposta
        Me.setOperadorBooleano grupoCondicao.getCampo("Operador_Booleano").getValor
        
        Set noCondicaoComposta = grupoCondicao.getGrupo("Condições").getNo.primeiroFilho
        
        While Not noCondicaoComposta Is Nothing
        
            Me.addCondicao("!!_nenhum_!!").carregaXML noCondicaoComposta
        
            Set noCondicaoComposta = noCondicaoComposta.proximoNo
        Wend
        
        Me.confPasta.carregaXML grupoCondicao.getGrupo("ConfPasta").getNo, True
    End If
    
End Function


Public Function toNoXML() As IXMLDOMNode
        
    Dim noCondicao As IXMLDOMNode
    Dim salvador As New clsSalvEstados
    
    Set noCondicao = salvador.criaNo("Condição")

    noCondicao.appendChild salvador.criaNo("Id", Me.getId)
    
    If getModificador Then
        noCondicao.appendChild salvador.criaNo("Modificador")
    End If
    
    
    Select Case Me.getTipoCondicao
    
    
        Case tcComparacao
        
            Dim noEstadosDependentes As IXMLDOMNode
            
            noCondicao.appendChild salvador.criaNo("Tipo_Condição", "Comparação")
            noCondicao.appendChild salvador.criaNo("Operador", getOperador)
            
            Set noEstadosDependentes = salvador.criaNo("Estados_Dependentes")
                                    
            noEstadosDependentes.appendChild estado1.toNoXML
            noEstadosDependentes.appendChild estado2.toNoXML
            
            noCondicao.appendChild noEstadosDependentes
            
            
        
        Case tcComposta
        
            Dim i As Integer
            Dim noCondicoes As IXMLDOMNode
            
            noCondicao.appendChild salvador.criaNo("Tipo_Condição", "Composta")
            noCondicao.appendChild salvador.criaNo("Operador_Booleano", getOperadorBooleano)
            
            Set noCondicoes = salvador.criaNo("Condições")
            
            For i = 1 To quantasCondicoes
            
                Dim condicao As clsCondicao
                
                Set condicao = condicoes.Item(i)
                
                noCondicoes.appendChild condicao.toNoXML
            
            Next
            
            noCondicao.appendChild noCondicoes
        
    End Select
    
    noCondicao.appendChild Me.confPasta.toNoXML
    
    Set toNoXML = noCondicao

End Function
