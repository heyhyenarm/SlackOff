#pragma once

#include "Level/Level.h"
#include <vector>

enum class MenuType
{
	Messanger,
	Game,
	Gallery,
	Setting,
	TrashBox,
	Exit
};

struct MenuItem
{
	using OnSelected = void (*)();

	MenuItem(MenuType menuType, const char* text, OnSelected onSelected)
		: menuType(menuType)
	{
		size_t length = strlen(text);
		menuText = new char[length + 1];
		strcpy_s(menuText, length + 1, text);

		this->onSelected = onSelected;
	}

	~MenuItem()
	{
		delete[] menuText;
	}

	MenuType menuType;
	char* menuText;
	OnSelected onSelected;
};

class LobbyLevel : public Level
{
	RTTI_DECLARATIONS(LobbyLevel, Level)
	
public:
	explicit LobbyLevel(std::wstring image);
	~LobbyLevel();

	virtual void Update(float deltaTime) override; 
	virtual void Draw() override; 

private:
	void Init();

private:
	std::wstring image;

	std::vector<MenuItem*> menuItems;

	int menuCount = 0;
	int currentMenu = 0;
	// 현재 메뉴 아이템. 
	MenuItem* nowMenuItem;
	// 선택한 메뉴 아이템. 
	MenuItem* selectedMenuItem;

	Color selectedColor = Color::Green;
	Color unselectedColor = Color::White;

	//MenuType selectedMenuType = MenuType::Game;
};