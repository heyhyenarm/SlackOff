#include <iostream>
#include "Engine/Engine.h"

int main()
{
	CheckMemoryLeak();

	Log(ELogCategory::Warning, L"aaaaa\r\n");
}