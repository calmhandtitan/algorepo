#include<bits/stdc++.h>
using namespace std;
#define MAX 10001
int F[MAX];

void compute_Prefix(char P[], int m)
{
	int i = 1, j = 0;
       	F[0] = 0;
	while(i < m)
	{
		if(P[i] == P[j])
		{
			F[i] = j + 1;
			i++;
			j++;
		}
		else if(j > 0)
			j = F[j-1];
		else
		{
			F[i] = 0;
			i++;
		}
	}
}

int KMP(char T[], int n, char P[], int m)
{
	int i = 0, j = 0;
	compute_Prefix(P, m);
	while(i < n)
	{
		if(T[i] == P[j])
		{
			if(j == m-1)	//successfull match
				return i-j;
			else
				i++, j++;
		}
		else if(j > 0)
			j = F[j-1];
		else
			i++;
	}
	return -1;
}

int main()
{
	char text[MAX], pattern[MAX];

	printf("Enter the text to search pattern in>>");
	scanf("%s", text);
	printf("Enter the pattern to search for>>");
	scanf("%s", pattern);

	int n = strlen(text);
	int m = strlen(pattern);

	int ans = KMP(text, n, pattern, m);

	if(ans == -1)
		printf("pattern not found\n");
	else
		printf("pattern found at index %d\n", ans);

	return 0;
}
