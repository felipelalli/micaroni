Attribute VB_Name = "mMouseWheel"
Option Explicit

Private Declare Function CallWindowProc Lib "user32.dll" Alias "CallWindowProcA" ( _
ByVal lpPrevWndFunc As Long, _
ByVal hWnd As Long, _
ByVal Msg As Long, _
ByVal Wparam As Long, _
ByVal Lparam As Long) As Long

Private Declare Function SetWindowLong Lib "user32.dll" Alias "SetWindowLongA" ( _
ByVal hWnd As Long, _
ByVal nIndex As Long, _
ByVal dwNewLong As Long) As Long

Public Const MK_CONTROL = &H8
Public Const MK_LBUTTON = &H1
Public Const MK_RBUTTON = &H2
Public Const MK_MBUTTON = &H10
Public Const MK_SHIFT = &H4
Private Const GWL_WNDPROC = -4
Private Const WM_MOUSEWHEEL = &H20A

Dim LocalHwnd As Long
Dim LocalPrevWndProc As Long
Dim MyForm As Form


Private Function WindowProc(ByVal Lwnd As Long, ByVal Lmsg As Long, ByVal Wparam As Long, ByVal Lparam As Long) As Long

    Dim MouseKeys As Long
    Dim Rotation As Long
    Dim Xpos As Long
    Dim Ypos As Long

    If Lmsg = WM_MOUSEWHEEL Then
        MouseKeys = Wparam And 65535
        Rotation = Wparam / 65536
        Xpos = Lparam And 65535
        Ypos = Lparam / 65536
        MyForm.MouseWheel MouseKeys, Rotation, Xpos, Ypos
    End If
    WindowProc = CallWindowProc(LocalPrevWndProc, Lwnd, Lmsg, Wparam, Lparam)
End Function

Public Sub WheelHook(PassedForm As Form)

    On Error Resume Next

    Set MyForm = PassedForm
    LocalHwnd = PassedForm.hWnd
    LocalPrevWndProc = SetWindowLong(LocalHwnd, GWL_WNDPROC, AddressOf WindowProc)
End Sub


Public Sub WheelUnHook()
    Dim WorkFlag As Long

    On Error Resume Next
    WorkFlag = SetWindowLong(LocalHwnd, GWL_WNDPROC, LocalPrevWndProc)
    Set MyForm = Nothing
End Sub

