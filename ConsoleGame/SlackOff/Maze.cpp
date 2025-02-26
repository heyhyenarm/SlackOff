#include "Maze.h"
#include "Algorithm/Node.h"
#include "Algorithm/AStar.h"

#include <stack>

Maze::Maze()
	: startNode(nullptr), goalNode(nullptr)
{
}

Maze::~Maze()
{
	// 메모리 해제.
	for (Node* node : openList)
	{
		SafeDelete(node);
	}
	openList.clear();

	for (Node* node : closedList)
	{
		SafeDelete(node);
	}
	closedList.clear();
}

void Maze::GenerateMaze(int width, int height)
{
	std::vector<std::vector<int>> grid(height, std::vector<int>(width, 1));

	// 미로 생성.
	RecursiveGenerateMaze(grid, width, height);

	// 시작 및 목표 지점 설정.
	startNode = new Node(Vector2(1, 1), nullptr);
	goalNode = new Node(Vector2(width - 2, height - 2), nullptr);

	// 시작 및 목표 지점이 열린 경로로 설정.
	grid[startNode->position.y][startNode->position.x] = 0;
	grid[goalNode->position.y][goalNode->position.x] = 0;

	DisplayGrid(grid);
}

void Maze::RecursiveGenerateMaze(std::vector<std::vector<int>>& grid, int width, int height)
{
	// 모든 셀을 벽으로 표시.
	std::vector<std::vector<int>> visited(height, std::vector<int>(width, 0));

	// 시작 지점 설정. 
	std::stack<Vector2> stack;
	Vector2 start = Vector2(1, 1);
	stack.push(start);
	visited[start.y][start.x] = 1;
	grid[start.y][start.x] = 0;

	while (!stack.empty())
	{
		Vector2 current = stack.top();
		stack.pop();

		// 상하좌우. 
		std::vector<Vector2> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

		// 랜덤한 방향 순서로 셔플.
		for (int i = 0; i < directions.size(); ++i)
		{
			int j = Random(0, directions.size() - 1);
			std::swap(directions[i], directions[j]);
		}

		for (const Vector2& direction : directions)
		{
			int newX = current.x + direction.x * 2;
			int newY = current.y + direction.y * 2;

			// 벽 체크.
			if (newX > 0 && newX < width - 1 && newY > 0 && newY < height - 1 && visited[newY][newX] == 0)
			{
				visited[newY][newX] = 1;
				grid[newY][newX] = 0; // 해당 셀을 열린 경로로 설정.
				grid[current.y + direction.y][current.x + direction.x] = 0; // 두 셀 사이 벽을 열린 경로로 설정.

				stack.push(Vector2(newX, newY));
			}
		}
	}
}

void Maze::DisplayGrid(const std::vector<std::vector<int>>& grid)
{
	for (const auto& row : grid)
	{
		for (int cell : row)
		{
			if (cell == 1)
			{
				//std::cout << "1";
				Log(LogCategoryType::Error, L"1");
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}