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

	//Todo: ���� ���� �� Ÿ��Ʋ�� ���ư���. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::TitleLevel);
	}
}

void EndingLevel::Draw()
{
	Super::Draw();

	//���� �̹��� ����ϱ�. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
