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
	
	// Todo: 1. ���콺 Ŭ������ �����ϱ�. 
	// Todo: �޴� ��Ŀ�� �����ϱ�. 
	// ���� ȭ��ǥ Ű�� �̵��ϱ�.
	// ���� ȭ��ǥ ������ ���, ���� �޴��� �̵��ϱ�. 
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		currentMenu = (currentMenu - 1 + menuCount) % menuCount;
	}
	// ������ ȭ��ǥ ������ ���, ������ �޴��� �̵��ϱ�. 
	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		currentMenu = (currentMenu + 1 + menuCount) % menuCount;
	}

	
	// Todo: 1. Ư�� ������ ���콺 Ŭ������ �����ϱ�. 
	// ���콺 �Է� �� ���� ���� �ҷ�����. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		//// ���� ������ �޴��� �´� ��� �ҷ�����. 
		//switch (selectedMenuItem->menuType)
		//{
		//	case MenuType::Gallery:
		//	{
		//		// Todo: �ٹ� �����ϱ�. 
		//		std::cout << "Load Gallery";
		//	}break;
		//	case MenuType::Game:
		//	{
		//		// ���� ������ �̵��ϱ�. 
		//		Game::Get().LoadLevel(LevelType::GameLevel);
		//	}break;
		//	case MenuType::Setting:
		//	{
		//		// Todo: ȯ�� ���� �����ϱ�. 
		//		std::cout << "Load Setting";

		//	}break;
		//	case MenuType::TrashBox:
		//	{
		//		// Todo: �������� �����ϱ�. 
		//		std::cout << "Load TrashBox";

		//	}break;
		//	case MenuType::Exit:
		//	{
		//		// Ÿ��Ʋ�� ���ư���. 
		//		Game::Get().LoadLevel(LevelType::TitleLevel);
		//	}break;
		//}
	}
}

void LobbyLevel::Draw()
{
	Super::Draw();

	//�κ� �̹��� ���.
	Engine::Get().SetCursorPosition(0, 0);
	Log(LogCategoryType::Logging, image.c_str());


	for (int i = 0; i < menuCount; ++i)
	{
		// Todo: char/wchar_t �ذ��ϱ�. 
		Log(i == currentMenu ? LogCategoryType::Warning : LogCategoryType::Logging, L"%s\n", menuItems[i]->menuText);
	}


}

