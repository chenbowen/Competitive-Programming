/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-24
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
const int N = 20;
struct State {
	int a, b, c, d;
	State(): a(149), b(148), c(149), d(0){}
};
int r, c, n, idx, id[N][N];
bool vis[150][150][150];
char s[N][N];
vector<int> G[150];

bool inter(int ta, int tb, int ua, int ub) {
	return (ta == ub) && (tb == ua);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	while(s(c), s(r), s(n) && c && r && n) {
		getchar();
		F(i, 150) G[i].clear();
		idx = 0;
		G[149].pb(149); G[148].pb(148);
		State start, end;
		F(i, r) {
			fgets(s[i], N, stdin);
			F(j, c) if (s[i][j] != '#') 
				id[i][j] = idx++;
		}
		int dx[] = {0, 0, -1, 0, 1};
		int dy[] = {0, 1, 0, -1, 0};
		F(i, r) F(j, c) if (s[i][j] != '#') {
			if (s[i][j] == 'a') 
				start.a = id[i][j];
			else if (s[i][j] == 'b')
				start.b = id[i][j];
			else if (s[i][j] == 'c')
				start.c = id[i][j];
			else if (s[i][j] == 'A') 
				end.a = id[i][j];
			else if (s[i][j] == 'B')
				end.b = id[i][j];
			else if (s[i][j] == 'C')
				end.c = id[i][j];
			F(k, 5) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx >= 0 && ny >= 0 && nx < r && ny < c && s[nx][ny] != '#') 
					G[id[i][j]].pb(id[nx][ny]);
			}
		}
		start.d = 0;
		MEM(vis, 0);
		queue<State> q;
		q.push(start);
		vis[start.a][start.b][start.c] = true;
		int ans = INF;
		while(!q.empty()) {
			State u = q.front(); q.pop();
			if (u.a == end.a && u.b == end.b && u.c == end.c) {
				ans = u.d;
				break;
			}
			State t;
			F(i, sz(G[u.a])) {
				t.a = G[u.a][i];
				F(j, sz(G[u.b])) {
					t.b = G[u.b][j];
					if (t.a == t.b || inter(t.a, t.b, u.a, u.b))
						continue;
					F(k, sz(G[u.c])) {
						t.c = G[u.c][k];
						if (t.a == t.c || t.b == t.c || vis[t.a][t.b][t.c])
							continue;
						if (inter(t.a, t.c, u.a, u.c) || inter(t.b, t.c, u.b, u.c))
							continue;
						vis[t.a][t.b][t.c] = true;
						State tt; memcpy(&tt, &t, sizeof(t));
						tt.d = u.d + 1;
						q.push(tt);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
