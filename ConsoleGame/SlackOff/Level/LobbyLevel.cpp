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
	
	// Todo: 1. ���콺 Ŭ������ �����ϱ�. 
	// Todo: �޴� ��Ŀ�� �����ϱ�. 
	// ���� ȭ��ǥ Ű�� �̵��ϱ�.
	// ���� ȭ��ǥ ������ ���, ���� �޴��� �̵��ϱ�. 
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		currentMenuIndex = (currentMenuIndex - 1 + menuCount) % menuCount;
	}
	// ������ ȭ��ǥ ������ ���, ������ �޴��� �̵��ϱ�. 
	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		currentMenuIndex = (currentMenuIndex + 1 + menuCount) % menuCount;
	}

	
	// Todo: 1. Ư�� ������ ���콺 Ŭ������ �����ϱ�. 
	// ���콺 �Է� �� ���� ���� �ҷ�����. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		menuItems[currentMenuIndex]->onSelected();
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
		Log(i == currentMenuIndex ? LogCategoryType::Warning : LogCategoryType::Logging, L" %s ", menuItems[i]->menuText);

	}


}

