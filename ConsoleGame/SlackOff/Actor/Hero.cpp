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

void Hero::Move(Vector2 direction)
{
	std::cout << "direction: " << direction.x << ", " << direction.y << "\n";

	// �����¿� �̵�. 
	// ��. 
	if (direction.y == 1)
	{
		std::cout << "auto move, up\n";
		SetPosition(Vector2(position.x, position.y + 1));
	}
	// ��. 
	else if (direction.y == -1)
	{
		std::cout << "auto move, down\n";
		SetPosition(Vector2(position.x, position.y - 1));
	}

	// ��. 
	if (direction.x == 1)
	{
		std::cout << "auto move, right\n";
		SetPosition(Vector2(position.x + 1, position.y));
	}
	// ��. 
	else if (direction.x == -1)
	{
		std::cout << "auto move, left\n";
		SetPosition(Vector2(position.x - 1, position.y));
	}

	//if (direction == Vector2::Up)
	//{
	//	std::cout << "auto move, up\n";
	//}
	//else if (direction == Vector2::Down)
	//{
	//	std::cout << "auto move, down\n";
	//}
	//else if (direction == Vector2::Right)
	//{
	//	std::cout << "auto move, right\n";
	//}
	//else if (direction == Vector2::Left)
	//{
	//	std::cout << "auto move, left\n";
	//}

	//SetPosition(position + direction);
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
