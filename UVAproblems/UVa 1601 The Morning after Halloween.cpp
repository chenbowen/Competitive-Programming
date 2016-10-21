#define               LOCAL   
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
#include <unordered_set>
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
const int N = 17;
int w, h, n, cnt, id[N][N];
char s[N+10][N+10];

struct Node {
	int a[3], d;
	Node(int x = 1, int y = 1, int z = 1, int dis = 0) {
		a[0] = x;
		a[1] = y;
		a[2] = z;
		d = dis;
	}
	Node(const Node &t, bool plus) {
		F(i, n) a[i] = t.a[i];
		d = t.d+plus;
	}
	int value() {
		int v = 0;
		F(i, n) v = v*179+a[i];
		return v;
	}
	bool conflict(int n, Node &u) {
		F(i, n) FOR(j, i+1, n-1) {
			if (a[i] == a[j] || (a[i] == u.a[j] && a[j] == u.a[i]))
				return true;
		}
		return false;
	}
	bool operator == (const Node &rhs) const {
		F(i, n) if (a[i] != rhs.a[i]) return false;
		return true;
	}
};
VI G[N*N];
bool f[180*180*180];
queue<Node> q;

void dfs(Node &u, Node &t, int i) {
	if (i == n) {
		if (!f[t.value()]) {
			f[t.value()] = true;
			q.push(Node(t, true));
		}
		return;
	}
	VI &vs = G[u.a[i]];
	for(auto v : vs) {
		t.a[i] = v;
		if (t.conflict(i+1, u)) continue;
		dfs(u, t, i+1);
	}
	t.a[i] = u.a[i];
}

int bfs(Node &a, Node &A) {
	while (!q.empty()) q.pop();
	MEM(f, 0);
	q.push(a);
	f[a.value()] = true;
	while (!q.empty()) {
		Node u = q.front(); q.pop();
		// whatis(u.d);
		Node t = Node(u, false);
		if (u == A) return u.d;
		dfs(u, t, 0);
	}
}

int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    while (s(w), s(h), s(n) && n) {
    	getchar();
    	F(i, N*N) G[i].clear();
    	F(i, h) gets(s[i]);
    	int dy[] = {0, 1, 0, -1, 0}, dx[] = {0, 0, -1, 0, 1};
    	Node a, A;
    	cnt = 0;
    	//build graph
    	F(i, h) F(j, w) {
    		if (s[i][j] != '#'){
    			id[i][j] = cnt;
    			if (s[i][j] >= 'a' && s[i][j] <= 'c') a.a[s[i][j]-'a'] = cnt;
    			else if (s[i][j] >= 'A' && s[i][j] <= 'C') A.a[s[i][j]-'A'] = cnt;
    			cnt++;
    		}
    	}
    	F(i, h) F(j, w) if (s[i][j] != '#'){
			F(k, 5) {
				int x = i + dx[k], y = j + dy[k];
				if (x >= 0 && x < h && y >= 0 && y < w && s[x][y] != '#')
					G[id[i][j]].pb(id[x][y]);
			}
    	}
    	printf("%d\n", bfs(a, A));
    }
	return 0;
}



