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
const int N = 10010;
int n, T, prime[N], cnt, f[N], s, e, vis[N];
bool notPrime[N];


int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    s(T);
    for (int i = 2; i < N; i++) {
    	if (!notPrime[i]) prime[cnt++] = i;
    	for (int j = 0; j < cnt && prime[j]*i < N; j++){
    		notPrime[prime[j]*i] = true;
    		if (i % prime[j] == 0) break;
    	} 
    }

    while (T--) {
    	MEM(f, INF);
    	MEM(vis, 0);
    	s(s),s(e);
    	f[s] = 0;
    	int ans = INF;
    	queue<PII> q;
    	q.push(mp(s, 0));
    	while(!q.empty()) {
			int u = q.front().fi;
			int d = q.front().se; q.pop();
			if (u == e) {
				ans = d;
				break;
			}
			vis[u] = true;
			int a[4] = {u%10, u/10%10, u/100%10, u/1000};
			F(i, 4) {
				int t = a[i];
				F(j, 10) {
					if (i == 3 && j == 0) continue;
					a[i] = j;
					int v = a[0]+a[1]*10+a[2]*100+a[3]*1000;
					if (!notPrime[v] && !vis[v]) {
						q.push(mp(v, d+1));
					}
				}
				a[i] = t;
			}
		}
    	if (ans == INF) printf("Impossible\n");
    	else printf("%d\n", ans);
    }
	return 0;
}



