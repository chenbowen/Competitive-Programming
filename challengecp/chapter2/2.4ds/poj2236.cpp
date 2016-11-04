/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-11-04
 */
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
typedef vector<int> VI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
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
#define bug                         printf("\nhere!!!\n")
#define fi                          first
#define se                          second
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define SI(n)                       scanf("%d",&(n))
#define SII(a,b)                    scanf("%d%d",&(a),&(b))
#define SIII(a,b,c)                 scanf("%d%d%d",&(a),&(b),&(c))
#define SC(n)                       scanf("%c",&(n))
#define SF(n)                       scanf("%lf",&(n))
#define SFF(a,b)                    scanf("%lf%lf",&(a),&(b))
#define SS(n)                       scanf("%s",(n))
#define PI(n)                       printf("%d\n",(n))
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define sl(n)                       scanf(LLD,&(n))
const int N = 1002;
int n, par[N], dep[N], f[N];
double d;
pair<double, double> data[N];

vector<int> G[N];

bool valid(pair<double, double> &x, pair<double, double> &y) {
	double dist = sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se));
	if(abs(dist - d) < eps) return true;
	return dist < d;
}

void dsu_init() { 
	F(i, n) par[i+1] = i+1;
}

int dsu_find(int x) {
	if(par[x] == x) return x;
	return par[x] = dsu_find(par[x]);
}

void dsu_union(int x, int y) {
	int fx = dsu_find(x), fy = dsu_find(y);
	if(fx == fy) return; 

	if(dep[fx] <= dep[fy]) {
		par[fx] = fy;
		if(dep[fx] == dep[fy]) dep[fy]++;
	} else par[fy] = fx;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	SI(n), SF(d);
	F(i, n) SFF(data[i+1].fi, data[i+1].se);

	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			if(valid(data[i], data[j])) {
				G[i].pb(j);
				G[j].pb(i);
			}

	dsu_init();
	char cmd;  int x, y;
	getchar();
	while(SC(cmd) == 1) {
		if(cmd == 'O') {
			SI(x);
			if(f[x]) continue;
			vector<int> &v = G[x];
			f[x] = true;
			F(i, sz(v)) if(f[v[i]]) dsu_union(x, v[i]);
		} else {
			SII(x, y);
			if(dsu_find(x) == dsu_find(y)) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
		getchar();
	}
	return 0;
}
