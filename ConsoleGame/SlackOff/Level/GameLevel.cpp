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
	// ���ΰ��� �޽��� ������. 
	//Todo: �Է� ���� ��Ȳ ó���ϱ�. 
	if (input == L"front")
	{
		//���ΰ� ������ �̵�. 
		std::wcout << "input front\n";
	}
	else if (input == L"left")
	{
		//���ΰ� �������� �̵�. 
		std::wcout << "input left\n";
	}
	else if (input == L"right")
	{
		//���ΰ� ���������� �̵�. 
		std::wcout << "input right\n";
	}
	else if (input == L"back")
	{
		//���ΰ� �ڷ� �̵�. 
		std::wcout << "input back\n";
	}
	return false;
}

void GameLevel::PrintScriptHero()
{
}

void GameLevel::SetAutoMode()
{
	// ���ΰ� ���� �� �̵� ���. 
}

void GameLevel::PlayerCommandProcess()
{
	wchar_t inputBuffer[100] = { };
	Engine::Get().SetCursorPosition(1, 0);
	Log(LogCategoryType::Logging, L"command : front, left, right, back\n");
	autoClock->StartClock();

	// ���� �ð����� �÷��̾� �Է� ����. 
	while (autoClock->GetDurationSeconds() < AUTO_TIME)
	{
		std::wcin >> inputBuffer;

		// ��ɾ� �Ǻ��ϱ�. 
		PlayerInputLog(inputBuffer);
	}
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//Todo: �÷��̾� input�� ���� ���� �ð��� ������ �ڵ����� ���ΰ� ��ũ��Ʈ ���. 

	//Todo: ���� �ð��� ������ �ڵ����� ���� ���� �ҷ�����. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::EndingLevel);
	}

	// �÷��̾� ��ɾ� ��� ����� ���. 
	if (isWaitingPlayer)
	{
		std::wcout << "isWaitingPlayer On\n";
		// PlayerCommandProcess ����. 
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

	//���� �̹��� ����ϱ�. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
