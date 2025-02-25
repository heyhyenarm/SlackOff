#include "TitleLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"

TitleLevel::TitleLevel(std::wstring titleImage)
	: Level(), image(titleImage)
{
	//LoadImageFile(L"../Assets/Images/img_title.txt");
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//Todo: 마우스 입력으로 변경하기
	//마우스 클릭 시 로비 레벨 불러오기. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::LobbyLevel);
	}
}

void TitleLevel::Draw()
{
	Super::Draw();

	//타이틀 이미지 그려주기. 
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
	//LogAnimation(image.c_str());
}

void TitleLevel::LoadImageFile(std::wstring directory)
{
	image = WLoadFile(directory);
}
