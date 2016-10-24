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
const int N = 30;
int n, ans, a[N], f[N], ansp[N], node[N];
bool G[N][N], vis[N], vis2[N];
char s[200];

void dfs(int d, int k) {
	if (d == n) {
		if (ans > k) {
			ans = k;
			memcpy(ansp, a, sizeof(a));
		}
		return;
	}
	F(i, n) if (!vis[node[i]]) {
		vis[node[i]] = true;
		a[d] = node[i];
		f[a[d]] = d;
		MEM(vis2, 0);
		F(j, d) if (G[a[d]][a[j]]) {
			k = max(k, abs(f[a[j]] - f[a[d]]));
			vis2[a[j]] = true;
		}
		int cnt = 0;
		F(j, n) if (G[a[d]][node[j]] && !vis2[node[j]]) 
			cnt++;
		if (k < ans && cnt < ans) dfs(d+1, k);
		f[a[d]] = INF;
		vis[node[i]] = false;
	}
}

void insert(int u) {
	if (!vis[u]) {
		node[n++] = u;
		vis[u] = true;
	}
}

void parse() {
	n = 0;
	int l = strlen(s), i = 0;
	MEM(G, 0);
	MEM(vis, 0);
	do {
		int u = s[i] - 'A'; i += 2;
		insert(u);
		while (i < l && s[i] != ';') {
			insert(s[i]-'A');
			G[s[i++] - 'A'][u] = G[u][s[i-1] - 'A'] = true;
		}
	} while(i++ < l);
	sort(node, node+n);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	while (ss(s) && s[0] != '#') {
		parse();
		ans = INF;
		MEM(vis, 0);
		MEM(f, INF);
		dfs(0, 0);
		F(i, n) printf("%c ", ansp[i] + 'A');
		printf("-> %d\n", ans);
	}
	return 0;
}
