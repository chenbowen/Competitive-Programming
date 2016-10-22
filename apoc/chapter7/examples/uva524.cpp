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
const int N = 33;
int n;
bool isp[N], f[N];

void bt(int d, int *A) {
	if (d == n) {
		if (isp[A[d-1] + A[0]]) {
			F(i, n-1) printf("%d ", A[i]);
			printf("%d\n", A[n-1]);
		}
		return;
	}
	for(int i = 2; i <= n; i++) 
		if (!f[i] && isp[i+A[d-1]]) {
			f[i] = true;
			A[d] = i;
			bt(d+1, A);
			f[i] = false;
		}
}

void init() {
	MEM(isp, 1);
	for (int i = 2; i < N; i++) {
		if (isp[i]) 
			for(int j = i+i; j < N; j += i) 
				isp[j] = false;
	}
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	init();
	int kase = 0;
	while (s(n) == 1) {
		if (++kase > 1) printf("\n");
		printf("Case %d:\n", kase);
		int a[N];
		MEM(f, 0);
		f[1] = true;
		a[0] = 1;
		bt(1, a);
	}
	return 0;
}
