#pragma once

#include "Level/Level.h"
#include "Actor/Hero.h"
#include <vector>

#define AUTO_TIME 5
#define MAX_LOG 5

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
	//void RequestPlayerInput();

	// �÷��̾� �Է� �̺�Ʈ. 
	bool PlayerInputLog(std::wstring input, std::wstring* outValue);

	// ���ΰ� ��ũ��Ʈ ���. 
	void PrintScriptHero();
	
	// ���ΰ� �ڵ� �ൿ ���. 
	void SetAutoMode();

	// �÷��̾� ��ɾ� �Է� ���μ���. 
	void PlayerCommandProcess();

	// �α� ���� ���μ���. 
	void ManageSavedLog(std::wstring& log);

private:
	std::wstring image;
	class Timer* autoTimer;
	int autoTime = 10;

	bool isWaitingPlayer = false;

	// ���ΰ� �߰�. 
	Hero* hero;

	// Todo: Queue�� �ٲٱ�. 
	// �α� ���� ����Ʈ. 
	std::vector<std::wstring> savedLogs;
};