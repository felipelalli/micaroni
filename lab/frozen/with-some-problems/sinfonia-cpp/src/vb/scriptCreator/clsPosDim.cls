VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsPosDim"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private top As Integer
Private left As Integer
Private width As Integer
Private height As Integer
Private default As Boolean

Public Function atualiza(obj As Object)

    top = obj.top
    left = obj.left
    width = obj.width
    height = obj.height
    
    default = False
    
End Function

Public Function aplica(obj As Object)

    If Not default Then
        obj.top = top
        obj.left = left
        obj.width = width
        obj.height = height
    Else
    
        atualiza obj
    End If
    
End Function

Public Function carregarXML(noXml As clsNoXML)

    If Not noXml Is Nothing Then
        
        Dim grupoPosDim As New clsGrupoXML
        
        grupoPosDim.carregaGrupoXML noXml, Array("top", "left", "width", "height")
        
        top = CInt(grupoPosDim.getCampo("top").getValor)
        left = CInt(grupoPosDim.getCampo("left").getValor)
        width = CInt(grupoPosDim.getCampo("width").getValor)
        height = CInt(grupoPosDim.getCampo("height").getValor)

        If width = 0 Or height = 0 Then
            default = True
        Else
            default = False
        End If

    Else
    
        default = True

    End If

End Function

Public Function toNoXML(nome As String) As IXMLDOMNode

    Dim salvador As New clsSalvEstados
    Dim noPosDim As IXMLDOMNode
    
    Set noPosDim = salvador.criaNo(nome)
    
    noPosDim.appendChild salvador.criaNo("top", Str(top))
    noPosDim.appendChild salvador.criaNo("left", Str(left))
    noPosDim.appendChild salvador.criaNo("width", Str(width))
    noPosDim.appendChild salvador.criaNo("height", Str(height))
    
    Set toNoXML = noPosDim

End Function

Private Sub Class_Initialize()
    default = True
End Sub
