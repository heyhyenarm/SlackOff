#include "EndingLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"

EndingLevel::EndingLevel(std::wstring image)
	: Level(), image(image)
{
}

EndingLevel::EndingLevel(std::wstring directory, FILE* file)
	: Level()
{
}

EndingLevel::~EndingLevel()
{
}

void EndingLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//Todo: 엔딩 연출 후 타이틀로 돌아가기. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::TitleLevel);
	}
}

void EndingLevel::Draw()
{
	Super::Draw();

	//엔딩 이미지 출력하기. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
