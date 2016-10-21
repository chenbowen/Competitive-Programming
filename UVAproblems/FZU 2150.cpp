#define              LOCAL   
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
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define F(i,n)                      for(int i=0;i<(n);++i)
#define FD(i,n)                     for(int i=(n-1);i>=0;--i)
#define MEM(x,i)                    memset(x,i,sizeof(x))
#define mp                          make_pair
#define db(a)                       cout<<(a)<<endl
#define whatis(a)                   cout<<#a<<" is "<<a<<endl
#define bug                         printf("here!!!\n")
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
const int N = 11;
struct Node{
	int x, y, d;
};

int T, m, n, dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
char s[N][N];
bool f[N][N];
int tot, x[N*N], y[N*N];

int bfs(int x, int y, int a, int b) {
	int time = -1, cnt = 0;
	queue<Node> q;
	MEM(f, 0);
	q.push((Node){x,y,0});
	if (a != x || b != y) q.push((Node){a,b,0});
	f[x][y] = f[a][b] = true;
	while (!q.empty()) {
		Node u = q.front(); q.pop();
		cnt++;
		F(i, 4) {
			int nx = u.x + dx[i], ny = u.y + dy[i];
			if (nx>=0&&nx<m&&ny>=0&&ny<n&&!f[nx][ny]&&s[nx][ny]=='#') {
				f[nx][ny] = true;
				q.push((Node){nx,ny,u.d+1});
			}
		}
		time = max(time, u.d);
	}
	// whatis(x);whatis(y);whatis(a);whatis(b);whatis(time);whatis(cnt);
	if (cnt == tot) return time;
	return INF;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    s(T);
    int kase = 0;
    while (T--) {
    	s(m), s(n);
    	tot = 0;
    	F(i, m) {
    		ss(s[i]);
    		F(j, n) if (s[i][j] == '#') {
    			x[tot] = i;
    			y[tot++] = j;
    		}
    	}
    	int ans = INF;
    	F(i, tot) 
    		for(int j = i; j < tot; j++) 
				ans = min(ans, bfs(x[i], y[i], x[j], y[j]));
    	printf("Case %d: ", ++kase);
    	if (ans == INF) printf("-1\n");
    	else printf("%d\n", ans);
    }
    return 0;
}
