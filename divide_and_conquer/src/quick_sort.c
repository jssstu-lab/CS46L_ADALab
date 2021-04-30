#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG

int iter = 0;

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low, j = high + 1;
    while (i <= j) {
        do { i++; iter++; } while (pivot >= A[i]);
        do { j--; iter++; } while (pivot <  A[j]);
        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quick_sort(int A[], int low, int high) {
    if (low < high) {
        iter++;
        int k = partition(A, low, high);
        quick_sort(A, low, k-1);
        quick_sort(A, k+1, high);
    }
}

void quick_sort_helper(int A[], int n) {
    iter = 0;
    quick_sort(A, 0, n-1);
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
		quick_sort_helper(A, n);

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