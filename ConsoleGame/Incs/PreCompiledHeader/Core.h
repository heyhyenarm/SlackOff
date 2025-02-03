#pragma once

#include <iostream>
#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#ifdef ENGINE_EXPORTS	//ENGINE_EXPORTS ��ó���� ���ǰ� �߰��Ǿ��ִٸ� ENGINE_API ���Ǹ� DLL ��������� ����
#define ENGINE_API __declspec( dllexport )
#else	//ENGINE_EXPORTS ��ó���� ���ǰ� �߰��Ǿ����� �ʴٸ� ENGINE_API ���Ǹ� DLL ��������� ����
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



//Ű���� �Է� 

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



//�޸� ������ �˻��Ͽ� ��� â�� ����
inline void CheckMemoryLeak()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

//�α� ���� �з�
enum class ELogCategory
{
	Logging,
	Warning,
	Error
};


//�ܼ� ���� ����
const std::string SetColor(int color)
{
	//��� ��带 ���� �͹̳� ������ �ڵ� ���� ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	return ESC "color";
}

//�α� ��� â�� ����
template<typename... T>
void Log(ELogCategory category, const char* logTemp, T&&... args)
{
	//��� ��带 ���� �͹̳� ������ �ڵ� ���� ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return GetLastError();
	}

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return GetLastError();
	}

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(hOut, dwMode))
	{
		return GetLastError();
	}

	//���޹��� ���ڿ� �ּҰ��� ���ۿ� ����
	char buffer[512];
	snprintf(buffer, sizeof(buffer), logTemp, args ...);
	std::cout << buffer;

	//�� �α� ���ؿ� ���� ��� ��ȭ
	//�� �����ϱ�, ESC: \x1b[
	switch (category)
	{
	case(ELogCategory::Logging):
		std::cout << ESC << VT_FOREGROUND_WHITE_BRIGHT << buffer;
		break;
	case(ELogCategory::Warning):
		std::cout << ESC << VT_FOREGROUND_YELLOW << buffer;
		break;
	case(ELogCategory::Error):
		std::cout<< ESC << VT_FOREGROUND_RED << buffer;
		break;
	}
}

//Todo: �����ڵ� �߰��ϱ�
//template<typename... T>
//void Log(ELogCategory category, const wchar_t* logTemp, T&&... args)
//{
//	//��� ��带 ���� �͹̳� ������ �ڵ� ���� ����
//	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	if (hOut == INVALID_HANDLE_VALUE)
//	{
//		return GetLastError();
//	}
//
//	DWORD dwMode = 0;
//	if (!GetConsoleMode(hOut, &dwMode))
//	{
//		return GetLastError();
//	}
//
//	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
//	if (!SetConsoleMode(hOut, dwMode))
//	{
//		return GetLastError();
//	}
//
//	//���޹��� ���ڿ� �ּҰ��� ���ۿ� ����
//	char buffer[1024];
//	snprintf(buffer, sizeof(buffer), logTemp, args ...);
//	std::cout << buffer;
//
//	//�� �α� ���ؿ� ���� ��� ��ȭ
//	//�� �����ϱ�, ESC: \x1b[
//	switch (category)
//	{
//	case(ELogCategory::Logging):
//		std::cout << L << ESC << VT_FOREGROUND_WHITE_BRIGHT << buffer;
//		break;
//	case(ELogCategory::Warning):
//		std::cout << L << ESC << VT_FOREGROUND_YELLOW << buffer;
//		break;
//	case(ELogCategory::Error):
//		std::cout << L << ESC << VT_FOREGROUND_RED << buffer;
//		break;
//	}
//}



