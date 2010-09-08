#include <windows.h>  
#include <stdio.h>  
  
main () {  
    HANDLE hFile = ::CreateFile (  
        ".",  
        FILE_READ_ATTRIBUTES,  
        FILE_SHARE_READ | FILE_SHARE_WRITE,  
        NULL,  
        OPEN_EXISTING,  
        FILE_FLAG_BACKUP_SEMANTICS,  
        NULL);  
    BY_HANDLE_FILE_INFORMATION fileInformation;          
    GetFileInformationByHandle(  
        hFile, &fileInformation);  
    printf ("%d\n", fileInformation.dwVolumeSerialNumber);  
  
    CloseHandle (hFile);  
}
