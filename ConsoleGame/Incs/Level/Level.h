#pragma once

#include "Core.h"
#include "RTTI.h"
#include <Vector>

class Actor;
class ENGINE_API Level : public RTTI
{
	RTTI_DECLARATIONS(Level, RTTI)

public:
	explicit Level();
	virtual ~Level();

	void AddActor(Actor* newActor);

	// 삭제 요청이 된 액터를 정리하는 함수.
	void ProcessAddedAndDestroyedActor();

	//프레임 업데이트. 
	virtual void Update(float deltaTime);
	//콘솔 화면에 그리기. 
	virtual void Draw();
	//Todo: 레벨 준비 완료 콜백. 

protected:

	std::vector <Actor*> actors;

	// 추가 요청된 액터.
	Actor* addRequestedActor = nullptr;
};