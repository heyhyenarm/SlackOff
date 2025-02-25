#pragma once

#include "Actor/Actor.h"

class Monster : public Actor
{
	RTTI_DECLARATIONS(Monster, Actor)

public:
	Monster();
	~Monster() = default;

	virtual void Update(float delatTime)override;
	virtual void Draw() override;

	inline virtual void SetPosition(const Vector2& newPosition) override { position = newPosition; };

private:
	void AutoMove();
};