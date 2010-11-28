VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDinamicaNaTela"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Type tPonto
    X As Long
    Y As Long
End Type

Private distanciaHorizontal As Long
Private distanciaVertical As Long


Private raio As Long

Private max_niveis As Long

Private key As String
Private X As Long
Private Y As Long
Private nivel As Long
Private zoom As Double

Private posDesenhado As tPonto
Private zoomDesenhado As Double

Private quantasAntes As Integer
Private quantasDepois As Integer

Private dinamicasAntes As clsDinNaTela
Private dinamicasDepois As clsDinNaTela

Public Function carrega(pkey As String, pnivel As Long, pzoom As Double, pMAX_NIVEIS As Long) As Integer
        
    Dim maxNivel As Long
    Dim nivelComp As Long
        
    maxNivel = Abs(pnivel)
    
    max_niveis = pMAX_NIVEIS
    
    key = pkey
    nivel = pnivel
    zoom = pzoom
    
    Set dinamicasAntes = New clsDinNaTela
    Set dinamicasDepois = New clsDinNaTela
        

    If Abs(nivel) <= (max_niveis - 1) Then
        
        Dim i As Long
        Dim dinamicas As clsDinamicas
        Dim dinamicasQueDisparam As Collection
        Dim dinamicasQueRecebem As Collection
        Dim dinamica As clsDinamica
        Dim novaDinamica As clsDinamicaNaTela
        
        Set dinamicas = definicoes.sinfonia.getDinamicas

        dinamicas.carregaDinamicasRelacionadas key
        Set dinamicasQueDisparam = dinamicas.getDinamicasQueDisparam
        Set dinamicasQueRecebem = dinamicas.getDinamicasQueRecebem
        
        quantasAntes = dinamicasQueDisparam.Count
        quantasDepois = dinamicasQueRecebem.Count
       
        If nivel <= 0 Then
            For i = 1 To dinamicasQueDisparam.Count
        
                Set novaDinamica = New clsDinamicaNaTela
                Set dinamica = dinamicasQueDisparam.Item(i)
                
                nivelComp = novaDinamica.carrega(dinamica.getId, _
                                                 nivel - 1, _
                                                 zoom * 0.9, _
                                                 max_niveis)
                  
                If nivelComp > maxNivel Then
                    maxNivel = nivelComp
                End If
                  
                dinamicasAntes.addDinamica novaDinamica
            Next
        End If
        
        
        If nivel >= 0 Then
            For i = 1 To dinamicasQueRecebem.Count
        
                Set novaDinamica = New clsDinamicaNaTela
                Set dinamica = dinamicasQueRecebem.Item(i)
        
                nivelComp = novaDinamica.carrega(dinamica.getId, _
                                                 nivel + 1, _
                                                 zoom * 0.9, _
                                                 max_niveis)
    
                If nivelComp > maxNivel Then
                    maxNivel = nivelComp
                End If
    
                dinamicasDepois.addDinamica novaDinamica
            Next
        End If
        
    End If

    carrega = maxNivel

End Function


Public Function atualizaPosicao(px As Long, py As Long)

    X = px
    Y = py

End Function

Public Function desenha(pb As PictureBox, px As Long, py As Long, pzoom As Double)

    If key <> "" Then

        Dim nome As String
        Dim i As Integer
        Dim yInicial As Long
        Dim novoX As Long
        Dim novoY As Long
        Dim ponto As tPonto
        Dim dinamica As clsDinamica
        Dim altura As Long
        Dim distancia As Long
        Dim quantos As Long
        Dim raioTotal As Double
        
        zoomDesenhado = zoom * pzoom

        posDesenhado = posAbsoluta(pb, X + px, Y + py)
                        
        
        If nivel <= 0 Then
                
            yInicial = Y - (((distanciaVertical * zoomDesenhado) * (dinamicasAntes.quantas - 1)) / 2)
        
            For i = 1 To dinamicasAntes.quantas
            
                novoX = X - (distanciaHorizontal * zoomDesenhado)
                novoY = yInicial + ((distanciaVertical * zoomDesenhado) * (i - 1))
            
                dinamicasAntes.getDinamica(i).atualizaPosicao novoX, novoY
            
                pb.ForeColor = &HFF8080
                pb.DrawWidth = 1
                ponto = posAbsoluta(pb, novoX + px, novoY + py)
                pb.Line (posDesenhado.X, posDesenhado.Y)-(ponto.X, ponto.Y)
            
                dinamicasAntes.getDinamica(i).desenha pb, px, py, pzoom
            Next
        End If
        
        
        If nivel >= 0 Then
        
            yInicial = Y - (((distanciaVertical * zoomDesenhado) * (dinamicasDepois.quantas - 1)) / 2)
            
            For i = 1 To dinamicasDepois.quantas
            
                novoX = X + (distanciaHorizontal * zoomDesenhado)
                novoY = yInicial + ((distanciaVertical * zoomDesenhado) * (i - 1))
            
                dinamicasDepois.getDinamica(i).atualizaPosicao novoX, novoY
            
                pb.ForeColor = &HFF8080
                pb.DrawWidth = 1
                ponto = posAbsoluta(pb, novoX + px, novoY + py)
                pb.Line (posDesenhado.X, posDesenhado.Y)-(ponto.X, ponto.Y)
            
                dinamicasDepois.getDinamica(i).desenha pb, px, py, pzoom
            Next
        End If


        If nivel = 0 Then
        
            pb.FillColor = &HFF00&
            pb.FillStyle = vbDiagonalCross
            pb.DrawStyle = vbSolid
            pb.ForeColor = &HFF00&
            pb.Circle (posDesenhado.X, posDesenhado.Y), (raio * 1.25) * zoomDesenhado
            
            raioTotal = (raio * 1.25) * zoomDesenhado
            
        Else
        
            raioTotal = raio * zoomDesenhado
            
        End If
        
        Dim total As Integer
        
                        
        pb.FillStyle = vbFSSolid
        pb.DrawWidth = 1
        pb.DrawStyle = vbSolid
                                            
        total = quantasAntes + quantasDepois
                        
        If total = 0 Then
        
            pb.FillColor = RGB(0, 200, 0)
            pb.Circle (posDesenhado.X, posDesenhado.Y), raio * zoomDesenhado, RGB(0, 255, 0)
            
        Else
                        
            If quantasAntes = 0 Then
            
                pb.FillColor = RGB(200, 0, 0)
                pb.Circle (posDesenhado.X, posDesenhado.Y), raio * zoomDesenhado, RGB(255, 0, 0)
                
            ElseIf quantasDepois = 0 Then
                            
                pb.FillColor = RGB(0, 0, 200)
                pb.Circle (posDesenhado.X, posDesenhado.Y), raio * zoomDesenhado, RGB(0, 0, 255)
                            
            Else
                            
                Dim anguloDisp As Double
                Dim anguloRec As Double
                Dim anguloInicial As Double
                Dim anguloFinal As Double
                            
                anguloDisp = 360 * (quantasAntes / total)
                anguloRec = 360 * (quantasDepois / total)
                        
                anguloInicial = 360 - (anguloRec / 2)
                anguloFinal = anguloRec / 2
                pb.FillColor = RGB(200, 0, 0)
                pb.Circle (posDesenhado.X, posDesenhado.Y), raio * zoomDesenhado, RGB(255, 0, 0), anguloInicial * (-3.14 / 180), anguloFinal * (-3.14 / 180)
            
                anguloInicial = 0 + (anguloRec / 2)
                anguloFinal = 360 - (anguloRec / 2)
                pb.FillColor = RGB(0, 0, 200)
                pb.Circle (posDesenhado.X, posDesenhado.Y), raio * zoomDesenhado, RGB(0, 0, 255), anguloInicial * (-3.14 / 180), anguloFinal * (-3.14 / 180)
    
            End If
        End If
        



        Set dinamica = definicoes.sinfonia.getDinamicas.getDinamica(key)

        Dim eventosTotal As Integer
        Dim maxY As Long
        Dim mimY As Long
        
        maxY = -1
        mimY = -1
        
        altura = 300 * zoomDesenhado
        distancia = 100 * zoomDesenhado
        
        If nivel >= 0 Then

            eventosTotal = dinamica.getEventosDisparadores.quantosEventos

            yInicial = posDesenhado.Y - (((eventosTotal - 1) * (altura + distancia)) / 2)

            
            mimY = yInicial - altura


            For i = 1 To dinamica.getEventosDisparadores.quantosEventos

                novoY = yInicial + ((altura + distancia) * (i - 1))
                novoX = posDesenhado.X - (raio * zoomDesenhado) - (altura + distancia)
                desenhaTriangulo pb, novoX, novoY, altura, zoomDesenhado, RGB(255, 255, 0), RGB(204, 199, 0)

                If novoY > maxY Then
                    maxY = novoY + altura
                End If

                nome = dinamica.getEventosDisparadores.getEvento(i).emString(dinamica.getId)

                pb.FontSize = 8.25
                pb.FontBold = True
                
                nome = limitaNome(pb, nome, ((distanciaHorizontal * zoomDesenhado) / 2) - (raio * zoomDesenhado) - (altura + (distancia * 4)))
                
                pb.ForeColor = RGB(255, 255, 255)
                pb.CurrentX = novoX - (altura + distancia) - pb.TextWidth(nome)
                pb.CurrentY = novoY - (pb.TextHeight(nome) / 2)
                pb.Print nome
            Next
        End If
        
        If nivel <= 0 Then

            eventosTotal = dinamica.getEventosGerados.quantosEventos + dinamica.getEventosGeradosSenao.quantosEventos

            quantos = 1


            yInicial = posDesenhado.Y - (((eventosTotal - 1) * (altura + distancia)) / 2)

            If yInicial < mimY Then
                mimY = yInicial - altura
            End If

            For i = 1 To dinamica.getEventosGerados.quantosEventos

                novoY = yInicial + ((altura + distancia) * (quantos - 1))
                novoX = posDesenhado.X + (raio * zoomDesenhado) + (altura + distancia)
                desenhaTriangulo pb, novoX, novoY, altura, zoomDesenhado, RGB(255, 255, 0), RGB(204, 40, 0)

                If novoY > maxY Then
                    maxY = novoY + altura
                End If

                nome = dinamica.getEventosGerados.getEvento(i).emString(dinamica.getId)
                
                pb.FontSize = 8.25
                pb.FontBold = True
                
                nome = limitaNome(pb, nome, ((distanciaHorizontal * zoomDesenhado) / 2) - (raio * zoomDesenhado) - (altura + (distancia * 4)))
                
                pb.ForeColor = RGB(255, 255, 255)
                pb.CurrentX = novoX + (altura + distancia)
                pb.CurrentY = novoY - (pb.TextHeight(nome) / 2)
                pb.Print nome

                quantos = quantos + 1

            Next

            For i = 1 To dinamica.getEventosGeradosSenao.quantosEventos

                novoY = yInicial + ((altura + distancia) * (quantos - 1))
                novoX = posDesenhado.X + (raio * zoomDesenhado) + (altura + distancia)
                desenhaTriangulo pb, novoX, novoY, altura, zoomDesenhado, RGB(255, 255, 0), RGB(51, 0, 204)

                If novoY > maxY Then
                    maxY = novoY + altura
                End If

                nome = dinamica.getEventosGeradosSenao.getEvento(i).emString(dinamica.getId)
                
                pb.FontSize = 8.25
                pb.FontBold = True
                
                nome = limitaNome(pb, nome, ((distanciaHorizontal * zoomDesenhado) / 2) - (raio * zoomDesenhado) - (altura + (distancia * 4)))
                
                pb.ForeColor = RGB(255, 255, 255)
                pb.CurrentX = novoX + (altura + distancia)
                pb.CurrentY = novoY - (pb.TextHeight(nome) / 2)
                pb.Print nome

                quantos = quantos + 1
            Next
        End If

                        
        Dim borda As Long
        Dim distanciaSombra As Long
        
        borda = 50
        distanciaSombra = 15
        
        nome = caminhoCompleto(key)
        
        pb.FontSize = 8.25
        pb.FontBold = True
        
        nome = limitaNome(pb, nome, (distanciaHorizontal * zoomDesenhado))
        
        ponto.X = posDesenhado.X - (pb.TextWidth(nome) / 2)
        ponto.Y = posDesenhado.Y - raioTotal - (pb.TextHeight(nome) * 2) - (borda * 2)
        
        If pb.TextWidth(nome) / 2 > raioTotal Then
            If mimY > 0 Then
                If ponto.Y > mimY Then
                    ponto.Y = mimY
                End If
            End If
        End If
        
        Dim grupo As clsGrupo
        
        Set grupo = definicoes.sinfonia.getGrupos.getGrupoPeloNomeCompleto(caminhoCompleto(key))
        
        If Not grupo Is Nothing Then
        
            pb.ForeColor = grupo.getCor
            pb.FillStyle = vbFSSolid
            pb.Line (ponto.X - borda, ponto.Y - borda)- _
                    (ponto.X + pb.TextWidth(nome) + borda + distanciaSombra, ponto.Y + pb.TextHeight(nome) + borda + distanciaSombra), , BF
        End If
                
        pb.ForeColor = RGB(0, 0, 0)
        pb.CurrentX = ponto.X
        pb.CurrentY = ponto.Y
        pb.Print nome
        
        pb.ForeColor = RGB(255, 255, 255)
        pb.CurrentX = ponto.X + distanciaSombra
        pb.CurrentY = ponto.Y + distanciaSombra
        pb.Print nome
        
        
        
        
        
        nome = definicoes.sinfonia.getDinamicas.getDinamica(key).getNome
        
        pb.FontSize = 8.25
        pb.FontBold = True
        
        nome = limitaNome(pb, nome, (distanciaHorizontal * zoomDesenhado))
        
        pb.ForeColor = RGB(255, 255, 255)
        pb.CurrentX = posDesenhado.X - (pb.TextWidth(nome) / 2)
        pb.CurrentY = posDesenhado.Y + raioTotal + pb.TextHeight(nome)
        
        If pb.TextWidth(nome) / 2 > raioTotal Then
            If maxY > 0 Then
                If pb.CurrentY < maxY Then
                    pb.CurrentY = maxY
                End If
            End If
        End If
        
        pb.Print nome

    End If
    
End Function

Private Function desenhaTriangulo(pb As PictureBox, X As Long, Y As Long, altura As Long, zoom As Double, corTriangulo As Long, corInterna As Long)

    Dim alturaEfetiva As Double
    Dim ponto1 As tPonto
    Dim ponto2 As tPonto
    Dim ponto3 As tPonto
    
    alturaEfetiva = altura / 3
    
    pb.DrawWidth = 1
    pb.FillColor = corInterna
    pb.Circle (X, Y), alturaEfetiva * 0.9, corTriangulo
    
    ponto1.Y = Y + alturaEfetiva
    ponto1.X = X - (alturaEfetiva / Tan(30 * (3.14 / 180)))
    
    ponto2.Y = Y + alturaEfetiva
    ponto2.X = X + (alturaEfetiva / Tan(30 * (3.14 / 180)))

    ponto3.Y = Y - (alturaEfetiva / Tan(30 * (3.14 / 180)))
    ponto3.X = X
    
    pb.DrawWidth = 1
    pb.ForeColor = corTriangulo

    pb.Line (ponto1.X, ponto1.Y)-(ponto2.X, ponto2.Y)
    pb.Line -(ponto3.X, ponto3.Y)
    pb.Line -(ponto1.X, ponto1.Y)

End Function

Private Function limitaNome(pb As PictureBox, ByRef nome As String, largura As Long) As String

    Dim larguraNome As Long
    
    larguraNome = pb.TextWidth(nome)
    
    If larguraNome <= largura Then
    
        limitaNome = nome
    
    Else
    
        Dim quantosCaracteresNoMaximo As Long
        
        quantosCaracteresNoMaximo = (Len(nome) * largura) / larguraNome
    
        If quantosCaracteresNoMaximo >= 4 Then
    
            limitaNome = Mid(nome, 1, quantosCaracteresNoMaximo - 3)
        
            limitaNome = limitaNome & "..."
        Else
        
            limitaNome = ""
        End If
    End If

End Function

Public Function dinamica(X As Long, Y As Long) As String

    dinamica = ""

    If key <> "" Then
    
        Dim deltaX As Double
        Dim deltaY As Double
        Dim distancia As Double
        
        deltaX = Abs(X - posDesenhado.X)
        deltaY = Abs(Y - posDesenhado.Y)
        
        distancia = Sqr((deltaX * deltaX) + (deltaY * deltaY))
    
        If distancia <= (raio * zoomDesenhado) Then
            dinamica = key
        Else
        
            Dim i As Integer
            
            For i = 1 To dinamicasAntes.quantas
            
                dinamica = dinamicasAntes.getDinamica(i).dinamica(X, Y)
                
                If dinamica <> "" Then
                    Exit Function
                End If
            Next
            
            For i = 1 To dinamicasDepois.quantas
            
                dinamica = dinamicasDepois.getDinamica(i).dinamica(X, Y)
                
                If dinamica <> "" Then
                    Exit Function
                End If
            Next
        End If
    End If
    
End Function

Private Function posAbsoluta(pb As PictureBox, X As Long, Y As Long) As tPonto
    posAbsoluta.X = (pb.width / 2) + X
    posAbsoluta.Y = (pb.height / 2) + Y
End Function

Private Sub Class_Initialize()
    raio = 300
    distanciaHorizontal = 7000
    distanciaVertical = 7000
End Sub
