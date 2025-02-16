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

	//Todo: ���ΰ��� �޽��� ������. 
	//Todo: �Է� ���� ��Ȳ ó���ϱ�. 
	if (input == L"front")
	{
		//���ΰ� ������ �̵�. 
	}
	else if (input == L"left")
	{
		//���ΰ� �������� �̵�. 
	}
	else if (input == L"right")
	{
		//���ΰ� ���������� �̵�. 
	}
	else if (input == L"back")
	{
		//���ΰ� �ڷ� �̵�. 
	}
	return false;
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

	if (isWaitingPlayer)
	{
		std::wstring playerInputLog;
		std::wcin >> playerInputLog;
	}
}

void GameLevel::Draw()
{
	Super::Draw();

	//���� �̹��� ����ϱ�. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
