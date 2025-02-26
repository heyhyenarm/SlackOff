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
	// ���ΰ� ����. 
	hero = new Hero();

	//LoadMap();
	// @Test.
	LoadTestMap();

	// �÷��̾� �Է� ��� ����. 
	isWaitingPlayer = true;
}

void GameLevel::LoadMap()
{
	FILE* file = nullptr;
	fopen_s(&file, "../Assets/txt_map.txt", "rb");

	// ���� ó��. 
	if (file == nullptr)
	{
		std::cout << "�� ���� ���� ����\n";
		__debugbreak();
		return;
	}

	// ���� ����. 
	fseek(file, 0, SEEK_END);
	size_t readSize = ftell(file);
	rewind(file);

	// ���� �о� ���ۿ� ���. 
	char* buffer = new char[readSize + 1];
	size_t bytesRead = fread(buffer, 1, readSize, file);

	if (readSize != bytesRead)
	{
		__debugbreak();
		return;
	}

	buffer[readSize] = '/0';

	// ���� �б� ���� �ε���. 
	int index = 0;

	// ��ǥ ����� ���� ���� ����. 
	int xPosition = 0;
	int yPosition = 0;

	// �Ľ�. 
	// h(���ΰ�).
	// e(�̺�Ʈ ���). 
	// m(����).
	// d(Ż�ⱸ). 
	// 1(��). 
	// .(�̵� ���� ����).
	while (index < (int)bytesRead)
	{
		// �� ���ھ� �б�.
		char mapChar = buffer[index++];

		// ���� ���� ó��. 
		if (mapChar == '\n')
		{
			++yPosition;
			xPosition = 0;
			continue;
		}

		// �÷��̾� ���� ��ġ �߰�. 
		if (mapChar == 'h')
		{
			//startPosition.emplace_back(Vector2(xPosition, yPosition));
			//gameMap.emplace_back(hero);
		}

		// �̺�Ʈ ��� �߰�. 
		else if (mapChar == 'e')
		{
			// Todo: �̺�Ʈ ���� �����ϱ�. 
			//gameMap.emplace_back(new Event());
		}

		// ���� �߰�.
		else if (mapChar == 'm')
		{
			//monsterList.emplace_back(new Monster());
			//gameMap.emplace_back(monsterList.back());
		}
		
		// Ż�ⱸ �߰�.
		else if (mapChar == 'd')
		{
			//gameMap.emplace_back(new Exit());
		}

		// �̵� ���� ���� �߰�. 
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
	// �׸��� ����.
	// 0: �̵� ����.
	// 1: �̵� �Ұ�(��ֹ�).
	// 2: ���� ��ġ.
	// 3: ��ǥ ��ġ.
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

	// �ʿ��� ���� ��ġ ��ǥ ��ġ �˻�.
	startNode = nullptr;
	exitNode = nullptr;

	bool initialized = false;
	for (int y = 0; y < (int)testMap.size(); ++y)
	{
		for (int x = 0; x < (int)testMap[0].size(); ++x)
		{
			// ���� ����.
			if (testMap[y][x] == 2)
			{
				startNode = new Node(Vector2(x,y));
				testMap[y][x] = 0;
				hero->SetPosition(Vector2(x, y));
				continue;
			}

			// �߰� ��ǥ ������. 
			if (testMap[y][x] == 3)
			{
				targetList.emplace_back(new Node(Vector2(x, y)));
				testMap[y][x] = 0;
				continue;
			}

			// Ż�ⱸ. 
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
	// ���ΰ��� �޽��� ������. 
	//Todo: �Է� ���� ��Ȳ ó���ϱ�. 
	if (input == "front")
	{
		//���ΰ� ������ �̵�. 
		std::wcout << "input front\n";
		outValue = &input;
		return true;
	}
	else if (input == "left")
	{
		//���ΰ� �������� �̵�. 
		std::wcout << "input left\n";
		outValue = &input;
		return true;
	}
	else if (input == "right")
	{
		//���ΰ� ���������� �̵�. 
		std::wcout << "input right\n";
		outValue = &input;
		return true;
	}
	else if (input == "back")
	{
		//���ΰ� �ڷ� �̵�. 
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
	// ù ������ ã��. 
	if (nowPath.empty())
	{
		FindPath();
	}

	static auto nowNodeIter = ++nowPath.begin();

	// ���ΰ� ���� �� �̵� ���. 
	if (!nowPath.empty())
	{
		// ��ǥ ��ġ�� ������ ��� Ȥ�� �÷��̾� ��� ��� ���� �� ����. 
		while (!isWaitingPlayer)
		{
			Sleep(1000);

			// ���ΰ��� ���� ��ġ�� ��� nowNode ��ġ ��. 
			Vector2 heroPos = hero->GetPosition();

			Vector2 direction = (*nowNodeIter)->position - heroPos;

			// ���ΰ� ��ǥ ��ġ�� �̵��ϱ�. 
			hero->Move(direction);

			// ���� �������� Ż�ⱸ��� ����. 
			if ((*nowNodeIter)->position == exitNode->position)
			{
				// @Test: A* ���. 
				aStar.DisplayGridWithPath(testMap, nowPath);
				std::cout << "Escape!\n";
				// ���� ���� �ε��ϱ�. 
				Sleep(1000);
				Game::Get().LoadLevel(LevelType::EndingLevel);
				return;
			}

			++nowNodeIter;

			// ���� �������� �߰� ���������. 
			if (nowNodeIter == nowPath.end())
			{
				// @Test: A* ���. 
				aStar.DisplayGridWithPath(testMap, nowPath);

				// �߰� ������ �� ������ ��������� ���� �� Ż�ⱸ�� �����ϱ�. 
				if (targetList.empty())
				{
					std::cout << "find exit door. \n";
					nowPath = aStar.FindPath(new Node(hero->GetPosition()), exitNode, testMap);
					nowNodeIter = nowPath.begin();
				}
				// ���� �߰� ������ ã��. 
				else
				{
					std::cout << "event!";
					// Todo: �̺�Ʈ �����ϱ�. 

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

	// �� �ʱ�ȭ. 
	nowPath.clear();

	// ��� Ž��.
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
			// �÷��̾� �Է� ����. 
			std::cin >> inputBuffer;
			hasPlayerInput = true;
			std::cout << inputBuffer << "\n";

			// ��ɾ� �Ǻ��ϱ�. 
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
	// �ִ� �α� �� �̸��� ���, �ڿ� ����. 
	if (savedLogs.size() < MAX_LOG)
	{
		savedLogs.emplace_back(log);
	}

	// �ִ� �α� �� �̻��� ���, ���� ó�� �α� ���� �� �ڿ� ����. 
	auto first = savedLogs.begin();
	savedLogs.erase(first);
	savedLogs.emplace_back(log);
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//Todo: �÷��̾� input�� ���� ���� �ð��� ������ �ڵ����� ���ΰ� ��ũ��Ʈ ���. 
	// �ڵ� ���� Ÿ�̸� ����. 
	static Timer autoTimer(AUTO_TIME);

	//Todo: ���� �ð��� ������ �ڵ����� ���� ���� �ҷ�����. 
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		Game::Get().LoadLevel(LevelType::EndingLevel);
	}

	// �÷��̾� ��ɾ� ��� ����� ���. 
	if (isWaitingPlayer)
	{
		//std::wcout << "isWaitingPlayer On\n";

		// Ÿ�̸� �ѱ�. 
		autoTimer.Update(deltaTime);
		Engine::Get().SetCursorPosition(0, 3);
		//std::cout << AUTO_TIME - autoTimer.GetTime() << "��\n";

		// �÷��̾� �Է� ���. 
		if (onThread)
		{
			PlayerCommandProcess();
			onThread = false;
		}

		// �Է� �޾Ҵٸ�. 
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
			std::cout << "�ð� �ʰ�. \n";
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

	//���� �̹��� ����ϱ�. 
	Engine::Get().SetCursorPosition(0, 0);
	//Log(LogCategoryType::Logging, image.c_str());
	std::cout << image;

	//std::cout << LoadFileCPP("../Assets/Images/hero/Log/log_1.txt");

}
