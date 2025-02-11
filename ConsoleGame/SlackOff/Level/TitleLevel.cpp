#include "TitleLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"

TitleLevel::TitleLevel(std::wstring titleImage)
	: Level(), image(titleImage)
{
}

TitleLevel::TitleLevel(const std::wstring directory, FILE* file)
	: Level()
{
	image = LoadFile(directory, file);
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//Todo: ���콺 �Է����� �����ϱ�
	//���콺 Ŭ�� �� �κ� ���� �ҷ�����. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::LobbyLevel);
	}
}

void TitleLevel::Draw()
{
	Super::Draw();

	//Ÿ��Ʋ �̹��� �׷��ֱ�. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
