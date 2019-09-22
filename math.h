#include <windows.h>
#include <stdio.h>

extern "C"
{
	__declspec(dllexport) int add(int iValue1,
	int iValue2,
	int iResult
	);

	__declspec(dllexport) int sub(int iValue1,
	int iValue2,
	int iResult);

	__declspec(dllexport) int mul(int iValue1,
	int iValue2,
	int iResult);
}
	