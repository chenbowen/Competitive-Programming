/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-25
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
const int N = 9;
int n, maxd, a[N];

int h() {
	int cnt = 0;
	F(i, n-1) if (a[i+1] != a[i]+1)
		cnt++;
	if (a[n-1] != n) cnt++;
	return cnt;
}

bool dfs(int d) {
	if (h() + 3*d > 3*maxd) return false;
	if(d == maxd) {
		F(i, n) if(a[i] != i+1) return false;
		return true;
	}
	int t[N], b[N]; memcpy(t, a, sizeof(a));
	F(i, n) for(int j = i; j < n; j++) {
		int cnt = 0;
		F(k, n) if(k < i || k > j) 
			b[cnt++] = a[k];
		F(k, cnt) {
			int cnt2 = 0;
			F(p, k) a[cnt2++] = b[p];
			for(int p = i; p <= j; p++) a[cnt2++] = t[p];
			for(int p = k; p < cnt; p++) a[cnt2++] = b[p];
			if (dfs(d+1)) return true;
			memcpy(a, t, sizeof(a));
		}
	}
	return false;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif

    int kase = 0;
	while(s(n) == 1 && n) {
		F(i, n) s(a[i]);
		for(maxd = 0; maxd < N; maxd++) 
			if (dfs(0)) {
				printf("Case %d: %d\n", ++kase, maxd);
				break;
			}
	}
	return 0;
}
