VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsSalvEstados"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private documentoXML As New MSXML2.DOMDocument

Public Sub salvarEstados(tvEstados As Nodes, sinfonia As clsSinfonia, arquivo As String)
    
    Dim tvNoPrincipal As Node
    Dim noPrincipal As IXMLDOMNode
    
    Set noPrincipal = criaNo("Sinfonia")
                
    Set tvNoPrincipal = tvEstados.Item(1)
        
    noPrincipal.appendChild criaNo("Nome", sinfonia.getNome)
        
    criaArvoreEstado tvNoPrincipal.Child, sinfonia, noPrincipal
    
    documentoXML.appendChild noPrincipal
    
    documentoXML.save arquivo
    
End Sub

Private Sub criaArvoreEstado(tvNo As Node, sinfonia As clsSinfonia, pai As IXMLDOMNode)

    If Not tvNo Is Nothing Then

        If tvNo.Tag = "Grupo" Then
        
            Dim grupo As clsGrupo
            Dim noGrupo As IXMLDOMNode
            
            Set grupo = sinfonia.getGrupos.getGrupo(tvNo.key)
                                        
            Set noGrupo = grupo.toNoXML
                    
            If tvNo.children > 0 Then
            
                criaArvoreEstado tvNo.Child, sinfonia, noGrupo
                
            End If
            
            pai.appendChild noGrupo
            
        ElseIf tvNo.Tag = "Estado" Then
        
            Dim estado As clsEstado
            Dim noEstado As IXMLDOMNode
            
            Set estado = sinfonia.getEstados.getEstado(tvNo.key)
                                    
            Set noEstado = estado.toNoXML
                                    
            If tvNo.children > 0 Then
            
                Dim noEventos As IXMLDOMNode
                
                Set noEventos = criaNo("Eventos")
            
                criaArvoreEstado tvNo.Child, sinfonia, noEventos
                
                noEstado.appendChild noEventos
                
            End If
                                    
            pai.appendChild noEstado
                    
        ElseIf tvNo.Tag = "Evento" Then
        
            Dim evento As clsEvento
            
            Set evento = sinfonia.getEventos.getEvento(tvNo.key)
            
            pai.appendChild evento.toNoXML
                    
        ElseIf tvNo.Tag = "Dinamica" Then
        
            Dim Dinamica As clsDinamica
            
            Set Dinamica = sinfonia.getDinamicas.getDinamica(tvNo.key)
            
            pai.appendChild Dinamica.toNoXML
                    
        End If
        
        criaArvoreEstado tvNo.Next, sinfonia, pai
        
    End If
End Sub


Public Function criaNo(nome As String, Optional valor As String = "nadinha") As IXMLDOMNode

    Dim novoNo As IXMLDOMNode
    
    Set novoNo = documentoXML.createElement(nome)
    
    If valor <> "nadinha" Then
        novoNo.Text = valor
    End If

    Set criaNo = novoNo

End Function
