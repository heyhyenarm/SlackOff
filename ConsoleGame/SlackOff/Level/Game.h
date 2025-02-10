#pragma once

#include "Core.h"
#include "Engine/Engine.h"
#include "Enums.h"

class Game : public Engine
{
public:
	Game();
	~Game();

	void LoadLevel(LevelType levelType);
	void ToggleLoading();

	static Game& Get() { return *instance; }

private:
	Level* loadingLevel = nullptr;
	Level* backLevel = nullptr;
	bool showLoading = false;

	Level* titleLevel = nullptr;
	Level* lobbyLevel = nullptr;
	Level* gameLevel = nullptr;
	Level* endingLevel = nullptr;

	LevelType nowLevelType;

private:
	static Game* instance;
};