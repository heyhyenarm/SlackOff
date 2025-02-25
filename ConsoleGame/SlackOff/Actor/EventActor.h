#pragma once

#include "Actor/Actor.h"

// 이벤트 타입. 
enum class EventType
{
	Item,
	Trap,
	Empty
};

class EventActor : public Actor
{
	RTTI_DECLARATIONS(EventActor, Actor)

public:
	EventActor();
	~EventActor() = default;

	virtual void Update(float delatTime)override;
	virtual void Draw() override;

	inline virtual void SetPosition(const Vector2& newPosition) override { position = newPosition; };

private:

};