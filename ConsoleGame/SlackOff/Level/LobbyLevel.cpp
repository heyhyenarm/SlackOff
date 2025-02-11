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
	
	//Todo: 1. 마우스 클릭으로 변경하기. 
	//Todo: 1. 특정 구역을 마우스 클릭으로 변경하기. 
	//마우스 입력 시 게임 레벨 불러오기. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::GameLevel);
	}
}

void LobbyLevel::Draw()
{
	Super::Draw();

	//로비 이미지 출력.
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());
}
