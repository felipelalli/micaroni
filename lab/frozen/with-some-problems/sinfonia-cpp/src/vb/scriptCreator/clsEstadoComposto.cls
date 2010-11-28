VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsEstadoComposto"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private pai As clsEstadoDep
Private id As String
Private idEstado As String
Private idAtributo As String
Private idParametro As String
Private valor As String
Private constante As Boolean
Private operador As String
Private valorAtual As Boolean


Public Sub setPai(estadoPai As clsEstadoDep)
    Set pai = estadoPai
End Sub

Public Function getPai() As clsEstadoDep
    Set getPai = pai
End Function


Public Sub setId(pId As String)
    id = pId
End Sub

Public Function getId() As String
    getId = id
End Function


Public Sub setValor(pValor As String)
    valor = pValor
End Sub

Public Function getValor() As String
    getValor = valor
End Function

Public Sub setValorAtual(pValorAtual As String)
    valorAtual = pValorAtual
End Sub

Public Function getValorAtual() As String
    getValorAtual = valorAtual
End Function


Public Sub setConstante(pConstante As Boolean)
    constante = pConstante
End Sub

Public Function getConstante() As Boolean
    getConstante = constante
End Function


Public Sub setOperador(pOperador As String)
    operador = pOperador
End Sub

Public Function getOperador() As String
    getOperador = operador
End Function


Public Sub setIdEstado(pIdEstado As String)
    idEstado = pIdEstado
End Sub

Public Function getIdEstado() As String
    getIdEstado = idEstado
End Function


Public Sub setIdAtributo(pIdAtributo As String)
    idAtributo = pIdAtributo
End Sub

Public Function getIdAtributo() As String
    getIdAtributo = idAtributo
End Function

Public Sub setIdParametro(pIdParametro As String)
    idParametro = pIdParametro
End Sub

Public Function getIdParametro() As String
    getIdParametro = idParametro
End Function

Private Sub Class_Initialize()

    idEstado = "__nadinha__"
    idAtributo = "__nadinha__"
    idParametro = "__nadinha__"
    valor = ""
    operador = "+"
    constante = True
    valorAtual = False
    
End Sub

Public Function getImagem() As String

    getImagem = "estado"

    If Me.quebrado Then
    
        getImagem = getImagem & "_quebrado"
        
    End If

End Function

Public Function quebrado() As Boolean

    quebrado = False
            
    If Not Me.getConstante Then
        
        Dim estado As clsEstado
        Dim atributo As clsAtributo
        Dim parametro As clsParametro
        
        If Me.getIdEstado <> "__nadinha__" Then
        
            Set estado = definicoes.sinfonia.getEstados.getEstado(Me.getIdEstado)
            
            If estado Is Nothing Then
                
                quebrado = True
            
            ElseIf Me.getIdAtributo <> "__nadinha__" Then
            
                Set atributo = estado.getAtributos.getAtributoPeloId(Me.getIdAtributo)
                
                If atributo Is Nothing Then
                
                    quebrado = True
                    
                ElseIf Me.getIdParametro <> "__nadinha__" Then
                
                    Set parametro = atributo.getParametros.getParametroPeloId(Me.getIdParametro)
                    
                    If parametro Is Nothing Then
                    
                        quebrado = True
                    
                    End If
                End If
            End If
        End If
    End If
                
End Function

Public Function emString(idRelacionado As String) As String

    emString = ""

    If Me.getConstante Then
    
        emString = Me.getValor
    
    Else
        If Me.getIdEstado <> "__nadinha__" Then
                    
            Dim estado As clsEstado
            
            Set estado = definicoes.sinfonia.getEstados.getEstado(Me.getIdEstado)
        
            If estado Is Nothing Then
            
                emString = "Estado não encontrado! (" & Me.getIdEstado & ")"
            
            Else
        
                emString = estado.getNome(idRelacionado)
                
                If Me.getIdAtributo <> "__nadinha__" Then
                
                    Dim atributo As clsAtributo
                    
                    Set atributo = estado.getAtributos.getAtributoPeloId(Me.getIdAtributo)
                    
                    If atributo Is Nothing Then
                    
                        emString = emString + "." + "Atributo não encontrado! (" & Me.getIdAtributo & ")"
                    
                    Else
                        emString = emString + "." + atributo.getNome
                        
                        If Me.getIdParametro <> "__nadinha__" Then
                        
                            Dim parametro As clsParametro
                            
                            Set parametro = atributo.getParametros.getParametroPeloId(Me.getIdParametro)
                            
                            If parametro Is Nothing Then
                            
                                emString = emString + "( Parametro não encontrado! (" & Me.getIdParametro & "))"
                            
                            Else
                                emString = emString + "(" + parametro.getNome + ")"
                            End If
                        End If
                    End If
                End If
            End If
        End If
    End If

End Function

Public Function carregaXML(noXml As clsNoXML)

    Dim grupoEstadoComposto As New clsGrupoXML
    
    grupoEstadoComposto.carregaGrupoXML noXml, Array("Id", "Operador", "Constante", "Valor", "ValorAtual", "IdEstado", "IdAtributo", "IdParametro")

    Me.setId grupoEstadoComposto.getCampo("Id").getValor
    Me.setOperador grupoEstadoComposto.getCampo("Operador").getValor
    Me.setConstante Not grupoEstadoComposto.getCampo("Constante").semValor
    Me.setValor grupoEstadoComposto.getCampo("Valor").getValor
    Me.setIdEstado grupoEstadoComposto.getCampo("IdEstado").getValor
    Me.setIdAtributo grupoEstadoComposto.getCampo("IdAtributo").getValor
    Me.setIdParametro grupoEstadoComposto.getCampo("IdParametro").getValor
    Me.setValorAtual Not grupoEstadoComposto.getCampo("ValorAtual").semValor

End Function


Public Function toNoXML() As IXMLDOMNode
        
    Dim noEstadoComposto As IXMLDOMNode
    Dim salvador As New clsSalvEstados
    
    Set noEstadoComposto = salvador.criaNo("Estado_Composto")

    noEstadoComposto.appendChild salvador.criaNo("Id", Me.getId)
    noEstadoComposto.appendChild salvador.criaNo("Operador", Me.getOperador)

    If Me.getConstante Then
    
        noEstadoComposto.appendChild salvador.criaNo("Constante")
        noEstadoComposto.appendChild salvador.criaNo("Valor", Me.getValor)
        
    Else
    
        noEstadoComposto.appendChild salvador.criaNo("IdEstado", Me.getIdEstado)
        noEstadoComposto.appendChild salvador.criaNo("IdAtributo", Me.getIdAtributo)
        noEstadoComposto.appendChild salvador.criaNo("IdParametro", Me.getIdParametro)
        
        If getValorAtual Then
        
            noEstadoComposto.appendChild salvador.criaNo("ValorAtual")
            
        End If
    End If
    
    Set toNoXML = noEstadoComposto

End Function
