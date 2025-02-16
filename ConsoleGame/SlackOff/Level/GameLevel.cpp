#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"

GameLevel::GameLevel(std::wstring image)
	: Level(), image(image)
{
}

GameLevel::GameLevel(std::wstring directory, FILE* file)
	: Level()
{
}

GameLevel::~GameLevel()
{
}

void GameLevel::Start()
{
	//neglectClock.StartClock();
}

bool GameLevel::RequestPlayerInput()
{
	Engine::Get().SetCursorPosition(1, 0);
	Log(LogCategoryType::Logging, L"command : front, left, right, back\n");
	neglectClock.StartClock();

	return PlayerInputLog(L"input");
}

bool GameLevel::PlayerInputLog(std::wstring input)
{

	//Todo: 주인공에 메시지 보내기. 
	//Todo: 입력 예외 상황 처리하기. 
	if (input == L"front")
	{
		//주인공 앞으로 이동. 
	}
	else if (input == L"left")
	{
		//주인공 왼쪽으로 이동. 
	}
	else if (input == L"right")
	{
		//주인공 오른쪽으로 이동. 
	}
	else if (input == L"back")
	{
		//주인공 뒤로 이동. 
	}
	return false;
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

	if (isWaitingPlayer)
	{
		std::wstring playerInputLog;
		std::wcin >> playerInputLog;
	}
}

void GameLevel::Draw()
{
	Super::Draw();

	//게임 이미지 출력하기. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
