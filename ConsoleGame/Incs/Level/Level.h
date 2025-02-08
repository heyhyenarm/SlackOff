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

	// ���� ��û�� �� ���͸� �����ϴ� �Լ�.
	void ProcessAddedAndDestroyedActor();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	std::vector <Actor*> actors;

	// �߰� ��û�� ����.
	Actor* addRequestedActor = nullptr;
};