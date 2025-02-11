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

	//Todo: 일정 시간이 지나면 자동으로 엔딩 레벨 불러오기. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::EndingLevel);
	}
}

void GameLevel::Draw()
{
	Super::Draw();

	//게임 이미지 출력하기. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
