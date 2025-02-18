#pragma once

#include "Level/Level.h"
#include "Actor/Hero.h"

#define AUTO_TIME 10

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
	// ���� ���� ���� ����. 
	void Start();

	// �÷��̾� �Է� ��û ���. 
	void RequestPlayerInput();

	// �÷��̾� �Է� �̺�Ʈ. 
	bool PlayerInputLog(std::wstring input);

	// ���ΰ� ��ũ��Ʈ ���. 
	void PrintScriptHero();
	
	// ���ΰ� �ڵ� �ൿ ���. 
	void SetAutoMode();

	// �÷��̾� ��ɾ� �Է� ���μ���. 
	void PlayerCommandProcess();
private:
	std::wstring image;
	class Clock* autoClock;
	int autoTime = 10;

	bool isWaitingPlayer = false;

	// ���ΰ� �߰�. 
	Hero* hero;
};