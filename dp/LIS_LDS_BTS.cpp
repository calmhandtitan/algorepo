#include<bits/stdc++.h>
using namespace std;

class LongSequence
{
		int *lis, *lds, *bts;
	public:
		LongSequence()
		{
			lis = lds = bts = NULL;
		}
		int LIS(int *a, int n)
		{
			lis = (int*)malloc(sizeof(int)*n);
			fill(lis, lis+n, 1);

			for(int i = 0; i < n; i++)
				for(int j = 0; j < i; j++)
					if(a[i] > a[j] && lis[i] < lis[j] + 1)
						lis[i] = lis[j]+1;

			return *(max_element(lis, lis+n));
		}		

		int LDS(int *a, int n)
		{
			lds = (int*)malloc(n*sizeof(int));
			fill(lds, lds+n, 1);

			for(int i = 0; i < n; i++)
				for(int j = 0; j < i; j++)
					if(a[i] < a[j] && lds[i] < lds[j]+1)
						lds[i] = lds[j] + 1;

			return *(max_element(lds, lds+n));
		}
		int LBTS(int *a, int n)	
		{
			/*
				returns the length of longest bitonic sequence, which is
				first increasing and then decreasing
			*/
			if(lis == NULL)			
				int _lis = LIS(a, n);
			if(lds == NULL)
				int _lds = LDS(a, n);

			bts = (int*)malloc(sizeof(int)*n);

			for(int i = 0; i < n; i++)
			{
				bts[i] = lis[i] + lds[i] - 1;
			}
			return *(max_element(bts, bts+n));
		}

};





int main()
{
	int a[] = {2, 4, 1, 7, 0, 9, 5};
	int n = sizeof(a)/sizeof(int);

	LongSequence LS;
	int lis = LS.LIS(a, n);
	cout << "LIS is " << lis << endl;
	int lds = LS.LDS(a, n);
	cout << "LDS is " << lds << endl;
	int bts = LS.LBTS(a, n);
	cout << "Longest Bitonic Sequence is " << bts << endl;

	return 0;
}
