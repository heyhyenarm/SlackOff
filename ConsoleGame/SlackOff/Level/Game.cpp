#include "Game.h"
#include "TitleLevel.h"
#include "LobbyLevel.h"
#include "GameLevel.h"
#include "EndingLevel.h"
#include "LoadingLevel.h"

Game* Game::instance = nullptr;

Game::Game()
	: Engine()
{
	instance = this;

	//Game �ʱ� ����. Ÿ��Ʋ ȭ��. 
	nowLevelType = LevelType::TitleLevel;

	//������ ���� �����صα�.
	//Todo: �ӽ� �̹��� �ٲٱ�. 
	titleLevel = new TitleLevel(TEXT("title image. Press Spacebar."));
	lobbyLevel = new LobbyLevel(TEXT("lobby image. Press Spacebar. "));
	gameLevel = new GameLevel(TEXT("game image. Press Spacebar. "));
	endingLevel = new EndingLevel(TEXT("ending image. Press Spacebar. "));
	loadingLevel = new LoadingLevel(TEXT("loading image. Press Spacebar. "));
}

Game::~Game()
{
	delete titleLevel;
	delete lobbyLevel;
	delete gameLevel;
	delete endingLevel;
}

void Game::LoadLevel(LevelType levelType)
{
	//���� Ÿ�� �Ǻ�. 
	switch(levelType)
	{
	case LevelType::TitleLevel:
		backLevel = titleLevel;
		break;
	case LevelType::LobbyLevel:
		backLevel = lobbyLevel;
		break;
	case LevelType::GameLevel:
		backLevel = gameLevel;
		break;
	case LevelType::EndingLevel:
		backLevel = endingLevel;
		break;
	}
	nowLevelType = levelType;

	//�ε� ȭ�� �ҷ�����. 
	Loading();
}

void Game::Loading()
{
	//Todo: �ε�. 
	//������� ������ �غ��Ű��, �ε�â ���. 
	//mainLevel = loadingLevel;

	//������� ������ �غ� �Ϸ�Ǹ� �ݹ�. 

	//������̴� ������ ���� ������ �ٽ� �ø���, ���� �ҷ�����. 
	mainLevel = backLevel;
}
