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
	// �޸� ����.
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

	// �̷� ����.
	RecursiveGenerateMaze(grid, width, height);

	// ���� �� ��ǥ ���� ����.
	startNode = new Node(Vector2(1, 1), nullptr);
	goalNode = new Node(Vector2(width - 2, height - 2), nullptr);

	// ���� �� ��ǥ ������ ���� ��η� ����.
	grid[startNode->position.y][startNode->position.x] = 0;
	grid[goalNode->position.y][goalNode->position.x] = 0;

	DisplayGrid(grid);
}

void Maze::RecursiveGenerateMaze(std::vector<std::vector<int>>& grid, int width, int height)
{
	// ��� ���� ������ ǥ��.
	std::vector<std::vector<int>> visited(height, std::vector<int>(width, 0));

	// ���� ���� ����. 
	std::stack<Vector2> stack;
	Vector2 start = Vector2(1, 1);
	stack.push(start);
	visited[start.y][start.x] = 1;
	grid[start.y][start.x] = 0;

	while (!stack.empty())
	{
		Vector2 current = stack.top();
		stack.pop();

		// �����¿�. 
		std::vector<Vector2> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

		// ������ ���� ������ ����.
		for (int i = 0; i < directions.size(); ++i)
		{
			int j = Random(0, directions.size() - 1);
			std::swap(directions[i], directions[j]);
		}

		for (const Vector2& direction : directions)
		{
			int newX = current.x + direction.x * 2;
			int newY = current.y + direction.y * 2;

			// �� üũ.
			if (newX > 0 && newX < width - 1 && newY > 0 && newY < height - 1 && visited[newY][newX] == 0)
			{
				visited[newY][newX] = 1;
				grid[newY][newX] = 0; // �ش� ���� ���� ��η� ����.
				grid[current.y + direction.y][current.x + direction.x] = 0; // �� �� ���� ���� ���� ��η� ����.

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