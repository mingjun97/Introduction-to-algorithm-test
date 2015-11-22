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
void MergeSort(int A[],int p,int r) { //�ݹ���û��ڴ˹���
	if (p < r) {
		int q;
		q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Sort(A, p, q, r);
	}

}
void Sort(int A[],int p,int q,int r) { //���򲿷�
	int k;
	int *B, *C, n1, n2;
	//----------insert
	n1 = q - p + 1;
	n2 = r - q;
	//----------------
	/*malloc�÷����ͣ�
		malloc���ڴ�����һ��յأ��ض��������С���Ա���к������㡣
		������ɺ���Ҫ��free���ͷ�������Ŀռ䣬����ᱬը��
	*/
	B = (int*)malloc((n1 + 1)*sizeof(int)); //��B���鶨��Ϊn1+1�Ĵ�С ���� n1 + 1 ��������ű����B��0...n1���������A��p...q����Ԫ��
	C = (int*)malloc((n2 + 1)*sizeof(int)); //��C���鶨��Ϊn2+1�Ĵ�С ͬ��
	int i, j;
	B[n1] = -B[n1]; //���������� windows�г�ʼֵ������Сֵ������ֱ�ӼӸ����š���
	C[n2] = B[n1];	//ͬ��
	//��A���������鵼�뵽BC
	for (i = 0; i < (n1); i++) B[i] = A[p + i];
	for (i = 0; i < (n2); i++) C[i] = A[q + i + 1];
	i = 0;
	j = 0;

	//**************�������ֵ������㷨
	for (k = p; k <= r; k++) {
		if (B[i] > C[j]) A[k] = C[j++];
		else A[k] = B[i++];
	}
	free(B);
	free(C);
}