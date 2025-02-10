#include "Game.h"

Game* Game::instance = nullptr;

Game::Game()
	: Engine()
{
	instance = this;
	nowLevelType = LevelType::TitleLevel;
}

Game::~Game()
{
}

void Game::LoadLevel(LevelType levelType)
{
	switch(levelType)
	{
	}

}

void Game::ToggleLoading()
{

}
