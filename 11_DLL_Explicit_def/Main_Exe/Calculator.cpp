
#include "..\Win32Project1\math.h"
#include <stdio.h>
#include <windows.h>


typedef int (*PFADD)(int, int, int);
typedef int(*PFSUB)(int, int, int);
typedef int(*PFMUL)(int, int, int);


int main()
{

	getchar();
	HMODULE hHandle;
	hHandle = LoadLibrary(L"Win32Project1.dll");
	if(!hHandle)
	{
		printf("LoadLibrary Failed!! (%u)",GetLastError());
	}
	int a=5, b=5, c;
	
	PFADD pfAdd;
	PFSUB pfSub;
	PFMUL pfMul;

	getchar();
	pfAdd =(PFADD) GetProcAddress(hHandle,"add");
	if(!pfAdd)
	{
		printf("GetProcAddress Error add (%u)\n",GetLastError());
		return FALSE;
	}
	printf("ADD = %d\n", pfAdd(a, b, c));


	getchar();
	pfAdd = (PFSUB)GetProcAddress(hHandle, "sub");
	if (!pfAdd)
	{
		printf("GetProcAddress Error sub (%u)\n", GetLastError());
		return FALSE;
	}
	printf("sub = %d\n", pfSub(a, b, c));


	getchar();
	pfAdd = (PFMUL)GetProcAddress(hHandle, "mul");
	if (!pfAdd)
	{ 
		printf("GetProcAddress Error mul (%u)\n", GetLastError());
		return FALSE;
	}
	printf("mul = %d\n", pfMul(a, b, c));

	FreeLibrary(hHandle);
	
	getchar();
	
	//printf("div = %f\n",div(a,b,c));
}


	