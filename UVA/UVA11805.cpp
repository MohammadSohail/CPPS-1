#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sq(a) (a)*(a)
#define pl printf("\n");
#define pf(n) printf("%d",n)
#define sf(n) scanf("%d",&n)
#define sff(a,b) scanf("%d %d",&a,&b);
#define sfff(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define INF (numeric_limits<int>::max())
#define kase(i,b) for(int i=1;i<=b;i++)
#define asize(arr) (sizeof(arr)/sizeof(arr[0]))
#define mem(arr) memset(arr,0,sizeof(arr));
#define KASE(a) printf("Case %d: ",a);
#define gcd(x,y) __gcd(abs(x),abs(y))
#define lcm(x,y) ((abs(x)/gcd(x,y))*abs(y))
#define N 10000020
int main()
{
    //freopen("input.txt","r",stdin);
    int T;
    sf(T);
    kase(t,T)
    {
        int n,k,p;
        sfff(n,k,p);
        int res = (k+p)%n;
        KASE(t);
        if(res==0) pf(n);
        else pf(res); pl;
    }
    return 0;
}
