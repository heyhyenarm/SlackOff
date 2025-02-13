#include <iostream>
#include <locale.h>
//#include "Engine/Engine.h"
//#include "Engine/Clock.h"
#include "Level/Game.h"

int main()
{
	CheckMemoryLeak();
	
	//@Test. 완료. 
	//Clock* clock = new Clock();
	//clock->StartClock();
	//Log(ELogCategory::Warning, TEXT("aaaaa\r\n"));

	//유니코드 문자 출력 모드로 설정. 
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "");

	//게임 생성하기. 
	Game game = Game();
	//콘솔 커서 감추기. 
	game.Get().SetCursorType(CursorType::NoCursor);
	//타이틀 레벨 불러오기.
	game.LoadLevel(LevelType::TitleLevel);
	//게임 실행하기.
	game.Run();

	
	//@Test: 유니코드 출력. 완료. 
	//std::wcout << L"▒\n";
	//std::wcout << L"\x2592";
	//@Test: Asset 폴더의 txt_map.txt 불러오기. 
	//FILE* file = nullptr;
	//std::wstring fileString = LoadFile(L"../Assets/txt_map.txt", file);
	//std::wcout << fileString;

	//@Test.
	//clock->StopClock();
	//std::cout << clock->GetDurationMSeconds();
	//std::cin.get();

	//@Test: Split(). 완료. 
	//std::wstring splitString = Split(TEXT("asfje     ivn\ns gas \nas ww\n"), TEXT(" \n"));
}