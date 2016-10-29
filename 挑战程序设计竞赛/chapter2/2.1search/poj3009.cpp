/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-29
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
const int N = 21;
const int maxd = 10;
int r, c, s[N][N];
bool vis[N][N];
struct Node{
	PII p, path[maxd];
	int d;
};
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

inline bool inside(PII &p) {
	return p.fi >= 0 && p.se >= 0 && p.fi < r && p.se < c;
}
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	while(s(c), s(r) == 1 && r) {
		Node start;
		PII goal;
		F(i, r) F(j, c) {
			s(s[i][j]);
			if (s[i][j] == 2) start.p = mp(i, j);
			else if (s[i][j] == 3) goal = mp(i, j);
		}
		queue<Node> q;
		MEM(vis, 0)
		q.push(start);
		vis[start.p.fi][start.p.se] = true;
		bool ok = false;
		while(!q.empty()) {
			Node u = q.front(); q.pop();
			if (u.p == goal) { ok = true; 
			else if (u.d > 9) break;
			PII t;
			F(i, 4) {
				t = u.p;
				for(int nx=t.fi+dx[i],ny=t.se+dy[i]; valid(nx, ny); nx+=dx[i],ny+=dy[i]) {
					if(s[nx][ny] == '2') {ok = true; printf("%d\n", u.d); break;}
					else if(s[nx][ny] == '1') {
						bool find = false;
						F(j, u.d) if (u.path[j].fi == nx && u.path[j].se == ny) {find = true; break;}
						if(!find) {
							Node tt; memcpy(&tt, &u, sizeof(u));
							tt.path[++tt.d] = mp(nx, ny);
							tt.p = mp(nx-dx[i],ny-dy[i]);
							q.push(tt); 
							break;
						}
					}
				}
				if (ok) break;
				if(!valid(t.fi, t.se)) continue;
			}
			if(ok) break;
		}
		if (!ok) printf("-1\n");
	}
	return 0;
}
