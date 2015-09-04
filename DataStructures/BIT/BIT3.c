//Range Sum Query, Range update Binary Indexed tree
#include<stdio.h>

int BIT[10010], n, a[10010];

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

void update(int k, int v)
{
	while(k <= n)
	{
		BIT[k] += v;
		k += k & -k;
	}
}

int main()
{
	int i, x, y, v;
	scanf("%d",&n);
	printf("Enter array elements>>"	);
	for(i = 1 ; i <= n; i++)
	{
		scanf("%d",&a[i]);	
		update(i, a[i]);
	}

	printf("Enter range[x..y]  for update>>\n");
	scanf("%d %d",&x,&y);
	printf("sum of elements of range[%d..%d] is %d\n", x, y, query(y) - query(x-1));
	printf("Enter value to update with>>");
	scanf("%d",&v);
	update(x, v);
	update(y+1, -v);
	printf("updated sum of elements of range[%d..%d] is %d\n", x, y, query(y) - query(x-1));
	
	return 0;
}
