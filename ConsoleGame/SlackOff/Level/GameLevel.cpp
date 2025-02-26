#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Game.h"
#include "Engine/Timer.h"
#include "Actor/EventActor.h"
#include "Actor/Exit.h"
#include "Actor/Monster.h"
#include "Actor/Ground.h"

GameLevel::GameLevel()
	: Level()
{
	//image = LoadFileCPP("../Assets/Images/hero/img_hero_default.txt");
	image = "test game";
	Init();
}

GameLevel::~GameLevel()
{
	delete hero;
	hero = nullptr;
}

void GameLevel::Init()
{
	// 주인공 생성. 
	hero = new Hero();

	//LoadMap();
	// @Test.
	LoadTestMap();

	// 플레이어 입력 대기 상태. 
	isWaitingPlayer = true;
}

void GameLevel::LoadMap()
{
	FILE* file = nullptr;
	fopen_s(&file, "../Assets/txt_map.txt", "rb");

	// 파일 처리. 
	if (file == nullptr)
	{
		std::cout << "맵 파일 열기 실패\n";
		__debugbreak();
		return;
	}

	// 파일 열기. 
	fseek(file, 0, SEEK_END);
	size_t readSize = ftell(file);
	rewind(file);

	// 파일 읽어 버퍼에 담기. 
	char* buffer = new char[readSize + 1];
	size_t bytesRead = fread(buffer, 1, readSize, file);

	if (readSize != bytesRead)
	{
		__debugbreak();
		return;
	}

	buffer[readSize] = '/0';

	// 파일 읽기 전용 인덱스. 
	int index = 0;

	// 좌표 계산을 위한 변수 선언. 
	int xPosition = 0;
	int yPosition = 0;

	// 파싱. 
	// h(주인공).
	// e(이벤트 장소). 
	// m(몬스터).
	// d(탈출구). 
	// 1(벽). 
	// .(이동 가능 영역).
	while (index < (int)bytesRead)
	{
		// 한 문자씩 읽기.
		char mapChar = buffer[index++];

		// 개행 문자 처리. 
		if (mapChar == '\n')
		{
			++yPosition;
			xPosition = 0;
			continue;
		}

		// 플레이어 시작 위치 추가. 
		if (mapChar == 'h')
		{
			//startPosition.emplace_back(Vector2(xPosition, yPosition));
			//gameMap.emplace_back(hero);
		}

		// 이벤트 장소 추가. 
		else if (mapChar == 'e')
		{
			// Todo: 이벤트 액터 생성하기. 
			//gameMap.emplace_back(new Event());
		}

		// 몬스터 추가.
		else if (mapChar == 'm')
		{
			//monsterList.emplace_back(new Monster());
			//gameMap.emplace_back(monsterList.back());
		}
		
		// 탈출구 추가.
		else if (mapChar == 'd')
		{
			//gameMap.emplace_back(new Exit());
		}

		// 이동 가능 영역 추가. 
		else if (mapChar == '.')
		{
			//gameMap.emplace_back(new Ground());
		}

		++xPosition;
	}
}

// @Test.
void GameLevel::LoadTestMap()
{
	// 그리드 생성.
	// 0: 이동 가능.
	// 1: 이동 불가(장애물).
	// 2: 시작 위치.
	// 3: 목표 위치.
	testMap =
	{
		//{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		//{ 1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 1, 1 },
		//{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4, 1 },
		//{ 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1 },
		//{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		//{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		//{ 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1 },
		//{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
		//{ 1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1 },
		//{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },

		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 0, 1, 3, 1, 0, 1, 3, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 3, 1, 0, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0, 0, 3, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 3, 1, 0, 1},
		{1, 0, 3, 0, 0, 0, 1, 0, 3, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1, 1, 3, 1, 0, 1, 0, 1},
		{1, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 3, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 4, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},

	};

	// 맵에서 시작 위치 목표 위치 검색.
	startNode = nullptr;
	exitNode = nullptr;

	bool initialized = false;
	for (int y = 0; y < (int)testMap.size(); ++y)
	{
		for (int x = 0; x < (int)testMap[0].size(); ++x)
		{
			// 시작 지점.
			if (testMap[y][x] == 2)
			{
				startNode = new Node(Vector2(x,y));
				testMap[y][x] = 0;
				hero->SetPosition(Vector2(x, y));
				continue;
			}

			// 중간 목표 지점들. 
			if (testMap[y][x] == 3)
			{
				targetList.emplace_back(new Node(Vector2(x, y)));
				testMap[y][x] = 0;
				continue;
			}

			// 탈출구. 
			if (testMap[y][x] == 4)
			{
				exitNode = new Node(Vector2(x, y));
				testMap[y][x] = 0;
				continue;
			}
		}
	}
}

void GameLevel::Start()
{
	//neglectClock.StartClock();
	//RequestPlayerInput();
}

//void GameLevel::RequestPlayerInput()
//{
//	Engine::Get().SetCursorPosition(0, 1);
//	Log(LogCategoryType::Logging, L"command : front, left, right, back\n");
//	autoClock->StartClock();
//
//	//return PlayerInputLog(L"input");
//}

bool GameLevel::PlayerInputLog(std::string input, std::string* outValue)
{
	// 주인공에 메시지 보내기. 
	//Todo: 입력 예외 상황 처리하기. 
	if (input == "front")
	{
		//주인공 앞으로 이동. 
		std::wcout << "input front\n";
		outValue = &input;
		return true;
	}
	else if (input == "left")
	{
		//주인공 왼쪽으로 이동. 
		std::wcout << "input left\n";
		outValue = &input;
		return true;
	}
	else if (input == "right")
	{
		//주인공 오른쪽으로 이동. 
		std::wcout << "input right\n";
		outValue = &input;
		return true;
	}
	else if (input == "back")
	{
		//주인공 뒤로 이동. 
		std::wcout << "input back\n";
		outValue = &input;
		return true;
	}

	std::wcout << "wrong command\n";
	return false;
}

void GameLevel::PrintScriptHero()
{
}

void GameLevel::OnAutoMode()
{
	// 첫 목적지 찾기. 
	if (nowPath.empty())
	{
		FindPath();
	}

	static auto nowNodeIter = ++nowPath.begin();

	// 주인공 랜덤 길 이동 모드. 
	if (!nowPath.empty())
	{
		// 목표 위치에 도착한 경우 혹은 플레이어 대기 모드 진입 시 까지. 
		while (!isWaitingPlayer)
		{
			Sleep(1000);

			// 주인공의 현재 위치와 노드 nowNode 위치 비교. 
			Vector2 heroPos = hero->GetPosition();

			Vector2 direction = (*nowNodeIter)->position - heroPos;

			// 주인공 목표 위치로 이동하기. 
			hero->Move(direction);

			// 현재 목적지가 탈출구라면 엔딩. 
			if ((*nowNodeIter)->position == exitNode->position)
			{
				// @Test: A* 출력. 
				aStar.DisplayGridWithPath(testMap, nowPath);
				std::cout << "Escape!\n";
				// 엔딩 레벨 로드하기. 
				Sleep(1000);
				Game::Get().LoadLevel(LevelType::EndingLevel);
				return;
			}

			++nowNodeIter;

			// 현재 목적지가 중간 목적지라면. 
			if (nowNodeIter == nowPath.end())
			{
				// @Test: A* 출력. 
				aStar.DisplayGridWithPath(testMap, nowPath);

				// 중간 목적지 중 마지막 목적지라면 현재 길 탈출구로 지정하기. 
				if (targetList.empty())
				{
					std::cout << "find exit door. \n";
					nowPath = aStar.FindPath(new Node(hero->GetPosition()), exitNode, testMap);
					nowNodeIter = nowPath.begin();
				}
				// 다음 중간 목적지 찾기. 
				else
				{
					std::cout << "event!";
					// Todo: 이벤트 진행하기. 

					std::cout << "find next target.\n";
					FindPath();
					nowNodeIter = nowPath.begin();
				}
			}
		}
	}
}

void GameLevel::FindPath()
{
	auto target = targetList.begin();

	// 길 초기화. 
	nowPath.clear();

	// 경로 탐색.
	nowPath = aStar.FindPath(new Node(hero->GetPosition()), *target, testMap);
	targetList.erase(target);
}

void GameLevel::PlayerCommandProcess()
{
	std::thread thread1([&]()
		{
			char inputBuffer[100] = { };
			//Engine::Get().SetCursorPosition(0, 5);
			//Log(LogCategoryType::Logging, L"command : front, left, right, back\n");
			std::cout << "command : front, left, right, back\n";

			//Engine::Get().SetCursorPosition(0, 6);
			// 플레이어 입력 받음. 
			std::cin >> inputBuffer;
			hasPlayerInput = true;
			std::cout << inputBuffer << "\n";

			// 명령어 판별하기. 
			std::string input;
			if (PlayerInputLog(inputBuffer, &input))
			{
				//ManageSavedLog(input);
			}
		}
	);
	thread1.detach();
}

void GameLevel::ManageSavedLog(std::wstring& log)
{
	// 최대 로그 수 미만인 경우, 뒤에 저장. 
	if (savedLogs.size() < MAX_LOG)
	{
		savedLogs.emplace_back(log);
	}

	// 최대 로그 수 이상인 경우, 가장 처음 로그 삭제 후 뒤에 저장. 
	auto first = savedLogs.begin();
	savedLogs.erase(first);
	savedLogs.emplace_back(log);
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//Todo: 플레이어 input이 없이 일정 시간이 지나면 자동으로 주인공 스크립트 출력. 
	// 자동 진행 타이머 생성. 
	static Timer autoTimer(AUTO_TIME);

	//Todo: 일정 시간이 지나면 자동으로 엔딩 레벨 불러오기. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::EndingLevel);
	}

	// 플레이어 명령어 대기 모드인 경우. 
	if (isWaitingPlayer)
	{
		//std::wcout << "isWaitingPlayer On\n";

		// 타이머 켜기. 
		autoTimer.Update(deltaTime);
		Engine::Get().SetCursorPosition(0, 3);
		//std::cout << AUTO_TIME - autoTimer.GetTime() << "초\n";

		// 플레이어 입력 대기. 
		if (onThread)
		{
			PlayerCommandProcess();
			onThread = false;
		}

		// 입력 받았다면. 
		if (hasPlayerInput)
		{
			Engine::Get().ClearScreen();
			autoTimer.Reset();
			isWaitingPlayer = true;
			onThread = true;
			hasPlayerInput = false;
		}

		if (autoTimer.IsTimeOut())
		{
			std::cout << "시간 초과. \n";
			isWaitingPlayer = false;

			Sleep(1000);
			Engine::Get().ClearScreen();
			OnAutoMode();
			return;
		}
	}
}

void GameLevel::Draw()
{
	Super::Draw();

	//게임 이미지 출력하기. 
	Engine::Get().SetCursorPosition(0, 0);
	//Log(LogCategoryType::Logging, image.c_str());
	std::cout << image;

	//std::cout << LoadFileCPP("../Assets/Images/hero/Log/log_1.txt");

}
