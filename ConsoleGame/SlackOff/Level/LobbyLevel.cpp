#include "LobbyLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"
#include <string>

LobbyLevel::LobbyLevel(std::wstring image)
	: Level(), image(image)
{
	Init();
}

LobbyLevel::~LobbyLevel()
{
}

void LobbyLevel::Init()
{
	menuItems.push_back(new MenuItem(MenuType::Messanger, L"Messanger", []() { Log(LogCategoryType::Logging, L"Messanger");}));
	menuItems.push_back(new MenuItem(MenuType::Game, L"Game", []() { Game::Get().LoadLevel(LevelType::GameLevel); }));
	menuItems.push_back(new MenuItem(MenuType::Gallery, L"Gallery", []() { Log(LogCategoryType::Logging, L"Gallery"); }));
	menuItems.push_back(new MenuItem(MenuType::Setting, L"Setting", []() { Log(LogCategoryType::Logging, L"Setting"); }));
	menuItems.push_back(new MenuItem(MenuType::TrashBox, L"TrashBox", []() { Log(LogCategoryType::Logging, L"TrashBox"); }));
	menuItems.push_back(new MenuItem(MenuType::Exit, L"Exit", []() { Game::Get().LoadLevel(LevelType::TitleLevel); }));
	menuCount = menuItems.size();
}

void LobbyLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);
	
	// Todo: 1. 마우스 클릭으로 변경하기. 
	// Todo: 메뉴 포커스 구현하기. 
	// 현재 화살표 키로 이동하기.
	// 왼쪽 화살표 눌렀을 경우, 왼쪽 메뉴로 이동하기. 
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		currentMenuIndex = (currentMenuIndex - 1 + menuCount) % menuCount;
	}
	// 오른쪽 화살표 눌렀을 경우, 오른쪽 메뉴로 이동하기. 
	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		currentMenuIndex = (currentMenuIndex + 1 + menuCount) % menuCount;
	}

	
	// Todo: 1. 특정 구역을 마우스 클릭으로 변경하기. 
	// 마우스 입력 시 게임 레벨 불러오기. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		menuItems[currentMenuIndex]->onSelected();
	}
}

void LobbyLevel::Draw()
{
	Super::Draw();

	//로비 이미지 출력.
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());


	for (int i = 0; i < menuCount; ++i)
	{
		// Todo: char/wchar_t 해결하기. 
		Log(i == currentMenuIndex ? LogCategoryType::Warning : LogCategoryType::Logging, L" %s ", menuItems[i]->menuText);

	}


}

