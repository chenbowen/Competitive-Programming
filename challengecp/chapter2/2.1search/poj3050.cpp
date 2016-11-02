/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-31
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
const int N = 5;
int a[N][N], A[N];
set<int> num;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

void dfs(int d, int x, int y) {
	if(d == N+1) {
		int t = 0;
		F(i, N+1) t = t * 10 + A[i];
		num.insert(t);
	} else {
		A[d] = a[x][y];
		F(i, 4) {
			int nx = x+dx[i], ny = y+dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			dfs(d+1, nx, ny);
		}
	}

}
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	F(i, N) F(j, N) s(a[i][j]);
	F(i, N) F(j, N) dfs(0, i, j);
	// for(auto i:num) printf("%d ", i); printf("\n");
	printf("%d\n", num.size());
	return 0;
}
