#include <iostream>
#include "Engine/Engine.h"
#include "Engine/Clock.h"

int main()
{
	CheckMemoryLeak();

	//Clock* clock = new Clock();
	//clock->StartClock();
	Log(ELogCategory::Warning, L"aaaaa\r\n");

	//Asset 폴더의 txt_map.txt 불러오기
	FILE* file = nullptr;
	LoadFile(L"../Assets/txt_map.txt", file);

	//clock->StopClock();
	//std::cout << clock->GetDurationMSeconds();
	//std::cin.get();
}