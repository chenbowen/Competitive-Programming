// #define     LOCAL   
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <functional>
using namespace std;
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define F(i,n)                      for(int i=0;i<(n);++i)
#define FOR(i,x,y)                  for(int i=(x);i<=(y);++i)
#define FD(i,n)                     for(int i=(n-1);i>=0;--i)
#define FORD(i,y,x)                 for(int i=(y);i>=(x);--i)
#define MEM(x,i)                    memset(x,i,sizeof(x))
#define mp                          make_pair
#define db(a)                       cout<<(a)<<endl
#define whatis(a)                   cout<<#a<<" is "<<a<<endl
#define bug                         puts("here!!!")
#define fi                          first
#define se                          second
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define s(n)                        scanf("%d",&(n))
#define sc(n)                       scanf("%c",&(n))
#define sl(n)                       scanf(LLD,&(n))
#define sf(n)                       scanf("%lf",&(n))
#define ss(n)                       scanf("%s",(n))
typedef vector<int> VI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const int N = 5002;
int n, m, T, f[N][N];
map<PII, int> pre;
vector<PII> G[N];

int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    scanf("%d %d %d", &n, &m, &T);
    int _u, _v, _t;
    F(i, m) {
    	scanf("%d %d %d", &_u, &_v, &_t);
    	G[_v].pb(mp(_u, _t));
    }
    int maxStep = 1, v, cost;
    FOR(i, 0, n) FOR(j, 0, n) f[i][j] = INF;
    f[1][1] = 0;
    FOR(i, 2, n) {
    	FOR(u, 2, n) {
    		f[i][u] = INF;
    		vector<PII> &from = G[u];
    		for (int j = 0; j < int(from.size()); j++) {
    			v = from[j].fi;
    			cost = f[i-1][v] + from[j].se;
    			if (cost <= T) {
    				// whatis(i),whatis(u), whatis(v);
    				if (f[i][u] > cost) {
    					f[i][u] = cost;
    					pre[mp(i, u)] = v;
    				}
    			}
    		}
    	}
    	if (f[i][n] != INF) maxStep = max(maxStep, i);
    }
    printf("%d\n", maxStep);
    int p = pre[mp(maxStep, n)];
    // db(p);
    VI ans;
    ans.pb(n);
    while (p != 1) {
    	ans.pb(p);
    	p = pre[mp(--maxStep, p)];
    }
    printf("1");
    FORD(i, int(ans.size())-1, 0) printf(" %d", ans[i]);
    return 0;
}
