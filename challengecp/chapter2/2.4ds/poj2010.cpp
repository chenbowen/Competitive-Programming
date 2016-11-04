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
#define SIII(a,b,c)                 scanf("%d%d%d",&(a),&(b),&(c))
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
const int N = 100002;
int n, c, f, lower[N], upper[N];
PII a[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	SIII(n, c, f);
	int half = n / 2;
	F(i, c) SII(a[i].fi, a[i].se);
	sort(a, a + c);

	int total = 0;
	priority_queue<int> q;
	F(i, c){
		lower[i] = q.size() == half ? total : INF;
		q.push(a[i].se);
		total += a[i].se;
		if (q.size() > half) { total -= q.top(); q.pop();}
	}
	while(!q.empty()) q.pop();
 
	total = 0;
	FD(i, c){
		upper[i] = q.size() == half ? total : INF;
		q.push(a[i].se);
		total += a[i].se;
		if (q.size() > half) {total -= q.top(); q.pop();}
	}
 
	int result = -1;
	FD(i, c) if (lower[i] + a[i].se + upper[i] <= f){
		result = a[i].fi;
		break;
	}
	PI(result);
	return 0;
}
