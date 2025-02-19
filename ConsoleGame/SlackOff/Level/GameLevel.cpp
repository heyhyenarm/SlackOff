#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"
#include "Engine/Timer.h"

GameLevel::GameLevel(std::wstring image)
	: Level(), image(image)
{
	// 자동 진행 타이머 생성. 
	autoTimer = new Timer(AUTO_TIME);
	// 타이머 정지 상태 지정. 
	autoTimer->TogglePause();

	// 주인공 생성. 
	hero = new Hero();

	// 플레이어 입력 대기 상태. 
	isWaitingPlayer = true;
}

GameLevel::~GameLevel()
{
	delete autoTimer;
	autoTimer = nullptr;

	delete hero;
	hero = nullptr;
}

void GameLevel::Start()
{
	//neglectClock.StartClock();
	//RequestPlayerInput();
}

//void GameLevel::RequestPlayerInput()
//{
//	Engine::Get().SetCursorPosition(0, 1);
//	Log(LogCategoryType::Logging, L"command : front, left, right, back\n");
//	autoClock->StartClock();
//
//	//return PlayerInputLog(L"input");
//}

bool GameLevel::PlayerInputLog(std::wstring input, std::wstring* outValue)
{
	// 주인공에 메시지 보내기. 
	//Todo: 입력 예외 상황 처리하기. 
	if (input == L"front")
	{
		//주인공 앞으로 이동. 
		std::wcout << "input front\n";
		outValue = &input;
		return true;
	}
	else if (input == L"left")
	{
		//주인공 왼쪽으로 이동. 
		std::wcout << "input left\n";
		outValue = &input;
		return true;
	}
	else if (input == L"right")
	{
		//주인공 오른쪽으로 이동. 
		std::wcout << "input right\n";
		outValue = &input;
		return true;
	}
	else if (input == L"back")
	{
		//주인공 뒤로 이동. 
		std::wcout << "input back\n";
		outValue = &input;
		return true;
	}

	std::wcout << "wrong command\n";
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
	Engine::Get().SetCursorPosition(0, 1);
	Log(LogCategoryType::Logging, L"command : front, left, right, back\n");
	Engine::Get().SetCursorPosition(0, 2);
	autoTimer->TogglePause();

	// 일정 시간동안 플레이어 입력 받음. 
	while (!autoTimer->IsTimeOut())
	{
		//std::wcout << autoClock->GetDurationSeconds() << "\n";
		std::wcin >> inputBuffer;

		// 명령어 판별하기. 
		std::wstring input;
		if (PlayerInputLog(inputBuffer, &input))
		{
			ManageSavedLog(input);
		}
	}
	isWaitingPlayer = false;
	std::cout << "Time out\n";
}

void GameLevel::ManageSavedLog(std::wstring& log)
{
	// 최대 로그 수 미만인 경우, 뒤에 저장. 
	if (savedLogs.size() < MAX_LOG)
	{
		savedLogs.emplace_back(log);
	}

	// 최대 로그 수 이상인 경우, 가장 처음 로그 삭제 후 뒤에 저장. 
	auto first = savedLogs.begin();
	savedLogs.erase(first);
	savedLogs.emplace_back(log);
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

		// 타이머 켜기. 
		autoTimer->TogglePause();
		autoTimer->Update(deltaTime);
		std::cout << autoTimer->GetTime() << "\n";

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
