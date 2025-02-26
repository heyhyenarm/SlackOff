#include "Game.h"
#include "TitleLevel.h"
#include "LobbyLevel.h"
#include "GameLevel.h"
#include "EndingLevel.h"
#include "LoadingLevel.h"
#include "Core.h"

#define FONT_SIZE 3

Game* Game::instance = nullptr;

Game::Game()
	: Engine()
{
	instance = this;

	// 콘솔 창 폰트 사이즈 설정. 
	Engine::Get().SetFontSize(FONT_SIZE);
	Engine::Get().SetTitle(L"Slack-Off");
	//SetTitle(L"Slack-Off");

	//Game 초기 셋팅. 타이틀 화면. 
	nowLevelType = LevelType::TitleLevel;

	//레벨들 동적 생성해두기.
	//Todo: 임시 이미지 바꾸기. 
	titleLevel = new TitleLevel();
	lobbyLevel = new LobbyLevel();
	gameLevel = new GameLevel();
	endingLevel = new EndingLevel(TEXT("ending image. Press Spacebar.\n"));
	loadingLevel = new LoadingLevel(TEXT("loading image. Press Spacebar.\n"));
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
	Engine::Get().ClearScreen();

	//레벨 타입 판별. 
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

	//로딩 화면 불러오기. 
	Loading();
}

void Game::Loading()
{
	//Todo: 로딩. 
	//대기중인 레벨을 준비시키고, 로딩창 출력. 
	//mainLevel = loadingLevel;

	//대기중인 레벨이 준비가 완료되면 콜백. 

	//대기중이던 레벨을 메인 레벨로 다시 올리고, 레벨 불러오기. 
	mainLevel = backLevel;
}
