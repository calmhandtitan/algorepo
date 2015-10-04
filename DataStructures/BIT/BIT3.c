#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define CLR(d) memset(d, 0, sizeof(d))
#define lli long long int

int inline inp()
{
    int n=0;
    char c=getchar_unlocked();
    while(c < '0' || c >'9') {c=getchar_unlocked();}
    while(c>='0' && c<='9')
    {
        n=(n<<3)+(n<<1)+c-'0';
        c=getchar_unlocked();
    }
    return n;
}

int n;
lli BIT1[100010], BIT2[100010];

lli query1(int k)
{
    lli s = 0;
    while( k > 0)
    {
        s += BIT1[k];
        k -= k & -k;
    }
    return s;
}

void update1(int k, lli v)
{
    while(k <= n)
    {
        BIT1[k] += v;
        k += k & -k;
    }
}

lli query2(int k)
{
    lli s = 0;
    while( k > 0)
    {
        s += BIT2[k];
        k -= k & -k;
    }
    return s;
}

void update2(int k, lli v)
{
    while(k <= n)
    {
        BIT2[k] += v;
        k += k & -k;
    }
}

int main()
{
    int t, c, p, q, z;
    lli  v1, v2, v;
    t = inp();
    while(t--)
    {
        CLR(BIT1);
        CLR(BIT2);
        n = inp();
        c = inp();

        while(c--)
        {
            z = inp();
            if(z) // query
            {
                p = inp();
                q = inp();
                v1 = query1(q)*q - query2(q);
                v2 = query1(p-1)*(p-1) - query2(p-1);
                printf("%lld\n",v1 - v2 );
            }
            else    
            {
                p = inp();
                q = inp();
                scanf("%lld",&v);
                update1(p, v);
                update1(q+1, -v);
                update2(p, v*(p-1));
                update2(q+1, -v*q);
            }
        }
    }
    return 0;
}
