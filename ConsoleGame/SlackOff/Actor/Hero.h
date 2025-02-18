#pragma once

#include "Actor/Actor.h"

class Hero : public Actor
{
	RTTI_DECLARATIONS(Hero, Actor)

public:
	Hero();
	~Hero();

	virtual void Update(float delatTime)override;
	virtual void Draw() override;

	inline virtual void SetPosition(const Vector2& newPosition) override { position = newPosition; };

	inline int GetHP() { return hp; }

	// ���ΰ� �ڵ� ���� ��� �޽���.  
	void OnAutoMode();

	// ���ΰ� �ڵ� ���� ��� ���� �޽���. 
	void OffAutoMode();

private:
	
	// ���ΰ� �ڵ� ���� ��� �޼ҵ�. 
	void OnAutoModeRecursive();

private:

	// ���ΰ� �����. 
	int hp = 0;

	// �ڵ� ���� ��� ��Ȳ. 
	bool isAutoMode = false;
};