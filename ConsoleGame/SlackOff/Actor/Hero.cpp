#include "Hero.h"

Hero::Hero()
	: Actor()
{
}

Hero::~Hero()
{
}

void Hero::Update(float deltaTime)
{
	Super::Update(deltaTime);
}

void Hero::Draw()
{
	Super::Draw();
}

void Hero::OnAutoMode()
{
	OnAutoModeRecursive();
}

void Hero::OffAutoMode()
{
	isAutoMode = false;
}

void Hero::OnAutoModeRecursive()
{
	if (isAutoMode)
	{
		// Todo: 이동 자동 진행. 

		// Todo: 스크립트 자동 진행. 

		// 재귀. 
		OnAutoModeRecursive();
	}
}
