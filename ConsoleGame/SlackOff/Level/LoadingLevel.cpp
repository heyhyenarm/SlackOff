#include "LoadingLevel.h"

LoadingLevel::LoadingLevel(std::wstring image)
	: Level(), image(image)
{
}

LoadingLevel::LoadingLevel(std::wstring directory, FILE* file)
	: Level()
{
}

LoadingLevel::~LoadingLevel()
{
}

void LoadingLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);
}

void LoadingLevel::Draw()
{
	Super::Draw();
}
