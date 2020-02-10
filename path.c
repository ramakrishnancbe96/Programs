/** 
 * Print all possible path from (0,0) to (n,n)
 */ 
#include <stdio.h>
#define INDEX 2

void path(int a[INDEX][INDEX], int i, int j, int *p, int k)
{
	if (i == INDEX -1) {
		int t;
		for (t = j; t < INDEX; t++) 
			p[k + t - j] = a[i][t]; 
		for (t = 0; t < (2 * INDEX) -1; t++)
			printf("%d ", p[t]);
		printf("\n");
		return;
	}

	if (j == INDEX -1) {
		int t;
		for (t = i; t < INDEX; t++) 
			p[k + t - i] = a[t][j]; 
		for (t = 0; t < (2 * INDEX) -1; t++)
			printf("%d ", p[t]);
		printf("\n");
		return;
	}

	p[k] = a[i][j];

	path(a, i + 1, j, p, k + 1);
	path(a, i, j + 1, p, k + 1);
}

int main()
{
	int a[INDEX][INDEX];
	int p[(2 * INDEX ) - 1], k = 0;
	int i, j;
	for (i = 0;i < INDEX; i++)
		for (j = 0;j < INDEX; j++)
			scanf("%d", &a[i][j]);
	path(a, 0, 0, p, 0);

	return 0;
}
