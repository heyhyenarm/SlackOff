#pragma once

#include "Level/Level.h"

class LoadingLevel : public Level
{
	RTTI_DECLARATIONS(LoadingLevel, Level)

public:
	explicit LoadingLevel(std::wstring image);
	explicit LoadingLevel(std::wstring directory, FILE* file);
	~LoadingLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

private:
	std::wstring image;
};