#include <stdio.h>
#include <stdlib.h>
void MergeSort(int A[], int p, int r);
void Sort(int A[], int p, int q, int r);
int main() {
	int A[] = { 1,5,9,6,3,1,4,8,2,4,5 };
	MergeSort(A,0,sizeof(A)/sizeof(int) -1);
	int i;
	for (i = 0; i < sizeof(A) / sizeof(int); i++) printf("%d  ", A[i]);
	getchar();
}
void MergeSort(int A[],int p,int r) {
	if (p < r) {
		int q;
		q = (p + r) / 2;
		//printf("q = %d p = %d  r = %d\n", q,p,r);
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Sort(A, p, q, r);
	}

}
void Sort(int A[], int p, int q, int r) {
	int k;
	int *B, *C, n1, n2;
	n1 = q - p + 1;
	n2 = r - q;
	B = (int*)malloc((n1)*sizeof(int));
	C = (int*)malloc((n2)*sizeof(int));
	int i, j;
	for (i = 0; i < (n1); i++) B[i] = A[p + i];
	for (i = 0; i < (n2); i++) C[i] = A[q + i + 1];
	i = 0;
	j = 0;
	for (k = p; k <= r; k++) {
		if (i < n1 && j < n2)
		{
		if (B[i] > C[j]) A[k] = C[j++];
		else A[k] = B[i++];
		}
		else if (i == n1) { while (k <= r) { A[k++] = C[j++]; } }
		else if (j == n2) { while (k <= r) { A[k++] = B[i++]; } }
	}

		free(B);
		free(C);
	
}