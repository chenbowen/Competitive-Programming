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
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define sl(n)                       scanf(LLD,&(n))
const int N = 50002;
int n, s[N], cnt;

struct cow{
	int x, y, i;

	bool operator < (const cow &rhs) const {
		return y > rhs.y;
	}
};

bool cmp(const cow &x, const cow &y) {
	return x.x < y.x || (x.x == y.x && x.y < y.y);
}

cow a[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
    s(n);
	F(i, n) {
		s(a[i].x), s(a[i].y);
		a[i].i = i;
	}
	sort(a, a+n, cmp);
	priority_queue<cow> q;
	stack<int> stall;
	int cur;
	F(i, n) {
		cur = a[i].i;
		while(!q.empty()) {
			if(q.top().y >= a[i].x) break;
			s[cur] = s[q.top().i];
			stall.push(s[cur]);
			q.pop();
		}
		q.push(a[i]);
		if(s[cur]) stall.pop();
		else {
			if(stall.empty()) s[cur] = sz(q);
			else {s[cur] = stall.top(); stall.pop();}
		}
		cnt = max(cnt, sz(q));
	}
	printf("%d\n", cnt);
	F(i, n) printf("%d\n", s[i]);	
	return 0;
}
