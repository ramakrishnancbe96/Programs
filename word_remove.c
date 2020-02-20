#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	int i,j, p = 0, c = 0;

	gets(s);

	for (i = 0; s[i]; ) {
		if (s[i] == ' ') {
			if (p % 2 != 0 && c % 2 == 0) {
				for (j = i+1; s[j]; j++)
					s[j-c-1] = s[j]; 
				s[j-c-1] = 0;
				i = i - c; 
				p = 0;
				c = 0;
			} else {
				p = c;
				c = 0;
				i++;
			}

		} else {
			c++;
			i++;
		}
	}

	if (p % 2 != 0 && c % 2 == 0)
		s[i - c -1] = 0;
	printf("%s\n", s);
	return 0;
}
