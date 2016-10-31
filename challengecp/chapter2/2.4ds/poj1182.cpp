/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-30
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
const int N = 50005;
int n, k, father[3*N], depth[3*N];

void dsu_init() {
	F(i, 3*(n+1)) {
		father[i] = i;
		depth[i] = 1;
	}
}

int dsu_find(int x) {
	if(father[x] == x) return x;
	return father[x] = dsu_find(father[x]);
}

int dsu_union(int x, int y) {
	int f1 = dsu_find(x), f2 = dsu_find(y);
	if(depth[f1] <= depth[f2]) {
		if(depth[f1] == depth[f2]) depth[f2]++;
		return father[f1] = f2;
	}
	return father[f2] = f1;
}

bool sameset(int x, int y) {
	return dsu_find(x) == dsu_find(y);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	s(n),s(k);
	dsu_init();
	int d, t1, t2, cnt = 0;
	F(i, k) {
		scanf("%d%d%d", &d, &t1, &t2);
		if(t1 > n || t2 > n || t1 < 1 || t2 < 1) {cnt++; continue;}
		if(d == 1) {
			if(sameset(t2+2*n, t1) || sameset(t2+n, t1)) {cnt++; continue;}
			dsu_union(t1, t2);
			dsu_union(t1+n, t2+n);
			dsu_union(t1+2*n, t2+2*n);
		} else {
			if(sameset(t1, t2) || sameset(t2+2*n, t1)) {cnt++; continue;}
			dsu_union(t1+2*n, t2);
			dsu_union(t2+n, t1);
			dsu_union(t1+n, t2+2*n);
		}
	}
	printf("%d", cnt);
	return 0;
}
