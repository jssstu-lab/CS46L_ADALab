#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Uncomment this line if you want to see the program's output
// in stdout
// #define DEBUG

int iter = 0;

void bubbleSort(int A[], int n) {
	iter = 0;
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			iter++;
			if (A[j] > A[j+1]) {
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
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
		bubbleSort(A, n);

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
