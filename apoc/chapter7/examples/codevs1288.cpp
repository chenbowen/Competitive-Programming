/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-24
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
const int N = 1010;
LL ans[N], t[N], maxd;

LL get_first(LL a, LL b) {
	return b/a+1;
}

bool dfs(LL d, LL from, LL a, LL b) {
	if (d == maxd) {
		if (b % a) return false;
		t[d] = b;
		if (t[maxd] < ans[maxd] || ans[maxd] == -1) 
			memcpy(&ans, &t, sizeof(LL) * (d+1));
		return true;
	}
	bool ok = false;
	for(LL c = max(get_first(a, b), from); ; c++) {
		if (a*c >= (maxd-d+1)*b) break;
		LL g = gcd(a*c-b, b*c);
		t[d] = c;
		if (dfs(d+1, c+1, (a*c-b)/g, (b*c)/g)) 
			ok = true;
	}
	return ok;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	int a, b;
	while(s(a), s(b) == 1) {
		bool ok = false;
		for(maxd = 1; maxd < 100; maxd++) {
			MEM(ans, -1);
			if (dfs(0, get_first(a,b), a, b)) {
				ok = true;
				break;
			}
		}
		if (ok) {
			printf("%d", ans[0]);
			F(i, maxd) printf(" %d", ans[i+1]);
		}
		else printf("No solution");
		printf("\n");
	}
	return 0;
}
