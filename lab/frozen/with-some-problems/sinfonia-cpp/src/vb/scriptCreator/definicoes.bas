Attribute VB_Name = "definicoes"
Option Explicit

Public Type borda

    largura As Integer
    altura As Integer

End Type

Public Enum tipoNoEstados
    grupo = 1
    estado = 2
End Enum

Public Enum TipoNo
    tnEvento = 1
    tnEstado = 2
    tnDinamica = 3
    tnGrupo = 4
    tnAplicacao = 5
    tnNenhum = 6
End Enum

Public Enum TipoNoDinamica
    tnEventoDisparador = 1
    tnCondicao = 2
    tnEventoGerado = 3
    tnEventoGeradoSenao = 4
End Enum

Public arquivoAtual As String

Public sinfonia As clsSinfonia

Public configuracao As New clsConfiguracao

Public estadoAtual As clsEstado
Public noEstadoAtual As Node

Public atributoAtual As clsAtributo
Public noAtributoAtual As Node

Public grupoAtual As clsGrupo
Public noGrupoAtual As Node

Public eventoAtual As clsEvento
Public noEventoAtual As Node

Public dinamicaAtual As clsDinamica
Public noDinamicaAtual As Node

Public estadoDepAtual As clsEstadoDep

Public tipoNoAtual As TipoNo






Public Function vCaminhoCompleto(idRelacionado As String, idElemento As String) As String

On Error GoTo erro

    Dim nos As Nodes
    Dim keyIdRelacionado As String
    
    vCaminhoCompleto = ""
    
    Set nos = frmPrincipal.iaSinfonia.nosArvore

    If nos.Item(idRelacionado).Parent.key <> nos.Item(idElemento).Parent.key Then
    
        vCaminhoCompleto = caminhoCompleto(idElemento) & "."
        
    End If
    
    Exit Function

erro:

    vCaminhoCompleto = "ERRO AO MONTAR CAMINHO"

End Function


Public Function caminhoCompleto(id As String) As String

On Error GoTo fim

    Dim nomes As New Collection
    Dim noAtual As Node
    Dim i As Integer
    
    caminhoCompleto = ""
    
    Set noAtual = frmPrincipal.iaSinfonia.nosArvore.Item(id).Parent
    
    Do
        nomes.add noAtual.Text
    
        Set noAtual = noAtual.Parent
    
    Loop While (Not noAtual Is Nothing)
    
    For i = nomes.Count - 1 To 1 Step -1
    
        caminhoCompleto = caminhoCompleto & nomes.Item(i)
        
        If i > 1 Then
            caminhoCompleto = caminhoCompleto & "."
        End If
    Next
    Exit Function
fim:
    caminhoCompleto = "VERIFICAR MONTAR CAMINHO\"
    Debug.Print "ERRO AO MONTAR CAMINHO COMPLETO (KEY: " + id + ")"

End Function






Public Function inputValor(nomeDoCampo As String, default As String) As String

    inputValor = InputBox(nomeDoCampo, "Sinfonia ScriptCreator")
    
    If inputValor = "" Then
        inputValor = default
    End If

End Function

Public Function montaEstadoDependente(idPai As String, estado As clsEstadoDep, noPai As Node, iArvore As ItensEArvore) As String

    Dim noNovoPai As Node
    Dim nomeEstadoDep As String
    
    nomeEstadoDep = ""
    
    If estado.quantos > 1 Then
    
        Set noNovoPai = iArvore.nosArvore.add(noPai.key, tvwChild, estado.getId, "Estado Dependente", estado.getImagem)
        noNovoPai.Expanded = estado.confPasta.getAberto
        noNovoPai.Tag = "Estado Dependente"
        noNovoPai.Sorted = False
        
    Else
    
        Set noNovoPai = noPai
        
    End If


    Dim i As Integer
    
    For i = 1 To estado.quantos
    
        Dim noEstado As Node
        Dim estadoComposto As clsEstadoComposto
        
        Set estadoComposto = estado.getEstadoCompostoPeloIndice(i)
        
        If estadoComposto.getConstante Then
        
            Set noEstado = iArvore.nosArvore.add(noNovoPai.key, tvwChild, estadoComposto.getId, estadoComposto.getValor, estadoComposto.getImagem)
            noEstado.Tag = "Estado"
            noEstado.Sorted = False
            
            nomeEstadoDep = nomeEstadoDep + estadoComposto.getValor
        
        Else
            
            Set noEstado = iArvore.nosArvore.add(noNovoPai.key, tvwChild, estadoComposto.getId, estadoComposto.emString(idPai), estadoComposto.getImagem)
            noEstado.Tag = "Estado"
            noEstado.Sorted = False
            
            noEstado.Checked = estadoComposto.getValorAtual
            
            nomeEstadoDep = nomeEstadoDep + estadoComposto.emString(idPai)
            
        End If
        
    
        If i <> estado.quantos Then
            
            Dim noOperador As Node
            
            Set noOperador = iArvore.nosArvore.add(noNovoPai.key, tvwChild, estadoComposto.getId & "_Operador", estadoComposto.getOperador, "operador")
            noOperador.Tag = "Operador"
            noOperador.Sorted = False
            
            nomeEstadoDep = nomeEstadoDep + " " + estadoComposto.getOperador + " "
            
        End If
    
    Next
    
    If estado.quantos > 1 Then
        noNovoPai.Text = nomeEstadoDep
    End If

    montaEstadoDependente = nomeEstadoDep

End Function

Public Function getBorda(obj As Object, objRef As Object) As borda
    
    getBorda.largura = objRef.width - obj.left - obj.width
    getBorda.altura = objRef.height - obj.top - obj.height
    
End Function

Public Function aplicaBorda(obj As Object, pBorda As borda, objRef As Object)

    obj.width = objRef.width - obj.left - pBorda.largura
    obj.height = objRef.height - obj.top - pBorda.altura
    
End Function

