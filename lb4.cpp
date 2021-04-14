#include <fstream>
#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

void copy_file(wstring copy_from, wstring copy_to);

int main()
{
    wstring search_files_in_dir = L"*";
    wstring copy_from_path = L"D:\\dir1\\";
    wstring copy_to_path = L"D:\\dir2\\";


    WIN32_FIND_DATAW wfd;
    HANDLE const hFind = FindFirstFileW((LPCWSTR)(copy_from_path + search_files_in_dir).c_str(), &wfd);
    setlocale(LC_ALL, "");

    if (INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
            wstring ws(wfd.cFileName);
            if (ws == L"." || ws == L"..")
                continue;

            wcout << L"Найден файл: " << ws << endl;

            if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                wcout << L"Это директория. Пропускаем" << endl;
                continue;
            }

            wstring copy_from = copy_from_path + ws;
            wstring copy_to = copy_to_path + ws;

            copy_file(copy_from, copy_to);

        } while (NULL != FindNextFile(hFind, &wfd));

        FindClose(hFind);
    }
    return 0;
}

void copy_file(wstring copy_from, wstring copy_to) {
    wcout << L"Копирование файла из: " << (LPCWSTR)copy_from.c_str() << endl;
    wcout << L"Копирование файла в: " << (LPCWSTR)copy_to.c_str() << endl;
    bool result = CopyFile(
        (LPCWSTR)copy_from.c_str(),
        (LPCWSTR)copy_to.c_str(),
        TRUE
    );
    if (result) {
        wcout << L"Успешно скопировано" << endl;
    }
    else {
        wcout << L"Ошибка в процессе копирования" << endl;
    }
    wcout << endl;
}