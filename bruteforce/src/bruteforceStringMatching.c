#include <stdio.h>
#include <string.h>

int iter = 0;

int bruteforceStringMatch(char* text, char* pattern) {
	iter = 0;

	int n = strlen(text);
	int m = strlen(pattern);
	int i, j;
	for (i = 0; i < n - m + 1; i++) {
		iter++;
		for (j = 0; j < m && pattern[j] == text[i+j]; j++)
			iter++;
		if (j == m) return i;
	}
	return -1;
}

int main() {
	char text[100];
	char pattern[100];
	
	printf("Enter text: ");
	scanf("%s", text);
	printf("Enter pattern: ");
	scanf("%s", pattern);

	int m = bruteforceStringMatch(text, pattern);
	if (m == -1) {
		printf("pattern not found in the string\n");
	} else {
		printf("pattern found in string at index %d taking %d iterations.\n", m, iter);
	}

	return 0;
}
