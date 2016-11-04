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
const double eps = 1e-7;
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
const int N = 1002;
int n;
double d;
bool ok;
PII a[N];

pair<double, double> calc(PII &x) {
	if(x.se > d) { ok = false; return mp(1, -1); }
	return mp(x.fi*1.0-sqrt(d*d-x.se*x.se), x.fi*1.0+sqrt(d*d-x.se*x.se));
}

bool leq(double x, double y) {
	if(abs(x - y) < eps) return true;
	return x < y;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
    int kase = 0;
	while(s(n), sf(d) == 1 && n) {
		ok = true;
		F(i, n) s(a[i].fi), s(a[i].se);
		sort(a, a+n);
		int i = 0, cnt = 0;
		while(i < n && ok) {
			pair<double, double> ri = calc(a[i]);
			if(!ok) break;
			cnt++;
			int j = i+1;
			while(j < n) {
				pair<double, double> rj = calc(a[j]);
				if(!ok) break;
				if(leq(max(ri.fi, rj.fi), min(ri.se, rj.se))) {
					ri.fi = max(ri.fi, rj.fi);
					ri.se = min(ri.se, rj.se);
					j++;
				}
				else break;
			}
			i = j;
		}
		printf("Case %d: ", ++kase);
		if(ok) printf("%d\n", cnt);
		else printf("-1\n");
	}
	return 0;
}
