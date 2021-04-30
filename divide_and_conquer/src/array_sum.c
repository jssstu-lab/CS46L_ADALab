#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define DEBUG

int iter = 0;

int arraySum(int A[], int low, int high) {
    iter++;
    if (low > high) return 0;
    if (low == high) return A[low];
    int mid = low + (high - low)/2;
    return arraySum(A, low, mid) + arraySum(A, mid+1, high);
}

int arraySumHelper(int A[], int n) {
    iter = 0;
    return arraySum(A, 0, n-1);
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
	    int sum = arraySumHelper(A, n);

#ifdef DEBUG
		int tsum = 0, i = 0;
        for (i = 0; i < n; i++)
            tsum += A[i];
        printf("sum = %d | tsum = %d | iter = %d | ", sum, tsum, iter);
        if (tsum == sum) printf("PASS\n"); else printf("FAIL\n");
#endif
		free(A);

		fprintf(f, "%d, %d\n", n, iter);
	}
	fclose(f);
	return 0;
}