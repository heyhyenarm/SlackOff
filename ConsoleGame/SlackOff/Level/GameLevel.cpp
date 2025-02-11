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

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//Todo: ���� �ð��� ������ �ڵ����� ���� ���� �ҷ�����. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::EndingLevel);
	}
}

void GameLevel::Draw()
{
	Super::Draw();

	//���� �̹��� ����ϱ�. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
