#include "LobbyLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"
#include <string>

LobbyLevel::LobbyLevel(std::wstring image)
	: Level(), image(image)
{
}

LobbyLevel::LobbyLevel(std::wstring directory, FILE* file)
	: Level()
{
}

LobbyLevel::~LobbyLevel()
{
}

void LobbyLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);
	
	//Todo: 1. ���콺 Ŭ������ �����ϱ�. 
	//Todo: 1. Ư�� ������ ���콺 Ŭ������ �����ϱ�. 
	//���콺 �Է� �� ���� ���� �ҷ�����. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::GameLevel);
	}
}

void LobbyLevel::Draw()
{
	Super::Draw();

	//�κ� �̹��� ���.
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
