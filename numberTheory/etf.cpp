#include<bits/stdc++.h>
using namespace std;

const int MAX = 100010;
int phi[MAX];

void prePhi()	//O(NlogN) precomputation of phi
{

	for (int i = 1; i < MAX; i++) phi[i] = i;
	for (int i = 2; i < MAX; i++)
		if (phi[i] == i)
		{
			phi[i]--;
			for (int j = i * 2; j < MAX; j += i)
				phi[j] -= phi[j] / i;
		}
}


int main()
{	
	prePhi();
	for(int i = 0; i < 10; i++)
		cout << phi[i] << " ";
	cout << endl;
	return 0;
}
