VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsNoXML"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private no As IXMLDOMNode

Public Sub setNoXML(pNo As IXMLDOMNode)
    Set no = pNo
End Sub

Public Function nome() As String

    If Not no Is Nothing Then

        nome = no.nodeName

    Else
    
        nome = ""
        
    End If
    
End Function





Public Function valor() As String

    If Not no Is Nothing Then

        If Not possuiFilhos Then

            If no.hasChildNodes Then
                
                Dim noFilho As IXMLDOMNode
                Dim possuiElementoDeTexto As Boolean
                
                possuiElementoDeTexto = False

                Set noFilho = no.firstChild

                While ((Not noFilho Is Nothing) And (Not possuiElementoDeTexto))

                    If noFilho.nodeType = 3 Then

                        valor = noFilho.Text
                        possuiElementoDeTexto = True
                        Exit Function
                    End If

                    Set noFilho = noFilho.nextSibling
                Wend

                valor = ""

            Else

                valor = ""
                
            End If

        Else
        
            valor = ""
            
        End If
    
    Else
        
        valor = ""
        
    End If
    
End Function




Public Function possuiFilhos() As Boolean

    If Not no Is Nothing Then

        If no.hasChildNodes Then

            Dim noFilho As IXMLDOMNode
            Dim possuiElementoComoFilho As Boolean
            
            possuiElementoComoFilho = False

            Set noFilho = no.firstChild

            While (Not noFilho Is Nothing) And (Not possuiElementoComoFilho)

                If noFilho.nodeType = 1 Then

                    possuiElementoComoFilho = True
                    
                End If

                Set noFilho = noFilho.nextSibling
                
            Wend

            possuiFilhos = possuiElementoComoFilho

        Else
        
            possuiFilhos = False
            
        End If

    Else
    
        possuiFilhos = False
        
    End If
End Function




Public Function primeiroFilho() As clsNoXML

    If Not no Is Nothing Then

        If no.hasChildNodes Then

            Dim noFilho As IXMLDOMNode
            Dim possuiElementoComoFilho As Boolean
            
            possuiElementoComoFilho = False

            Set noFilho = no.firstChild

            While (Not noFilho Is Nothing) And (Not possuiElementoComoFilho)

                If noFilho.nodeType = 1 Then
                    
                    Dim cPrimeiroFilho As New clsNoXML
                    
                    cPrimeiroFilho.setNoXML noFilho
                    
                    Set primeiroFilho = cPrimeiroFilho
                    
                    Exit Function
                    
                End If

                Set noFilho = noFilho.nextSibling
                
            Wend

            Set primeiroFilho = Nothing

        Else

            Set primeiroFilho = Nothing
            
        End If

    Else
    
        Set primeiroFilho = Nothing
        
    End If
    
End Function




Public Function proximoNo() As clsNoXML

    If Not no Is Nothing Then

        Dim pProximoNo As IXMLDOMNode

        Set pProximoNo = no.nextSibling

        While Not pProximoNo Is Nothing

            If pProximoNo.nodeType = 1 Then
                
                Dim cProximoNo As New clsNoXML
                
                cProximoNo.setNoXML pProximoNo
                
                Set proximoNo = cProximoNo
                
                Exit Function
                
            End If

            Set pProximoNo = pProximoNo.nextSibling
            
        Wend

        Set proximoNo = Nothing

    Else
    
        Set proximoNo = Nothing
        
    End If
    
End Function
