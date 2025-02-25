#pragma once

#include "Level/Level.h"
#include "Actor/Hero.h"
#include "Algorithm/Node.h"
#include "Algorithm/AStar.h"
#include <vector>

#define AUTO_TIME 5
#define MAX_LOG 5

class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	explicit GameLevel(std::wstring image);
	//explicit GameLevel(std::wstring directory, FILE* file);
	~GameLevel();
	
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

private:
	// 게임 레벨 초기 셋팅. 
	void Init();

	// 게임 맵 불러오기. 
	void LoadMap();

	// 테스트용 게임 맵 불러오기. 
	void LoadTestMap();

	// 게임 레벨 시작. 
	void Start();

	// 플레이어 입력 요청 대기. 
	//void RequestPlayerInput();

	// 플레이어 입력 이벤트. 
	bool PlayerInputLog(std::wstring input, std::wstring* outValue);

	// 주인공 스크립트 출력. 
	void PrintScriptHero();
	
	// 주인공 자동 행동 모드. 
	void OnAutoMode();

	// 길 찾기. 
	void FindPath();

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

	// 주인공 시작 위치 리스트. 
	std::vector<Node*> startPositionList;
	Node* startNode;

	// Todo: Queue로 바꾸기. 
	// 로그 저장 리스트. 
	std::vector<std::wstring> savedLogs;

	// 게임 진행 맵. 
	std::vector<Actor> gameMap;

	// AI 몬스터. 
	//std::vector<class Monster&> monsterList;

	// AStar 객체.
	AStar aStar;

	// @Test: 테스트 맵. 
	std::vector<std::vector<int>> testMap;

	// 현재 자동 길 찾기. 
	std::vector<Node*> nowPath;

	// 탈출구를 제외한 목적지들. 
	std::vector<Node*> targetList;
	// 탈출구. 
	Node* exitNode;
};