#include <iostream>
#include<cstdio>
using namespace std;
void merge(int A[], int p, int q, int r){
	int *L, *R;
	int i, j, k;
	int lsize = q-p+1, rsize = r-q;
	L=(int*)malloc(sizeof(int)*lsize+1);
	R=(int*)malloc(sizeof(int)*rsize+1);
	for(i=0; i<lsize; i++){
		L[i] = A[i+p];
	}
	L[i] = INT_MAX;
	for(j=0; j<rsize; j++){
		R[j] = A[j+q+1];
	}
	R[j] = INT_MAX;
	i=0;
	j=0;
	for(k=p;k<=r;){
		if(L[i] <= R[j])
            {
			A[k] = L[i];
			k++;
			i++;
		}
		else {
			A[k] = R[j];
			k++;
			j++;
		}
	}
}

void mergeSort(int A[], int p, int r){
	int q;
	if(p<r){
		q = (p+r)/2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main(){
	int i,n;
	cin>>n;
	int A[n];
	for(i=0; i<n; i++)
    cin>>A[i];
	mergeSort(A, 0, n-1);
	//printf("\n");
	for(i=0; i<n; i++)
		printf("%d ", A[i]);
}
