#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"
#include "Engine/Timer.h"

GameLevel::GameLevel(std::wstring image)
	: Level(), image(image)
{
	// �ڵ� ���� Ÿ�̸� ����. 
	autoTimer = new Timer(AUTO_TIME);
	// Ÿ�̸� ���� ���� ����. 
	autoTimer->TogglePause();

	// ���ΰ� ����. 
	hero = new Hero();

	// �÷��̾� �Է� ��� ����. 
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
	// ���ΰ��� �޽��� ������. 
	//Todo: �Է� ���� ��Ȳ ó���ϱ�. 
	if (input == L"front")
	{
		//���ΰ� ������ �̵�. 
		std::wcout << "input front\n";
		outValue = &input;
		return true;
	}
	else if (input == L"left")
	{
		//���ΰ� �������� �̵�. 
		std::wcout << "input left\n";
		outValue = &input;
		return true;
	}
	else if (input == L"right")
	{
		//���ΰ� ���������� �̵�. 
		std::wcout << "input right\n";
		outValue = &input;
		return true;
	}
	else if (input == L"back")
	{
		//���ΰ� �ڷ� �̵�. 
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
	// ���ΰ� ���� �� �̵� ���. 
}

void GameLevel::PlayerCommandProcess()
{
	wchar_t inputBuffer[100] = { };
	Engine::Get().SetCursorPosition(0, 1);
	Log(LogCategoryType::Logging, L"command : front, left, right, back\n");
	Engine::Get().SetCursorPosition(0, 2);
	autoTimer->TogglePause();

	// ���� �ð����� �÷��̾� �Է� ����. 
	while (!autoTimer->IsTimeOut())
	{
		//std::wcout << autoClock->GetDurationSeconds() << "\n";
		std::wcin >> inputBuffer;

		// ��ɾ� �Ǻ��ϱ�. 
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
	// �ִ� �α� �� �̸��� ���, �ڿ� ����. 
	if (savedLogs.size() < MAX_LOG)
	{
		savedLogs.emplace_back(log);
	}

	// �ִ� �α� �� �̻��� ���, ���� ó�� �α� ���� �� �ڿ� ����. 
	auto first = savedLogs.begin();
	savedLogs.erase(first);
	savedLogs.emplace_back(log);
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

		// Ÿ�̸� �ѱ�. 
		autoTimer->TogglePause();
		autoTimer->Update(deltaTime);
		std::cout << autoTimer->GetTime() << "\n";

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
