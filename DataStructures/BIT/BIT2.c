//Point sum query, Range update Binary Indexed tree
#include<stdio.h>

int BIT[10010], a[10010], n;

int query(int k)
{
	int s =0;
	while(k > 0)
	{
		s += BIT[k];
		k -= k & -k;
	}
	return s;
}

void update(int x, int v)
{
	while(x <= n)
	{
		BIT[x] += v;
		x += x & -x;
	}
}


int main()
{
	scanf("%d",&n);
	int i, x, y, v;
	for(i = 1; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		update(i, a[i]);
		update(i+1, -a[i]);
	}

	printf("Enter update query range[x..y]>>");
	scanf("%d %d",&x, &y);
	printf("Enter value v to update by>>");
	scanf("%d",&v);
	update(x, v);
	update(y+1, -v);
	for(i = x ; i <= y; i++)
		printf("updated %dth element is %d\n",i,query(i));
	
	return 0;
}
