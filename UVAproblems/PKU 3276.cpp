// #define               LOCAL   
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
int n, f[N];
bool a[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	s(n);
	char c;
	F(i, n) {
		getchar();
		sc(c);
		if (c == 'B') a[i] = true;
	}
	int ans = INF, ansk = 1;
	for (int k = 1; k <= n; k++) {
		MEM(f, 0);
		if (a[0]) f[0] = 1;
		bool ok = true;
		for(int i = 1; i < n; i++) {
			int cnt = f[i] = f[i-1];
			if (i-k >= 0) cnt -= f[i-k];
			if (i <= n-k) {
				if ((a[i] && cnt % 2 == 0) || (!a[i] && cnt % 2))
					f[i]++;
			}
			else {
				if ((a[i] && cnt % 2 == 0) || (!a[i] && cnt % 2)) {
					ok = false;
					break;
				}	
			}
						
		}
		// whatis(k);
		// F(i, n) whatis(f[i]);
		if (ok && ans > f[n-1]) {
			ans = f[n-1];
			ansk = k;
		}
	}
	printf("%d %d\n", ansk, ans);
	return 0;
}
