#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"
#include "Engine/Clock.h"

GameLevel::GameLevel(std::wstring image)
	: Level(), image(image)
{
	autoClock = new Clock();
	hero = new Hero();

	isWaitingPlayer = true;
}

GameLevel::GameLevel(std::wstring directory, FILE* file)
	: Level()
{
	autoClock = new Clock();
}

GameLevel::~GameLevel()
{
	delete autoClock;
	autoClock = nullptr;

	delete hero;
	hero = nullptr;
}

void GameLevel::Start()
{
	//neglectClock.StartClock();
	//RequestPlayerInput();
}

void GameLevel::RequestPlayerInput()
{
	Engine::Get().SetCursorPosition(1, 0);
	Log(LogCategoryType::Logging, L"command : front, left, right, back\n");
	autoClock->StartClock();

	//return PlayerInputLog(L"input");
}

bool GameLevel::PlayerInputLog(std::wstring input)
{
	// 주인공에 메시지 보내기. 
	//Todo: 입력 예외 상황 처리하기. 
	if (input == L"front")
	{
		//주인공 앞으로 이동. 
		std::wcout << "input front\n";
	}
	else if (input == L"left")
	{
		//주인공 왼쪽으로 이동. 
		std::wcout << "input left\n";
	}
	else if (input == L"right")
	{
		//주인공 오른쪽으로 이동. 
		std::wcout << "input right\n";
	}
	else if (input == L"back")
	{
		//주인공 뒤로 이동. 
		std::wcout << "input back\n";
	}
	return false;
}

void GameLevel::PrintScriptHero()
{
}

void GameLevel::SetAutoMode()
{
	// 주인공 랜덤 길 이동 모드. 
}

void GameLevel::PlayerCommandProcess()
{
	wchar_t inputBuffer[100] = { };
	Engine::Get().SetCursorPosition(1, 0);
	Log(LogCategoryType::Logging, L"command : front, left, right, back\n");
	autoClock->StartClock();

	// 일정 시간동안 플레이어 입력 받음. 
	while (autoClock->GetDurationSeconds() < AUTO_TIME)
	{
		std::wcin >> inputBuffer;

		// 명령어 판별하기. 
		PlayerInputLog(inputBuffer);
	}
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//Todo: 플레이어 input이 없이 일정 시간이 지나면 자동으로 주인공 스크립트 출력. 

	//Todo: 일정 시간이 지나면 자동으로 엔딩 레벨 불러오기. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::EndingLevel);
	}

	// 플레이어 명령어 대기 모드인 경우. 
	if (isWaitingPlayer)
	{
		std::wcout << "isWaitingPlayer On\n";
		// PlayerCommandProcess 진행. 
		PlayerCommandProcess();
	}
	
	//if (isWaitingPlayer)
	//{
	//	std::wstring playerInputLog;
	//	std::wcin >> playerInputLog;
	//}
}

void GameLevel::Draw()
{
	Super::Draw();

	//게임 이미지 출력하기. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
