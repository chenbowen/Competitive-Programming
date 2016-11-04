/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-11-03
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
#define SC(n)                       scanf("%c",&(n))
#define SF(n)                       scanf("%lf",&(n))
#define SS(n)                       scanf("%s",(n))
#define PI(n)                       printf("%d\n",(n))
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define sl(n)                       scanf(LLD,&(n))
const int N = 2502;
int n, l;
PII cow[N], bot[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	SII(n, l);
	F(i, n) SII(cow[i].fi, cow[i].se);
	F(i, l) SII(bot[i].fi, bot[i].se);
	sort(cow, cow+n); sort(bot, bot+l);
	priority_queue<int, vector<int>, greater<int> > q;
	int j = 0, t, cnt = 0;
	F(i, l) {
		while(j < n && cow[j].fi <= bot[i].fi) q.push(cow[j++].se);
		while(bot[i].se && !q.empty()) {
			t = q.top(); q.pop();
			if(t >= bot[i].fi) cnt++, --bot[i].se;
		}
	}
	PI(cnt);
	return 0;
}
