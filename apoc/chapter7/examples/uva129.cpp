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
const int N = 100;
int n, l, a[N];

void dfs(int &k, int d) {
	if (k == n) {
		F(i, d) {
			if (i == 64) printf("\n");
			else if (i && (i % 4) == 0) printf(" ");
			printf("%c", a[i]+'A');
		}
		printf("\n%d\n", d);
		return;
	}
	F(i, l) {
		bool ok = true;
		for(int j = d-1; j >= d/2; j--) {
			if (a[j] == i) {
				ok = false;
				F(z, d-j-1) {
					if (a[d-1-z] != a[j-1-z]) {
						ok = true;
						break;
					}
				}
				if (!ok) break;
			}
		}
		if (!ok) continue;
		a[d] = i;
		if (++k <= n) dfs(k, d+1);
	}
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	while (s(n),s(l) && n) {
		int k = 0;
		dfs(k, 0);
	}
	return 0;
}
