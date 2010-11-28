VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsCarregEstados"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private sinfonia As clsSinfonia
Private arvore As Nodes

Public Function carregaEstados(pArvore As Nodes, pSinfonia As clsSinfonia, arquivo As String) As Boolean

    Dim arquivoXML As New clsArquivoXML
    
    If Not arquivoXML.carregaArquivo(arquivo) Then

        carregaEstados = False
        
    Else
        
        Dim tvNoSinfonia As Node
        
        Set definicoes.sinfonia = pSinfonia
        Set arvore = pArvore
        
        arvore.Clear
        
        definicoes.sinfonia.carregaXML arquivoXML.noPrincipal
        
        Set tvNoSinfonia = arvore.add(, , "Principal", definicoes.sinfonia.getNome, "aplicacao")
        tvNoSinfonia.Expanded = True
        tvNoSinfonia.Tag = "Principal"
        tvNoSinfonia.Sorted = True
            
        percorreGrupos tvNoSinfonia, arquivoXML.noPrincipal.primeiroFilho
    
        frmPrincipal.atualizaIcones
    
        carregaEstados = True
    
    End If

End Function

Private Sub percorreGrupos(pai As Node, no As clsNoXML)

    If Not no Is Nothing Then

        Dim id As String
        Dim grupoXML As New clsGrupoXML

        grupoXML.carregaGrupoXML no, Array("Id"), Array("Eventos")

        id = grupoXML.getCampo("Id").getValor

        If no.nome = "Grupo" Then
                                
            Dim grupo As clsGrupo
            Dim tvNovoGrupo As Node
            
            Set grupo = definicoes.sinfonia.getGrupos.getGrupo(id)
            
            Set tvNovoGrupo = arvore.add(pai, tvwChild, grupo.getId, grupo.getNome, grupo.getImagem)
            tvNovoGrupo.ExpandedImage = "grupo_aberto"
            tvNovoGrupo.Expanded = grupo.confPasta.getAberto
            tvNovoGrupo.Tag = "Grupo"
            tvNovoGrupo.Sorted = True
                                                
            percorreGrupos tvNovoGrupo, no.primeiroFilho
            
            
            
        ElseIf no.nome = "Evento" Then
                    
            Dim evento As clsEvento
            Dim tvNoEvento As Node
        
            Set evento = definicoes.sinfonia.getEventos.getEvento(id)
        
            Set tvNoEvento = arvore.add(pai, tvwChild, evento.getId, evento.getNome, evento.getImagem)
            tvNoEvento.Tag = "Evento"
            tvNoEvento.Sorted = True
            
            
            
        ElseIf no.nome = "Dinamica" Then
            
            Dim dinamica As clsDinamica
            Dim tvNoDinamica As Node
            Dim imagem As String
            
            Set dinamica = definicoes.sinfonia.getDinamicas.getDinamica(id)
                    
            Set tvNoDinamica = arvore.add(pai, tvwChild, dinamica.getId, dinamica.getNome, dinamica.getImagem)
            tvNoDinamica.Expanded = False
            tvNoDinamica.Tag = "Dinamica"
            tvNoDinamica.Sorted = True
            
                       
            
        ElseIf no.nome = "Estado" Then
                        
            Dim estado As clsEstado
            Dim tvNoEstado As Node
                       
            Set estado = definicoes.sinfonia.getEstados.getEstado(id)
            
            Set tvNoEstado = arvore.add(pai, tvwChild, estado.getId, estado.getNome, estado.getImagem)
            tvNoEstado.Expanded = estado.confPasta.getAberto
            tvNoEstado.Tag = "Estado"
            tvNoEstado.Sorted = True
                                
            If Not grupoXML.getGrupo("Eventos").getNo Is Nothing Then
            
                percorreGrupos tvNoEstado, grupoXML.getGrupo("Eventos").getNo.primeiroFilho
            
            End If
                                                          
        End If
        
        percorreGrupos pai, no.proximoNo
        
    End If
End Sub

