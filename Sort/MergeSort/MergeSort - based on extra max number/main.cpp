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
void MergeSort(int A[],int p,int r) { //递归调用基于此过程
	if (p < r) {
		int q;
		q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Sort(A, p, q, r);
	}

}
void Sort(int A[],int p,int q,int r) { //排序部分
	int k;
	int *B, *C, n1, n2;
	//----------insert
	n1 = q - p + 1;
	n2 = r - q;
	//----------------
	/*malloc用法解释：
		malloc向内存申请一块空地，重定义数组大小，以便进行后续运算。
		申请完成后需要用free来释放所申请的空间，否则会爆炸。
	*/
	B = (int*)malloc((n1 + 1)*sizeof(int)); //将B数组定义为n1+1的大小 其中 n1 + 1 的用来存放标兵，B【0...n1】用来存放A【p...q】的元素
	C = (int*)malloc((n2 + 1)*sizeof(int)); //将C数组定义为n2+1的大小 同上
	int i, j;
	B[n1] = -B[n1]; //定义标兵变量 windows中初始值疑似最小值，所以直接加个负号。。
	C[n2] = B[n1];	//同上
	//将A中数组数组导入到BC
	for (i = 0; i < (n1); i++) B[i] = A[p + i];
	for (i = 0; i < (n2); i++) C[i] = A[q + i + 1];
	i = 0;
	j = 0;

	//**************基于最大值标兵的算法
	for (k = p; k <= r; k++) {
		if (B[i] > C[j]) A[k] = C[j++];
		else A[k] = B[i++];
	}
	free(B);
	free(C);
}