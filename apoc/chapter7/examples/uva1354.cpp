/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-22
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
const double eps = 1e-9;
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
#define bug                         printf("\nhere!!!\n")
#define fi                          first
#define se                          second
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define s(n)                        scanf("%d",&(n))
#define sc(n)                       scanf("%c",&(n))
#define sf(n)                       scanf("%lf",&(n))
#define ss(n)                       scanf("%s",(n))
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define sl(n)                       scanf(LLD,&(n))
const int N = 6+1;
int n;
bool vis[1<<N];
double a[N], maxr, sum[1<<N];
vector<pair<double, double> > mem[1<<N];
void dfs(int subset) {
	if (vis[subset]) return;
	vis[subset] = true;
	bool have_children = false;
	for(int left=(subset-1)&subset; left; left=(left-1)&subset) {
		have_children = true;
		int right = subset^left;
		dfs(left); dfs(right);
		double l = sum[right] / sum[subset];
		double r = sum[left] / sum[subset];
		F(i, sz(mem[left])) 
			F(j, sz(mem[right])) {
				double ll = max(mem[left][i].fi+l, mem[right][j].fi-r);
				double rr = max(mem[right][j].se+r, mem[left][i].se-l);
				if (ll+rr < maxr)
					mem[subset].pb(mp(ll, rr));
			}
	}
	if (!have_children) mem[subset].pb(mp(0, 0));
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
    int T;
    s(T);
    while(T--) {
		sf(maxr),s(n);
		F(i, n) sf(a[i]);
		F(i, 1<<n) {
			sum[i] = 0;
			F(j, n) if (i&(1<<j)) 
				sum[i] += a[j];
			mem[i].clear();
		}
		MEM(vis, 0);
		int allset = (1<<n)-1;
		dfs(allset);
		double ans = -1;
		F(i, sz(mem[allset])) 
			ans = max(ans, mem[allset][i].fi+mem[allset][i].se);
		printf("%.10f\n", ans);
    }
	return 0;
}