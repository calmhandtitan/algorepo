/*
	Closest point pair problem
	Algo: Line sweep algorithm
	Complexity: O(NlogN)
	handle: calmhandtitan
*/
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define py first	
#define px second
#define mp make_pair
#define debug 0

const int MAX = 1e5;
const lli INF = 1LL<<60;

typedef pair<lli, lli> point;
point p[MAX];		//p[i] is y, x; see macro defined
set<point> s;
map<point, int> mapp;
int n;
double best;

bool cmp(point a, point b) { return a.px < b.px; }

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{	
		scanf("%lld %lld", &p[i].px, &p[i].py);	//assuming all points are integral coordinates
		mapp[p[i]] = i;				//since all the point are unique
	}
	sort(p, p+n, cmp);	//sort in increasing order of x coordinate	
	best = INF;		//let minimum dist be INF
	s.insert(p[0]);		//this is the active set
	int left = 0, pos1, pos2;
	for(int i = 1; i < n; i++)
	{
		while(left < i and p[i].px - p[left].px > best) 	s.erase(p[left++]);
		for(typeof(s.begin()) it = s.lower_bound(mp(p[i].py - best, p[i].px - best)); it != s.end() and p[i].py + best >= it->py; it++)
		{
			double d =  sqrt(pow(p[i].py - it->py, 2.0) + pow(p[i].px - it->px, 2.0));
			if(d < best)
			{
				best = d;
				pos1 = mapp[p[i]], pos2 = mapp[*it];
			}
		}
		s.insert(p[i]);
	}
	if(pos1 > pos2) swap(pos1, pos2);
	printf("%d %d %.6lf\n", pos1, pos2, best);
	return 0;
}
