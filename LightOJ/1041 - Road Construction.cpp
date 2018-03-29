/*===============================================
    Username    : Caffeines
    Name        : Abu Sadat Md. Sayem
    about me    : caffeines.github.io
    University  : North South University (NSU)
=================================================*/

#include <bits/stdc++.h>
#define all(x)                                 (x).begin(),(x).end()
#define ABS(x)                                      ((x)<0?-(x):(x))
#define FABS(x)                                 ((x)+eps<0?-(x):(x))
#define F                                                      first
#define FOR(i,x,y)                 for(ull i = (x) ; i <= (y) ; ++i)
#define kase(a,t)                    for(int a = 1 ; a <= (t) ; ++a)
#define LB(a,key)     lower_bound(a.begin(),a.end(), key) -a.begin()
#define LEFTMOST                          ((63-__builtin_clzll((x)))
#define MOD(x,y)                                     (((x)*(y))%mod)
#define MIN(a,b)                                   ((a)<(b)?(a):(b))
#define MAX(a,b)                                   ((a)>(b)?(a):(b))
#define MP                                                 make_pair
#define mem(x,y)                               memset(x,y,sizeof(x))
#define NORM(x)                                     if(x>=mod)x-=mod
#define NUMDIGIT(x,y)              (((ll)(log10((x))/log10((y))))+1)
#define ODD(x)                                  (((x)&1)==0?(0):(1))
#define pb                                                 push_back
#define pl                                              printf("\n")
#define pf                                                    printf
#define pcase(t)                               printf("Case %d: ",t)
#define phl printf                                     ( "hello\n" )
#define POPCOUNT                                __builtin_popcountll
#define ROF(i,x,y)                 for(ull i = (y) ; i >= (x) ; --i)
#define RIGHTMOST                                    __builtin_ctzll
#define REP(i,y)                      for(ull i = 0 ; i < (y) ; ++i)
#define S                                                     second
#define Size                                                      55
#define SQ(x)                                              ((x)*(x))
#define sf(n)                                         scanf("%d",&n)
#define slf(n)                                      scanf("%lld",&n)
#define SZ(x)                                    ((vlong)(x).size())
#define sff(n,m)                                scanf("%d %d",&n,&m)
#define slff(n,m)                           scanf("%lld %lld",&n,&m)
#define UB(a,key)     upper_bound(a.begin(),a.end(), key) -a.begin()
#define Unique(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define valid(i,j)         (i >= 0 && j>= 0 && i < 1001 && j < 1001)
#define check(i, j)         ((i >= 0 && i < R) && (j >= 0 && j < C))

using namespace std;
typedef long long               ll;
const double            eps = 1e-9;
typedef unsigned long long     ull;
typedef         pair < ll, ll> pll;
typedef        pair < int,int> pii;
typedef             vector<pll> pv;
typedef              vector<ll> vl;
typedef            vector <int> vi;
const int         inf = (int) 10e9;
const ll          INF = (ll) 10e18;
const double PI = 2 * acos ( 0.0 );

int dx[] = {+1,-1,0,0};
int dy[] = {0,0,+1,-1};
int hx[] = {+1,-1,-1,+1,-2,-2,+2,+2};
int hy[] = {+2,+2,-2,-2,+1,-1,+1,-1};
int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

template < typename T> inline T LCM(T x, T y) {T g = GCD(x,y); return x*(y/g); }
template < typename T> inline T GCD(T a, T b) {a=ABS(a), b=ABS(b); return !b ? a : GCD(b,a%b); }
template < typename T> inline T power(T b,T p) { T res = 1, x = b; while ( p ) { if ( p & 1 ) res = ( res * x ); x = ( x * x ); p >>= 1;}return res;}
template < typename T> inline T bigmod (T b, T p, T m) { T res = 1 % m, x = b % m; while ( p ) { if ( p & 1 ) res = ( res * x ) % m; x = ( x * x ) % m; p >>= 1; }return res; }

/*=================================================================================================================================================
                                                stop doubting yourself, work hard and make it happen.
===================================================================================================================================================*/

struct Node
{
    int x,y,cost;
    Node(){};
    Node(int x,int y,int cost)
    {
        this->x = x;
        this->y = y;
        this->cost = cost;
    }
    bool operator <(const Node& node) const
    {
        return node.cost > cost;
    }
}input;

int par[Size],temp;
int setFind(int pos)
{
    if(pos == par[pos])
        return pos;
    par[pos] = setFind(par[pos]);
    return par[pos];
}

void make_set(int n)
{
    for(int i=0;i<=n;i++)
        par[i] = i;
}

vector <Node> graph;
int MST(int n)
{
    sort(graph.begin(),graph.end());
    make_set(n);

    int counter=0, sum=0;
    for(int i=0;i<graph.size();i++)
    {
        int u = setFind(graph[i].x);
        int v = setFind(graph[i].y);

        if(u != v)
        {
            par[u] = v;
            counter++;
            sum += graph[i].cost;
            if(counter == n)
                break;
        }
    }
    if(n-1 != counter)
        printf("Impossible\n");
    else
        printf("%d\n",sum);
    return sum;
}

map< string,int > MAP;
int mapFind(string x)
{
    if(MAP.find(x) == MAP.end())
        MAP[x] = ++temp;
    return MAP[x];
}

void Clear()
{
    graph.clear();
    MAP.clear();
    temp = 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T,cost;
    string u,v;
    sf(T);
    kase(t,T)
    {
        Clear();
        int m;sf(m);
        FOR(i,1,m)
        {
            cin>>u>>v>>cost;
            input = Node(mapFind(u),mapFind(v),cost);
            graph.pb(input);
        }
        pcase(t);
        MST(temp);
    }
    return 0;
}
