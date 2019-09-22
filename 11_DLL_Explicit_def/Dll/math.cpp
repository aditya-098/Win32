#include "math.h"

extern "C"
{

__declspec(dllexport) int  add(int iValue1, int iValue2, int iResult)
{
	printf("iValue1 = %d, iValue2 = %d",iValue1,iValue2);

	iResult = iValue1 + iValue2;
	printf("iResult = %d",iResult);

	return iResult;
	  
}

__declspec(dllexport) int sub(int iValue1, int iValue2, int iResult)
{
	printf("iValue1 = %d, iValue2 = %d", iValue1, iValue2);

	iResult = iValue1 - iValue2;
	printf("iResult = %d", iResult);

	return iResult;

}
	__declspec(dllexport) int mul(int iValue1, int iValue2, int iResult)
{
	printf("iValue1 = %d, iValue2 = %d", iValue1, iValue2);

	iResult = iValue1 * iValue2;
	printf("iResult = %d", iResult);

	return iResult;

}

//	__declspec(dllexport) float div(int iValue1, int iValue2, int iResult)
//{
//	/*printf("iValue1 = %d, iValue2 = %d", iValue1, iValue2);
//
//	iResult = (float)(iValue1 /iValue2);*/
//	//printf("iResult = %d", iResult);
//
////	return iResult;
//
//}

}