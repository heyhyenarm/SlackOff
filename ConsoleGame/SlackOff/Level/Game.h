#pragma once

#include "Core.h"
#include "Engine/Engine.h"
#include "Enums.h"

class Game : public Engine
{
public:
	explicit Game();
	~Game();

	//대상 레벨 불러오기. 
	void LoadLevel(LevelType levelType);

	static Game& Get() { return *instance; }

private:
	//로딩 화면 불러오기. 
	void Loading();

private:
	//현재 그려주는, 대기중인 레벨. 
	Level* backLevel = nullptr;

	//로딩 레벨. 
	class LoadingLevel* loadingLevel = nullptr;
	bool showLoading = false;

	//레벨들. 
	Level* titleLevel = nullptr;
	Level* lobbyLevel = nullptr;
	Level* gameLevel = nullptr;
	Level* endingLevel = nullptr;

	//현재의 레벨 타입. 
	LevelType nowLevelType;

private:
	static Game* instance;
};