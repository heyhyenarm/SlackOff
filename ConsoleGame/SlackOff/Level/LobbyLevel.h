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

	MenuItem(MenuType menuType, const wchar_t* text, OnSelected onSelected)
		: menuType(menuType)
	{
		size_t length = wcslen(text);
		menuText = new wchar_t[length + 1];
		wcscpy_s(menuText, length + 1, text);

		this->onSelected = onSelected;
	}

	~MenuItem()
	{
		delete[] menuText;
	}

	MenuType menuType;
	wchar_t* menuText;
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
	int currentMenuIndex = 0;

	Color selectedColor = Color::Green;
	Color unselectedColor = Color::White;
};