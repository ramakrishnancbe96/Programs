#include <stdio.h>

void merger(int a[], int l, int m, int r)
{
	int left[10], right[10], i,j, k = 0, n1 = 0, n2 = 0;

	for (i = l; i <= m; i++) {
		left[k++] = a[i];
		n1++;
	}

	k = 0;
	for (i = m+1; i <= r; i++) {
		right[k++] = a[i];
		n2++;
	}

	k = l;
	i = 0;
	j = 0;
	while (i < n1 && j < n2)
	{
		if (left[i] < right[j]) {
			a[k] = left[i];
			k++;
			i++;
		} else {
			a[k] = right[j];
			k++;
			j++;
		}
	}

	while (i < n1) {
		a[k] = left[i];
		k++;
		i++;
	}

	while (j < n2) {
		a[k] = right[j];
		k++;
		j++;
	}

}

void split(int a[], int l, int r)
{
	if (l >= r)
		return;

	int m = l + (r - l) / 2;

	split(a, l, m);
	split(a, m+1, r);

	merger(a, l, m, r);
}

int main()
{
	int n;

	scanf("%d", &n);
	int a[n];
	int i, m;

	for (i=0; i < n; i++)
		scanf("%d", &a[i]);

	m = n/2;
	split(a, 0, n-1);

	for (i=0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
