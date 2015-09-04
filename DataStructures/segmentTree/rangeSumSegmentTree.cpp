#include<bits/stdc++.h>
using namespace std;

int *st;

int query(int *st, int start, int end, int qs, int qe, int idx)
{
	if(qs <= start && qe >= end)
		return st[idx];

	if(end < qs || start > qe)
		return 0;

	int mid = (start+end)/2;
	return query(st, start, mid, qs, qe, 2*idx+1) +
		query(st, mid+1, end, qs, qe, 2*idx+2);
}

void updateIt(int *st, int start, int end, int pos, int diff, int idx)
{
	if(pos < start || pos > end)
		return;

	st[idx] += diff;
	if(start != end)
	{
		int mid = (start+end)/2;
		updateIt(st, start, mid, pos, diff, 2*idx+1);
		updateIt(st, mid+1, end, pos, diff, 2*idx+2);
	}
}

void update(int a[], int n, int *st, int pos, int new_val)
{
	int diff = new_val - a[pos];
	a[pos] = new_val;

	updateIt(st, 0, n-1, pos, diff, 0);
}

int build(int a[], int start, int end, int *st, int idx)
{
	if(start == end)
	{
		st[idx] = a[start];
		return st[idx];
	}

	int mid = (start+end)/2;
	st[idx] = build(a, start, mid, st, 2*idx+1) +
		  build(a, mid+1, end, st, 2*idx+2);
	return st[idx];
}

void init(int a[], int n)
{
	int x = (int)ceil(log2(n));
	int max_size = 2*(int)pow(2, x) - 1;

	st = (int*)malloc(sizeof(int)*max_size);
	build(a, 0, n-1, st, 0);
}

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a)/sizeof(a[0]);

	init(a, n);
	cout << query(st, 0, n-1, 0, 2, 0) << endl;//query sum from a[0]-a[2]
	update(a, n, st, 2, 5);	//update a[2] -> 5
	cout << query(st, 0, n-1, 1, 3, 0) << endl;//query sum from a[1]-a[3]
	return 0;
}	
