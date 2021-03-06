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
#define bug                         puts("here!!!")
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
const int N = 1e5+10;
int sum[N], f[N], ans = -INF;

int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, t, a[N];
    s(n), s(t);
    F(i, n) s(a[i]);
    F(i, n) {
    	int j = 0;
    	if (i) {
    		sum[i] = max(0, sum[i-1] - a[i-1]);
	    	j = max(j, f[i-1]-1);
	 	}
	    while (i+j < n && sum[i] + a[i+j] <= t) {
	    	sum[i] += a[i+j];
	    	j++;
    	}
    	f[i] = j;
    	ans = max(ans, f[i]);
    }
    printf("%d", ans);
	return 0;
}

