#include<bits/stdc++.h>
using namespace std;
#define MAX 10010

class Union_Find
{
	int parent[MAX], sz[MAX];
	public:
		Union_Find(int n)
		{
			for(int i = 0; i <= n; i++)
			{
				parent[i] = i;
				sz[i] = 1;
			}
		}

		int root(int i)
		{
			while(i != parent[i])
			{
				parent[i] = parent[parent[i]];
				i = parent[i];
			}
			return i;
		}

		int find(int p, int q)
		{
			return root(p) == root(q);
		}

		int unite(int p, int q)
		{
			int i = root(p);
			int j = root(q);
			
			if(sz[i] < sz[j])
			{
				parent[i] = parent[j];
				sz[j] += sz[i];
			}
			else
			{
				parent[j] = parent[i];
				sz[i] += sz[j];
			}
		}
		int getNumberOfCompo(int n)	//returns the number of disjoint sets
		{
			set<int> s;
			for(int i = 1; i <= n; i++)	//assuming 1 based index
			{
				s.insert(root(i));
			}
			return s.size();
		}
};


int main()
{
	int n, e, x, y;
	cin >> n >> e;
	Union_Find UF(n);
	for(int i = 0 ; i < e; i++)
	{
		cin >> x >> y;
		if(!UF.find(x, y))
			UF.unite(x, y);
	}
	cout << UF.getNumberOfCompo(n) << endl;
	return 0;
}
