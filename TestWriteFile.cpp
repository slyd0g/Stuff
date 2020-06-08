#include <iostream>
#include "Windows.h"

int main()
{

    	std::cout << "Hello World!\n";
	LPCWSTR outputFile = L"C:\\Users\\John\\Desktop\\JUSTIN_TESTING.txt";
	HANDLE hEvent, hFile, hCreateFile;
	DWORD dwBytesWritten, dwBytesToWrite;
	
	hCreateFile = CreateFileW(outputFile, GENERIC_WRITE, NULL, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hCreateFile == INVALID_HANDLE_VALUE)
	{
		std::cout << "Error: " << GetLastError() << "\n";
		return 0;
	}
	CloseHandle(hCreateFile);

	hFile = CreateFileW(outputFile, FILE_APPEND_DATA, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::cout << "Error: " << GetLastError() << "\n";
		return 0;
	}
	CloseHandle(hFile);
	std::cout << "Files created, handles closed \n";

	return 0;
}
