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
const int N = 5002;
int ans[N], t[N], maxd;

bool better() {
	FD(i, maxd+1) if (t[i] < ans[i] || ans[i] == -1) return true;
	return false; 
}

bool dfs(int d, int from, int a, int b) {
	if (d == maxd) {
		if (b % a) return false;
		t[d] = b;
		if (better()) memcpy(&ans, &t, sizeof(int) * maxd+1);
		return true;
	}
	bool ok = false;
	for(int c = from; ; c++) {
		if (a*c >= (maxd-d+1)*b) return false;
		int g = gcd(a*c-b, b*c);
		t[d] = c;
		if (dfs(d+1, c+1, (a*c - b)/g, (b*c)/g)) 
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
	while(s(a), s(b)) {
		for(maxd = 1; ; maxd++) {
			MEM(ans, -1);
			if (dfs(0, 2, a, b))
				break;
		}
		printf("%d/%d=", a, b);
		F(i, maxd+1) printf("1/%d+", ans[i]);
		printf("\n");
	}
	return 0;
}
