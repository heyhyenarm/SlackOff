#include "PreCompiledHeader.h"

#include "Engine.h"
#include <Windows.h>
#include <iostream>

#include "Level/Level.h"
#include "Actor/Actor.h"

#include <time.h>

#define SCREEN_X 150
#define SCREEN_Y 100
#define TITLE "SLACK-OFF"

// 스태틱 변수 초기화.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr), screenSize(SCREEN_X, SCREEN_Y)
{
	// 랜덤 시드 설정.
	srand((unsigned int)time(nullptr));

	// 싱글톤 객체 설정.
	instance = this;

	// 기본 타겟 프레임 속도 설정.
	SetTargetFrameRate(60.0f);

	// Todo: 콘솔 크기, 제목 설정. 
	char command[100] = {};
	sprintf_s(command, "mode con: cols=%d lines=%d", SCREEN_X, SCREEN_Y);
	system(command);

//	// 화면 지울 때 사용할 버퍼 초기화.
//	// 1. 버퍼 크기 할당.
//	emptyStringBuffer = new char[(screenSize.x + 1) * screenSize.y + 1];
//
//	// 버퍼 덮어쓰기.
//	memset(emptyStringBuffer, ' ', (screenSize.x + 1) * screenSize.y + 1);
//
//	// 2. 값 할당.
//	for (int y = 0; y < screenSize.y; ++y)
//	{
//		// 각 줄 끝에 개행 문자 추가.
//		emptyStringBuffer[(y * (screenSize.x + 1)) + screenSize.x] = '\n';
//	}
//
//	// 마지막에 널 문자 추가.
//	emptyStringBuffer[(screenSize.x + 1) * screenSize.y] = '\0';
//
//	// 디버깅.
//#if _DEBUG
//	char buffer[16000];
//	strcpy_s(buffer, 16000, emptyStringBuffer);
//#endif
}

Engine::~Engine()
{
	// 메인 레벨 메모리 해제.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
		mainLevel = nullptr;
	}

	//// 클리어 버퍼 삭제.
	//delete[] emptyStringBuffer;
}

void Engine::Run()
{
	// 시작 타임 스탬프 저장.
	// timeGetTime 함수는 밀리세컨드(1/1000초) 단위.
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;

	// CPU 시계 사용.
	// 시스템 시계 -> 고해상도 카운터. (10000000).
	// 메인보드에 시계가 있음.
	LARGE_INTEGER frequency;
	//혜림 : QueryPerformanceFrequency는 퍼포먼스 카운터의 빈도
	QueryPerformanceFrequency(&frequency);

	//std::cout << "Frequency: " << frequency.QuadPart << "\n";

	// 시작 시간 및 이전 시간을 위한 변수.
	LARGE_INTEGER time;
	//혜림 : QueryPerformanceCounter는 퍼포먼스 카운터의 수
	QueryPerformanceCounter(&time);

	//혜림 : QuadPart로 LARGE_INTEGER에서 int64_t 형식으로 뽑아옴
	int64_t currentTime = time.QuadPart;
	int64_t previousTime = currentTime;

	// 프레임 제한.
	//float targetFrameRate = 90.0f;

	// 한 프레임 시간 계산.
	//float targetOneFrameTime = 1.0f / targetFrameRate;

	// Game-Loop.
	while (true)
	{
		// 종료 조건.
		if (quit)
		{
			break;
		}

		// 현재 프레임 시간 저장.
		//time = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		// 프레임 시간 계산.
		//혜림 : (현재 퍼포먼스 카운트 - 이전 카운드)를 퍼포먼스 빈도록 나누면 프레임 시간이 나온다. 
		float deltaTime = static_cast<float>(currentTime - previousTime) /
			static_cast<float>(frequency.QuadPart);

		// 한 프레임 시간 계산.
		float targetOneFrameTime = 1.0f / targetFrameRate;

		// 프레임 확인.
		if (deltaTime >= targetOneFrameTime)	//한 프레임 시간 값을 넘어갈 경우 업데이트 처리
		{
			// 입력 처리 (현재 키의 눌림 상태 확인).
			ProcessInput();

			// 업데이트 가능한 상태에서만 프레임 업데이트 처리.
			if (shouldUpdate)
			{
				Update(deltaTime);
				Draw();
			}

			// 키 상태 저장.
			SavePreviouseKeyStates();

			// 이전 프레임 시간 저장.
			previousTime = currentTime;

			// 액터 정리 (삭제 요청된 액터들 정리).
			if (mainLevel)
			{
				//mainLevel->DestroyActor();
				mainLevel->ProcessAddedAndDestroyedActor();
			}

			// 프레임 활성화.
			shouldUpdate = true;
		}

		//Sleep(1);
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// 기존 레벨이 있다면 삭제 후 교체.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
		mainLevel = nullptr;
	}

	// 메인 레벨 설정.
	mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
	// 예외 처리.
	if (mainLevel == nullptr)
	{
		return;
	}

	// 레벨에 액터 추가.
	shouldUpdate = false;
	mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
	// 예외 처리.
	if (mainLevel == nullptr)
	{
		return;
	}

	// 레벨에 액터 추가.
	shouldUpdate = false;
	targetActor->Destroy();
}

void Engine::SetCursorType(CursorType cursorType)
{
	// 1. 커서 속성 구조체 설정.
	CONSOLE_CURSOR_INFO info = { };

	// 타입 별로 구조체 값 설정.
	switch (cursorType)
	{
	case CursorType::NoCursor:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;

	case CursorType::SolidCursor:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;

	case CursorType::NormalCursor:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;

	}

	// 2. 설정.
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Engine::SetCursorPosition(const Vector2& position)
{
	SetCursorPosition(position.x, position.y);
}

void Engine::SetCursorPosition(int x, int y)
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { static_cast<short>(x), static_cast<short>(y) };
	SetConsoleCursorPosition(handle, coord);
}

void Engine::SetTitle(const wchar_t* title)
{
	//SetTitle(title);

	// 가상 콘솔 창 모드. 
	system("\x1b]0;<SlackOff><ST>");
}

void Engine::SetFontSize(int fontSize)
{
	static CONSOLE_FONT_INFOEX fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	wcscpy_s(fontex.FaceName, L"Consolas");
	fontex.dwFontSize.X = 0;
	fontex.dwFontSize.Y = fontSize;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}

void Engine::SetTargetFrameRate(float targetFrameRate)
{
	this->targetFrameRate = targetFrameRate;
	targetOneFrameTime = 1.0f / targetFrameRate;
}

void Engine::ClearScreen()
{
	Clear();
}

bool Engine::GetKey(int key)
{
	return keyState[key].wasKeyDown;
}

bool Engine::GetKeyDown(int key)
{
	return keyState[key].isKeyDown && !keyState[key].wasKeyDown;
}

bool Engine::GetKeyUp(int key)
{
	return !keyState[key].isKeyDown && keyState[key].wasKeyDown;
}

void Engine::QuitGame()
{
	// 종료 플래그 설정.
	quit = true;
}

Engine& Engine::Get()
{
	// 싱글톤 객체 반환.
	return *instance;
}

void Engine::ProcessInput()
{
	//키보드 입력 처리. 
	for (int ix = 0; ix < 255; ++ix)
	{
		//혜림: 이전에 눌렸지만, 현재 눌리지 않은 상태도 false로 반환하기 위해 비트연산. 비트연산 하지 않으면 true로 반환하기 때문.
		keyState[ix].isKeyDown = (GetAsyncKeyState(ix) & 0x8000) ? true : false;
	}

	//Todo: 마우스 입력 처리. 
}

void Engine::Update(float deltaTime)
{
	// 레벨 업데이트.
	if (mainLevel != nullptr)
	{
		mainLevel->Update(deltaTime);
	}
}

void Engine::Clear()
{
	// 화면의 (0,0)으로 이동.
	//SetCursorPosition(0, 0);

	// 화면 지우기.
	//std::cout << emptyStringBuffer;

	//int height = 25;
	//for (int ix = 0; ix < height; ++ix)
	//{
	//	std::cout << "                               \n";
	//}

	system("cls");
	// 화면의 (0,0)으로 이동.
	SetCursorPosition(0, 0);
}

void Engine::Draw()
{
	// 화면 지우기.
	//Clear();

	// 레벨 그리기.
	if (mainLevel != nullptr)
	{
		mainLevel->Draw();
	}
}

void Engine::SavePreviouseKeyStates()
{
	for (int ix = 0; ix < 255; ++ix)
	{
		keyState[ix].wasKeyDown = keyState[ix].isKeyDown;
	}
}