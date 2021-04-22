#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int count = 0;

int gcd_euclid(int m, int n) {
	count = 0;
	while (n != 0) {
		count++;
		int r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int gcd_cicm(int a, int b) {
	count = 0;
	int t = (a > b)? b : a;
	while (t > 0) {
		count++;
		if (a % t == 0 && b % t == 0)
			return t;
		t--;
	}
	return -1;
}

int gcd_msm(int a, int b) {
	count = 0;
	int t = (a > b)? b : a;
	int primes[t+1];
	int i, k;
	for (i = 0; i < t+1; i++)
		primes[i] = 1;
	primes[1] = 0, primes[0] = 0;
	int ans = 1;
	for (i = 2; i <= t; i++) {
		if (!primes[i])
			continue;
		for (k = 2*i; k <= t; k += i) {
			count++;
			primes[k] = 0;
		}

		while (a % i == 0 && b % i == 0) {
			count++;
			ans *= i;
			a /= i;
			b /= i;
		}
	}
}

int main() {
	srand(time(0));
	printf("Enter number of iterations: ");
	int t, i;
	scanf("%d", &t);
	
	FILE* feuclid = fopen("euclid.txt", "a");
	FILE* fcicm = fopen("cicm.txt", "a");
	FILE* fmsm = fopen("msm.txt", "a");
	
	int n = rand() % 100;
	int m = rand() % 100;

	for (i = 0; i < t; i++) {
		n += rand() % 100;
		m += rand() % 100;
		
		printf("GCD(%d %d) using euclid: %d\n", n, m, gcd_euclid(n, m));
		fprintf(feuclid, "%d, %d\n", (m > n)? m : n, count);

		printf("GCD(%d %d) using consecutive integer checking method: %d\n",n, m, gcd_cicm(n, m));
		fprintf(fcicm, "%d, %d\n", (m > n)? m : n, count);
		
		printf("GCD(%d %d) using middle school method: %d\n\n\n", n, m, gcd_msm(n, m));
		fprintf(fmsm, "%d, %d\n", (m > n)? m : n, count);
	}

	fclose(feuclid);
	fclose(fcicm);
	fclose(fmsm);

	return 0;
}
