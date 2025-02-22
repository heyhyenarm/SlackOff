#pragma once

#include <string>

struct TextImage
{
public:
	TextImage(std::wstring name, std::wstring image)
		: name(name), image(image)
	{

	}

private:
	std::wstring name;
	std::wstring image;
};

class Imges
{

private:

	TextImage characterDefault = TextImage(L"Default Hero", L"");
};