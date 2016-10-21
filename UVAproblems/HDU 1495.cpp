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
const int N = 101;
int a[3];
bool vis[N][N][N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	while (s(a[0]),s(a[1]),s(a[2]) && a[0]) {
		int e = a[0]/2, ans = -1;
		if (a[0]%2) {printf("NO\n"); continue;}
		MEM(vis, 0);
		queue<VI> q;
		q.push((VI){a[0], 0, 0, 0});
		while (!q.empty()) {
			VI u = q.front(); q.pop();
			int cnt = 0;
			F(i,3) if (u[i] == e) cnt++;
				// whatis(u[0]),whatis(u[1]), whatis(u[2]);
			if (cnt >= 2) {
				ans = u[3];
				break;
			}
			vis[u[0]][u[1]][u[2]] = true;
			F(i, 3) if (u[i]) {
				F(j, 3) if (i != j) {
					int pour = min(u[i], a[j]-u[j]);
					u[i] -= pour;
					u[j] += pour;
					if (!vis[u[0]][u[1]][u[2]]) 
						q.push((VI){u[0], u[1], u[2], u[3]+1});
					u[i] += pour;
					u[j] -= pour;
				} 
			}
		}
		if (ans == -1) printf("NO\n");
		else printf("%d\n", ans);
	}  
	return 0;
}
