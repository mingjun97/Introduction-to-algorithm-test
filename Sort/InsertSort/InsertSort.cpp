#include <stdio.h>
void InsertSort(int A[], int Ubound);
int main() {
	int A[] = { 55,8,1,12,3,4,2,6,8,7,5,1,3,44,55,23,11,62,15 };
	InsertSort(A,sizeof(A)/sizeof(int));
	int i;
	for (i = 0; i < sizeof(A) / sizeof(int); i++) printf("%d  ", A[i]);
	getchar();
}
void InsertSort(int A[],int Ubound) {
	int i,key,j;
	for (i = 1; i < Ubound; i++)
	{
		key = A[i];
		j = i - 1;
		while (A[j] > key && j >= 0) {
			A[j + 1] = A[j--];
		}
		A[j+1] = key;
	}

}