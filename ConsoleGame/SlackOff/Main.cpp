#include <iostream>
#include <locale.h>
#include "Engine/Engine.h"
#include "Engine/Clock.h"

int main()
{
	CheckMemoryLeak();
	
	//@Test.
	//Clock* clock = new Clock();
	//clock->StartClock();
	Log(ELogCategory::Warning, TEXT("aaaaa\r\n"));

	SetConsoleOutputCP(CP_UTF8);

	setlocale(LC_ALL, "");
	//@Test: Asset 폴더의 txt_map.txt 불러오기. 
	FILE* file = nullptr;
	std::wstring fileString = LoadFile(L"../Assets/txt_map.txt", file);
	std::wcout << fileString;

	//@Test.
	//clock->StopClock();
	//std::cout << clock->GetDurationMSeconds();
	//std::cin.get();
}