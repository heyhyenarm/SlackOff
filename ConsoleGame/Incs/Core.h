#pragma once

#include <iostream>
#include <Windows.h>
#include <wchar.h>
#include <tchar.h>
#include <string>
#include <locale>
#include <vector>
#include <fstream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#ifdef ENGINE_EXPORTS	//ENGINE_EXPORTS ��ó���� ���ǰ� �߰��Ǿ��ִٸ� ENGINE_API ���Ǹ� DLL ��������� ����.
#define ENGINE_API __declspec( dllexport )
#else	//ENGINE_EXPORTS ��ó���� ���ǰ� �߰��Ǿ����� �ʴٸ� ENGINE_API ���Ǹ� DLL ��������� ����.
#define ENGINE_API __declspec( dllimport )
#endif

#define ESC "\x1b["

//���� �͹̳� �ؽ�Ʈ �� ����
//Foreground
#define VT_FOREGROUND_BLACK 30
#define VT_FOREGROUND_RED 31
#define VT_FOREGROUND_GREEN 32
#define VT_FOREGROUND_YELLOW 33
#define VT_FOREGROUND_BLUE 34
#define VT_FOREGROUND_MAGENTA 35
#define VT_FOREGROUND_CYAN 36
#define VT_FOREGROUND_WHITE 37
#define VT_FOREGROUND_EXTENDED 38
#define VT_FOREGROUND_DEFAULT 39
//Background
#define VT_BACKGROUND_BLACK 40
#define VT_BACKGROUND_RED 41
#define VT_BACKROUND_GREEN 42
#define VT_BACKGROUND_YELLOW 43
#define VT_BACKGROUND_BLUE 44
#define VT_BACKGROUND_MAGENTA 45
#define VT_BACKGROUND_CYAN 46
#define VT_BACKGROUND_WHITE 47
#define VT_BACKGROUND_EXTENDED 48
#define VT_BACKGROUND_DEFAULT 49
//Foreground_Bright
#define VT_FOREGROUND_BLACK_BRIGHT 90
#define VT_FOREGROUND_RED_BRIGHT 91
#define VT_FOREGROUND_GREEN_BRIGHT 92
#define VT_FOREGROUND_YELLOW_BRIGHT 93
#define VT_FOREGROUND_BLUE_BRIGHT 94
#define VT_FOREGROUND_MAGENTA_BRIGHT 95
#define VT_FOREGROUND_CYAN_BRIGHT 96
#define VT_FOREGROUND_WHITE_BRIGHT 97
//Background_Bright
#define VT_BACKGROUND_BLACK_BRIGHT 100
#define VT_BACKGROUND_RED_BRIGHT 101
#define VT_BACKROUND_GREEN_BRIGHT 102
#define VT_BACKGROUND_YELLOW_BRIGHT 103
#define VT_BACKGROUND_BLUE_BRIGHT 104
#define VT_BACKGROUND_MAGENTA_BRIGHT 105
#define VT_BACKGROUND_CYAN_BRIGHT 106
#define VT_BACKGROUND_WHITE_BRIGHT 107


enum class Color : unsigned short
{
	Red = VT_FOREGROUND_RED,
	Green = VT_FOREGROUND_GREEN,
	Blue = VT_FOREGROUND_BLUE,
	White = VT_FOREGROUND_WHITE,
};



//Ű���� �Է� .

/*
 * Virtual Keys, Standard Set
 */
#define VK_LBUTTON        0x01
#define VK_RBUTTON        0x02
#define VK_CANCEL         0x03
#define VK_MBUTTON        0x04    /* NOT contiguous with L & RBUTTON */

#if(_WIN32_WINNT >= 0x0500)
#define VK_XBUTTON1       0x05    /* NOT contiguous with L & RBUTTON */
#define VK_XBUTTON2       0x06    /* NOT contiguous with L & RBUTTON */
#endif /* _WIN32_WINNT >= 0x0500 */

 /*
  * 0x07 : reserved
  */


#define VK_BACK           0x08
#define VK_TAB            0x09

  /*
   * 0x0A - 0x0B : reserved
   */

#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D

   /*
	* 0x0E - 0x0F : unassigned
	*/

#define VK_SHIFT          0x10
#define VK_CONTROL        0x11
#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14

#define VK_KANA           0x15
#define VK_HANGEUL        0x15  /* old name - should be here for compatibility */
#define VK_HANGUL         0x15
#define VK_IME_ON         0x16
#define VK_JUNJA          0x17
#define VK_FINAL          0x18
#define VK_HANJA          0x19
#define VK_KANJI          0x19
#define VK_IME_OFF        0x1A

#define VK_ESCAPE         0x1B

#define VK_CONVERT        0x1C
#define VK_NONCONVERT     0x1D
#define VK_ACCEPT         0x1E
#define VK_MODECHANGE     0x1F

#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0x2E
#define VK_HELP           0x2F


//���콺 �̺�Ʈ. 
#define WM_MOUSEFIRST                   0x0200
#define WM_MOUSEMOVE                    0x0200
#define WM_LBUTTONDOWN                  0x0201
#define WM_LBUTTONUP                    0x0202
#define WM_LBUTTONDBLCLK                0x0203
#define WM_RBUTTONDOWN                  0x0204
#define WM_RBUTTONUP                    0x0205
#define WM_RBUTTONDBLCLK                0x0206
#define WM_MBUTTONDOWN                  0x0207
#define WM_MBUTTONUP                    0x0208
#define WM_MBUTTONDBLCLK                0x0209

//�޸� ������ �˻��Ͽ� ��� â�� ����.
inline void CheckMemoryLeak()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

//�α� ���� �з�. 
enum class LogCategoryType
{
	Logging,
	Warning,
	Error
};


////�ܼ� ���� ����.
////�α� ��� â�� ����.
//template<typename... T>
//void Log(ELogCategory category, const char* logTemp, T&&... args)
//{
//	//��� ��带 ���� �͹̳� ������ �ڵ� ���� ����.
//	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	DWORD dwMode = 0;
//	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
//
//	SetConsoleMode(hOut, dwMode);
//
//	//���޹��� ���ڿ� �ּҰ��� ���ۿ� ����.
//	char buffer[1024];
//	snprintf(buffer, sizeof(buffer), logTemp, args ...);
//	//std::cout << buffer;
//
//	//�� �α� ���ؿ� ���� ��� ��ȭ.
//	//�� �����ϱ�, ESC: \x1b[
//	switch (category)
//	{
//	case(ELogCategory::Logging):
//		printf_s("%s%d%s", ESC, VT_FOREGROUND_WHITE_BRIGHT, buffer);
//		//SetColor(Color::White);
//		break;
//	case(ELogCategory::Warning):
//		//std::cout << ESC << VT_FOREGROUND_YELLOW << buffer;
//		printf_s("%s%d%s", ESC, VT_FOREGROUND_YELLOW, buffer);
//		//SetColor(Color::Blue);
//		break;
//	case(ELogCategory::Error):
//		//std::cout<< ESC << VT_FOREGROUND_RED << buffer;
//		printf_s("%s%d%s", ESC, VT_FOREGROUND_RED, buffer);
//		//SetColor(Color::Red);
//		break;
//	}
//
//	std::cout << buffer;
//}

// �ܼ� ��� �Լ�. 
template<typename... T>
void Log(LogCategoryType category, const wchar_t* logTemp, T&&... args)
{
	//��� ��带 ���� �͹̳� ������ �ڵ� ���� ����.
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	//���޹��� ���ڿ� �ּҰ��� ���ۿ� ����.
	wchar_t buffer[1024];
	swprintf(buffer, sizeof(buffer)*sizeof(_TCHAR), logTemp, args ...);

	int color = VT_FOREGROUND_WHITE;
	//�� �α� ���ؿ� ���� ��� ��ȭ.
	//�� �����ϱ�, ESC: \x1b[
	switch (category)
	{
	case(LogCategoryType::Logging):
		color = VT_FOREGROUND_WHITE_BRIGHT;
		break;
	case(LogCategoryType::Warning):
		color = VT_FOREGROUND_YELLOW;
		//wprintf(ESC L"%dm%s", VT_FOREGROUND_YELLOW, buffer);
		//std::wcout << ESC << (L"%dm", VT_FOREGROUND_YELLOW) << buffer;
		break;
	case(LogCategoryType::Error):
		color = VT_FOREGROUND_RED;
		break;
	}
	wprintf(ESC TEXT("%dm%s"), color, buffer);
}

template<typename... T>
void LogAnimation(const char* logTemp, T&&... args)
{
	//��� ��带 ���� �͹̳� ������ �ڵ� ���� ����.
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	//���޹��� ���ڿ� �ּҰ��� ���ۿ� ����.
	char buffer[1024];
	swprintf(buffer, sizeof(buffer), logTemp, args ...);

	for (int i = 0;i < (int)sizeof(logTemp);++i)
	{
		std::cout << buffer[i];
		Sleep(0.2);
	}
}


inline void ClearLogLine(const char* emptyBuffer)
{
	printf(emptyBuffer);
}

// ���� �Լ�. 
inline int Random(int min, int max)
{
	int diff = (max - min) - 1;
	return (diff * rand()) / (RAND_MAX + 1) + min;
}

//// Todo: ������ ���� �Լ�. 
//const std::vector<int> RandomVector(std::vector<int>& list)
//{
//	// ������� ���. 
//	if (list.empty())
//	{
//		std::cout << "vector is empty, cannot RandomVector. ";
//		return;
//	}
//	int count = (int)list.size();
//	int randomCount = count;
//	auto targetPos = list.begin();
//
//	// �迭�� ����ŭ �ݺ�, ������� ������ �ε����� �̾� ����. 
//	while (randomCount > 0)
//	{
//		int randomIndex = Random(0, count - 1);
//		auto randomValue = list.begin() + randomIndex;
//
//		// ��� ���� ��������. 
//		auto targetValue = list.erase(randomValue);
//
//		// Todo: ���� ��� �����ϱ�. 
//		// ��� ���� �� Ȥ�� �ڷ� �����ϱ�. 
//		bool isBack = (bool)Random(0, 1);
//		isBack ? list.emplace_back(targetValue) : list.insert(targetPos, targetValue);
//
//		// ��� ���� ������ ��ġ�� �����ϱ�. 
//		//list.insert(randomValue, count, );
//
//		--randomCount;
//	}
//
//	for (int value : list)
//	{
//		int temp = list[Random(0, count - 1)];
//
//	}
//}

//// �迭 ���� �Լ�. 
//template<typename T>
//inline T Rullet(const std::vector<T> list)
//{
//	int count = (int)list.size();
//
//	// ���� �ε��� �� ��������. 
//	int randomIndex = Random(0, count - 1);
//	
//
//}

// �ؽ�Ʈ ������ �о� wstring���� ��ȯ. 
inline std::wstring WLoadFile(const std::wstring directory)
{
	//SetConsoleOutputCP(CP_UTF8);
	//std::locale::global(std::locale(""));

	//���� �ҷ�����.
	FILE* file = nullptr;
	errno_t err;
	err = _wfopen_s(&file, directory.c_str(), TEXT("rb, ccs=UTF-8"));
	if (err != 0)
	{
		wprintf(TEXT("LoadFile Failed\n"));
		return nullptr;
	}
	else
	{
		wprintf(TEXT("LoadFile Success\n"));

		fseek(file, 0, SEEK_END);
		size_t readSize = ftell(file) / sizeof(wchar_t);
		rewind(file);
		wchar_t* buffer = new wchar_t[readSize + 1];
		memset(buffer, L' ', readSize);
		size_t bytesRead = fread(buffer, 1, readSize, file);
		buffer[readSize] = '\0';
		std::wstring fileString;
		return buffer;
		//while (std::fgetws(buffer, readSize, file))
		//{
		//	fileString += buffer;
		//}
		//std::fclose(file);
		//
		//return fileString;
		//printf_s(&buffer[0]);
	}
}

inline std::string LoadFile(const std::string directory)
{
	FILE* file = nullptr;
	fopen_s(&file, directory.c_str(), "rb");
	if (file == nullptr)
	{
		std::cout << "�� ���� ���� ����.\n";
		__debugbreak();
		//return;
	}
	fseek(file, 0, SEEK_END);

	size_t readSize = ftell(file);
	rewind(file);

	char* buffer = new char[readSize + 1];
	memset(buffer, ' ', readSize);
	fread(buffer, 1, readSize, file);
	buffer[readSize] = '\0';
	fclose(file);
	return buffer;
}

inline std::string LoadFileUTF(const std::string directory)
{
	std::ifstream file(directory);
	std::string fileString;

	if (file.is_open())
	{
		while (std::getline(file, fileString))
		{

		}

		return fileString;
	}
}


// ��Ʈ�� �ļ�. 
inline std::wstring Split(const std::wstring str, const std::wstring separator)
{
	//���ڿ� ����. 
	int size = (int)sizeof(str);
	wchar_t* string = new wchar_t[size];
	//wcscpy(string, str.c_str());
	wcscpy_s(string, size, str.c_str());

	wchar_t* token;
	wchar_t* context = new wchar_t[(int)sizeof(str)] {};
	token = wcstok_s(string, separator.c_str(), &context);
	while (token != nullptr)
	{
		std::wcout << token;

		//���� ��ū ��������. 
		token = wcstok_s(nullptr, separator.c_str(), &context);
	}

	//delete string;
}