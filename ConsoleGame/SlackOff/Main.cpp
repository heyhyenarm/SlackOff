#include <iostream>
#include "Engine/Engine.h"


int main()
{
	CheckMemoryLeak();

	Log(ELogCategory::Warning, L"aaaaa\r\n");

	//Asset 폴더의 txt_map.txt 불러오기
	FILE* file = nullptr;
	LoadFile(L"../Assets/txt_map.txt", file);

	//std::cin.get();
}