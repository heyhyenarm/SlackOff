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
	// ���� ���� �ʱ� ����. 
	void Init();

	// ���� �� �ҷ�����. 
	void LoadMap();

	// �׽�Ʈ�� ���� �� �ҷ�����. 
	void LoadTestMap();

	// ���� ���� ����. 
	void Start();

	// �÷��̾� �Է� ��û ���. 
	//void RequestPlayerInput();

	// �÷��̾� �Է� �̺�Ʈ. 
	bool PlayerInputLog(std::wstring input, std::wstring* outValue);

	// ���ΰ� ��ũ��Ʈ ���. 
	void PrintScriptHero();
	
	// ���ΰ� �ڵ� �ൿ ���. 
	void OnAutoMode();

	// �� ã��. 
	void FindPath();

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

	// ���ΰ� ���� ��ġ ����Ʈ. 
	std::vector<Node*> startPositionList;
	Node* startNode;

	// Todo: Queue�� �ٲٱ�. 
	// �α� ���� ����Ʈ. 
	std::vector<std::wstring> savedLogs;

	// ���� ���� ��. 
	std::vector<Actor> gameMap;

	// AI ����. 
	//std::vector<class Monster&> monsterList;

	// AStar ��ü.
	AStar aStar;

	// @Test: �׽�Ʈ ��. 
	std::vector<std::vector<int>> testMap;

	// ���� �ڵ� �� ã��. 
	std::vector<Node*> nowPath;

	// Ż�ⱸ�� ������ ��������. 
	std::vector<Node*> targetList;
	// Ż�ⱸ. 
	Node* exitNode;
};