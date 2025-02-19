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
	// 게임 레벨 시작 셋팅. 
	void Start();

	// 플레이어 입력 요청 대기. 
	//void RequestPlayerInput();

	// 플레이어 입력 이벤트. 
	bool PlayerInputLog(std::wstring input, std::wstring* outValue);

	// 주인공 스크립트 출력. 
	void PrintScriptHero();
	
	// 주인공 자동 행동 모드. 
	void SetAutoMode();

	// 플레이어 명령어 입력 프로세스. 
	void PlayerCommandProcess();

	// 로그 관리 프로세스. 
	void ManageSavedLog(std::wstring& log);

private:
	std::wstring image;
	class Timer* autoTimer;
	int autoTime = 10;

	bool isWaitingPlayer = false;

	// 주인공 추가. 
	Hero* hero;

	// Todo: Queue로 바꾸기. 
	// 로그 저장 리스트. 
	std::vector<std::wstring> savedLogs;
};