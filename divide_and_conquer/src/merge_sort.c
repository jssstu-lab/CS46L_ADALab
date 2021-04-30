#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define DEBUG

int iter = 0;

void merge(int A[], int p, int q, int r) {
    // split A[p...q] and A[q+1...r]
    int n1 = q-p+1, 
        n2 = r-q,
        i, j, k;
    
    int L[n1], R[n2];
    for (i = 0; i < n1; i++, iter++) L[i] = A[p+i];
    for (i = 0; i < n2; i++, iter++) R[i] = A[q+i+1];
    
    // merge back to A[p...r]
    i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        A[k++] = (L[i] < R[j])? L[i++] : R[j++];
        iter++;
    }
    while (i < n1) { A[k++] = L[i++]; iter++; }
    while (j < n2) { A[k++] = R[j++]; iter++; }
}

void merge_sort(int A[], int low, int high) {
    if (low < high) {
        iter++;
        int mid = low + (high - low)/2;
        merge_sort(A, low, mid);
        merge_sort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

void merge_sort_helper(int A[], int n) {
    iter = 0;
    merge_sort(A, 0, n-1);
}

int main () {
	srand(time(0));
	FILE* f = fopen("graph.txt", "w");
	int *A, n;
	int i;
	for (n = 100; n <= 10000; n += 100) {
		A = (int*) malloc(n * sizeof(int));

		for (i = 0; i < n; i++)
			A[i] = rand() % 10000;
		merge_sort_helper(A, n);

#ifdef DEBUG
		printf("Sorted array : ");
		for (i = 0; i < n; i++)
			printf("%d ", A[i]);
		printf("\nIter : %d\n", iter);
#endif
		free(A);

		fprintf(f, "%d, %d\n", n, iter);
	}
	fclose(f);
	return 0;
}