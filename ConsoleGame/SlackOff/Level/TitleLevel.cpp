#include "TitleLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"
#include "Maze.h"

TitleLevel::TitleLevel()
	: Level()
{
	image = LoadFileCPP("../Assets/Images/img_title.txt");
	Maze maze;
	//maze.GenerateMaze(11, 11);
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
	Engine::Get().SetCursorPosition(0, Engine::Get().ScreenSize().y/2-10);
	std::cout << image;
	//Log(image.c_str());
	//LogAnimation(image.c_str());
}

void TitleLevel::LoadImageFile(std::wstring directory)
{
	//image = WLoadFile(directory);
}
