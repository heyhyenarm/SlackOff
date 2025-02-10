#pragma once

#include "Core.h"
#include "RTTI.h"
#include <Vector>

class Actor;
class ENGINE_API Level : public RTTI
{
	RTTI_DECLARATIONS(Level, RTTI)

public:
	Level();
	virtual ~Level();

	void AddActor(Actor* newActor);

	// 삭제 요청이 된 액터를 정리하는 함수.
	void ProcessAddedAndDestroyedActor();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	std::vector <Actor*> actors;

	// 추가 요청된 액터.
	Actor* addRequestedActor = nullptr;
};