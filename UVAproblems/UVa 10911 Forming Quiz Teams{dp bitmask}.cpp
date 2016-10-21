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
#define              LOCAL   
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define sl(n)                       scanf(LLD,&(n))
const int N = 9;
int n;
double dp[1<<(2*N)];
typedef pair<double, double> pt;
pt a[2*N];

double dis(pt x, pt y) {
	return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se));
}

double solve(int state) {
	if (dp[state] != -1) return dp[state];
	dp[state] = INF;
	F(i, n) if (state & (1<<i)){
		F(j, n) if (i != j && (state & (1<<j))){
			dp[state] = min(dp[state], solve((1<<i)+(1<<j))+solve((state^(1<<i))^(1<<j)));
		}
	}
	return dp[state];
}

int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int kase = 0;
	while (s(n) && n) {
		char t[50];
		n *= 2;
		F(i, 1<<n) dp[i] = -1;
		F(i, n) ss(t), sf(a[i].fi), sf(a[i].se);
		F(i, n) FOR(j, i+1, n-1){
			dp[(1<<i)+(1<<j)] = dis(a[i], a[j]);
		}
		printf("Case %d: %.2lf\n", ++kase, solve((1<<n)-1));
	}
	return 0;
}

