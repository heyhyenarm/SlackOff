#pragma once

#include "Level/Level.h"

class EndingLevel : public Level
{
	RTTI_DECLARATIONS(EndingLevel, Level)

public:
	explicit EndingLevel(std::wstring image);
	explicit EndingLevel(std::wstring directory, FILE* file);
	~EndingLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

private:
	std::wstring image;
};