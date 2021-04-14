#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

int main(void)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcess(
        (LPCWSTR)L"D:\\SPlab4\\lb4\\x64\\Debug\\lb4.exe",
        NULL, NULL, NULL, FALSE,
        CREATE_NEW_CONSOLE,
        NULL, NULL,
        &si, &pi)
    )
    {
        wcout << L"Ошибка запуска процесса: " << GetLastError() << endl;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}