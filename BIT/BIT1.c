//Point Update, Range Sum Query Binary Indexed Tree
//Author: Chandan Mittal
#include<stdio.h>

int BIT[100010], n, a[100010];

void update(int x, int v)
{
	while(x <= n)
	{
		BIT[x] += v;
		x += x & -x;
	}
}

int query(int k)
{
	int s = 0;
	while(k > 0)
	{
		s += BIT[k];
		k -= k & -k;
	}
	return s;
}

int main()
{
	printf("Enter size of array>>");
	scanf("%d",&n);
	int i, q, r;
	printf("Enter array elements\n");
	for(i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		update(i , a[i]);
	}
	printf("Enter range [x..y]>>");
	scanf("%d %d",&q,&r);
	printf("sum of elements of range [%d..%d] is %d\n",q,r,query(r) - query(q-1));

	return 0;
}
