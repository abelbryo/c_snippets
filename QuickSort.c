#include <stdio.h>


int quickSortStep(int A[], int lo, int hi);
void quickSort(int A[], int lo, int hi);

int quickSortStep(int A[], int lo, int hi){
	int pivot = A[lo];
	
	do {
		while( hi > lo && A[hi] >= pivot)
			hi--;
		if(hi == lo)
		{
			break;
		}
		A[lo] = A[hi];
		lo++;
		
		while(hi > lo && A[lo] < pivot)
			lo++;
		if(hi == lo)
		{
			break;
		}
		A[hi] = A[lo];
		hi--;	
	} while(hi > lo);
	
	A[lo] = pivot;
	return lo;
}


void quickSort(int A[], int lo, int hi){
	if(hi <= lo)
	{
		return;
	}
	int pivotPosition = quickSortStep(A,lo,hi);
	quickSort(A, lo, pivotPosition - 1);
	quickSort(A, pivotPosition + 1, hi);
}

int main(){
	int A[] = {9, 8, 4, 5, 2, 1, 7, 3, 6};
	quickSort(A,0,8);
	int i;
	for(i = 0; i < 9; i++){
		printf("%d, ", A[i]);
	}
	printf("\n");
	
	return 0;
	
}







