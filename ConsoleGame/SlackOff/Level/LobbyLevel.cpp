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
	menuItems.push_back(new MenuItem(MenuType::Messanger, "Messanger", []() { Log(LogCategoryType::Logging, L"Messanger");}));
	menuItems.push_back(new MenuItem(MenuType::Game, "Game", []() { Game::Get().LoadLevel(LevelType::GameLevel); }));
	menuItems.push_back(new MenuItem(MenuType::Gallery, "Gallery", []() { Log(LogCategoryType::Logging, L"Gallery"); }));
	menuItems.push_back(new MenuItem(MenuType::Setting, "Setting", []() { Log(LogCategoryType::Logging, L"Setting"); }));
	menuItems.push_back(new MenuItem(MenuType::TrashBox, "TrashBox", []() { Log(LogCategoryType::Logging, L"TrashBox"); }));
	menuItems.push_back(new MenuItem(MenuType::Exit, "Exit", []() { Game::Get().LoadLevel(LevelType::TitleLevel); }));
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
		currentMenu = (currentMenu - 1 + menuCount) % menuCount;
	}
	// 오른쪽 화살표 눌렀을 경우, 오른쪽 메뉴로 이동하기. 
	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		currentMenu = (currentMenu + 1 + menuCount) % menuCount;
	}

	
	// Todo: 1. 특정 구역을 마우스 클릭으로 변경하기. 
	// 마우스 입력 시 게임 레벨 불러오기. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		//// 현재 선택한 메뉴에 맞는 기능 불러오기. 
		//switch (selectedMenuItem->menuType)
		//{
		//	case MenuType::Gallery:
		//	{
		//		// Todo: 앨범 구현하기. 
		//		std::cout << "Load Gallery";
		//	}break;
		//	case MenuType::Game:
		//	{
		//		// 게임 레벨로 이동하기. 
		//		Game::Get().LoadLevel(LevelType::GameLevel);
		//	}break;
		//	case MenuType::Setting:
		//	{
		//		// Todo: 환경 설정 구현하기. 
		//		std::cout << "Load Setting";

		//	}break;
		//	case MenuType::TrashBox:
		//	{
		//		// Todo: 쓰레기통 구현하기. 
		//		std::cout << "Load TrashBox";

		//	}break;
		//	case MenuType::Exit:
		//	{
		//		// 타이틀로 돌아가기. 
		//		Game::Get().LoadLevel(LevelType::TitleLevel);
		//	}break;
		//}
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
		Log(i == currentMenu ? LogCategoryType::Warning : LogCategoryType::Logging, L"%s\n", menuItems[i]->menuText);
	}


}

