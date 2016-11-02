/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-11-01
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
#define LLD                         "%lld"
#define sl(n)                       scanf(LLD,&(n))
const int N = 100002;
int n;
struct cow{
	int t, d;
	cow(int t, int d): t(t), d(d){}
	bool operator < (const cow &rhs) const {
		return t*rhs.d > rhs.t*d;
	}
};

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	s(n);
	int x, y;
	LL ans = 0, sum = 0;
	priority_queue<cow> q;
	F(i, n) {
		s(x), s(y);
		sum += y;
		q.push(cow(x, y));
	}
	while(!q.empty()) {
		cow t = q.top(); q.pop();
		ans += (sum -= t.d)*(t.t<<1);
	}
	printf(LLD"\n", ans);
	return 0;
}
