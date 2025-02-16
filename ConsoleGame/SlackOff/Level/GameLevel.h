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
	//���� ���� ���� ����. 
	void Start();
	//�÷��̾� �Է� ��û ���. 
	bool RequestPlayerInput();

	//�÷��̾� �Է� �̺�Ʈ. 
	bool PlayerInputLog(std::wstring input);

private:
	std::wstring image;
	Clock neglectClock = Clock();

	bool isWaitingPlayer = false;
};