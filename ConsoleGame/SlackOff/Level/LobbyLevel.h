#pragma once

#include "Level/Level.h"

class LobbyLevel : public Level
{
	RTTI_DECLARATIONS(LobbyLevel, Level)
	
public:
	explicit LobbyLevel(std::wstring image);
	explicit LobbyLevel(std::wstring directory, FILE* file);
	~LobbyLevel();

	virtual void Update(float deltaTime) override; 
	virtual void Draw() override; 

private:
	std::wstring image;
};