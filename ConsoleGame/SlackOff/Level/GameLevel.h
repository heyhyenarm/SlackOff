#pragma once

#include "Level/Level.h"
#include "Engine/Clock.h"

class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	explicit GameLevel(std::wstring image);
	explicit GameLevel(std::wstring directory, FILE* file);
	~GameLevel();
	
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

private:
	//게임 레벨 시작 셋팅. 
	void Start();
	//플레이어 입력 요청 대기. 
	bool RequestPlayerInput();

	//플레이어 입력 이벤트. 
	bool PlayerInputLog(std::wstring input);

private:
	std::wstring image;
	Clock neglectClock = Clock();

	bool isWaitingPlayer = false;
};