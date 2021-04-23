#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iter = 0;

int search_linear(int A[], int n, int key) {
	iter = 0;
	for (int i = 0; i < n; i++) {
		iter++;
		if (A[i] == key)
			return i;
	}
	return -1;
}

int search_binary(int A[], int n, int key) {
	iter = 0;
	int l = 0, h = n-1;
	while (l <= h) {
		iter++;
		int mid = l + (h-l)/2;
		if (A[mid] == key) return mid;
		if (A[mid] > key) h = mid - 1;
		if (A[mid] < key) l = mid + 1;
	}
	return -1;
}

int main() {
	srand(time(0));
	FILE* flinear = fopen("linear.txt", "w");
	FILE* fbinary = fopen("binary.txt", "w");
	
	int *A, n, i;

	for (n = 10; n <= 500; n += 10) {
		A = (int*) malloc(n * sizeof(int));
		A[0] = rand() % 10;
		for (i = 1; i < n; i++)
			A[i] = A[i-1] + rand() % 10;
		
		search_linear(A, n, A[n-1]+1);
		fprintf(flinear, "%d, %d\n", n, iter);

		search_binary(A, n, A[n-1]+1);
		fprintf(fbinary, "%d, %d\n", n, iter);

		free(A);
	}

	fclose(flinear);
	fclose(fbinary);
	return 0;
}
