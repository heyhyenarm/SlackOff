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
		// Todo: �̵� �ڵ� ����. 

		// Todo: ��ũ��Ʈ �ڵ� ����. 

		// ���. 
		OnAutoModeRecursive();
	}
}
