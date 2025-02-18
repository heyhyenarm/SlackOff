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

	// 주인공 자동 진행 모드 메시지.  
	void OnAutoMode();

	// 주인공 자동 진행 모드 해제 메시지. 
	void OffAutoMode();

private:
	
	// 주인공 자동 진행 재귀 메소드. 
	void OnAutoModeRecursive();

private:

	// 주인공 생명력. 
	int hp = 0;

	// 자동 진행 모드 현황. 
	bool isAutoMode = false;
};