#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Uncomment this line if you want to see the program's output
// in stdout
// #define DEBUG

int iter = 0;

void selectionSort(int A[], int n) {
	iter = 0;
	int i, j;
	for (i = 0; i < n-1; i++) {
		int pos = i;
		for (j = i+1; j < n; j++) {
			iter++;
			if (A[pos] > A[j])
				pos = j;
		}

		int temp  = A[pos];
		A[pos] = A[i];
		A[i] = temp;
	}
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
		selectionSort(A, n);
		
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
