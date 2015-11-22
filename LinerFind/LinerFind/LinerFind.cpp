// LinerFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int LinerFind(int A[], int Target, int sPos, int ePos);
int main()
{
	int A[] = { 5,8,5,8,5,2,5,1,4,3,4,3,4,2,6,1,2,6,1,5 };
	int pos = -1;
	int startPos = 0;
	do {
		startPos = pos + 1;
		pos = LinerFind(A, 5,startPos , sizeof(A) / sizeof(int));
		printf("%d \n", pos);
	} while (pos != -1);
	getchar();
}
int LinerFind(int A[], int Target, int sPos, int ePos) {
	int nPos;
	nPos = sPos;
	//if (sPos > ePos) return -1;
	while (1){
		if (A[nPos] == Target) return nPos;
		if (nPos >= ePos) return -1;
		nPos++;
		//getchar();
	}

}
