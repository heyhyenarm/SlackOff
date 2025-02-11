#pragma once

#include "Core.h"
#include "Engine/Engine.h"
#include "Enums.h"

class Game : public Engine
{
public:
	explicit Game();
	~Game();

	//��� ���� �ҷ�����. 
	void LoadLevel(LevelType levelType);

	static Game& Get() { return *instance; }

private:
	//�ε� ȭ�� �ҷ�����. 
	void Loading();

private:
	//���� �׷��ִ�, ������� ����. 
	Level* backLevel = nullptr;

	//�ε� ����. 
	class LoadingLevel* loadingLevel = nullptr;
	bool showLoading = false;

	//������. 
	Level* titleLevel = nullptr;
	Level* lobbyLevel = nullptr;
	Level* gameLevel = nullptr;
	Level* endingLevel = nullptr;

	//������ ���� Ÿ��. 
	LevelType nowLevelType;

private:
	static Game* instance;
};