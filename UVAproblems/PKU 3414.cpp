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
const int N = 105;
int C, A, B;
bool vis[N][N];
struct Node{
	int a, b;
	Node(int a = 1, int b = 1): a(a), b(b) {}
};
Node path[N][N], st;
char cmd[N][N][20];

void print_path(Node e, int d) {
	printf("%d\n", d);
	vector<char*> p;
	while (e.a || e.b) {
		p.pb(cmd[e.a][e.b]);
		e = path[e.a][e.b];
	}
	FD(i, sz(p)) printf("%s\n", p[i]);
}

int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
    s(A),s(B),s(C);
    st = Node(0, 0);
    queue<pair<Node, int> > q;
    q.push(mp(st, 0));
    bool ok = false;
    while (!q.empty()) {
    	Node u = q.front().fi;
    	int d = q.front().se; q.pop();
    	if (u.a == C || u.b == C) {
    		print_path(u, d);
    		ok = true;
    		break;
    	}
    	vis[u.a][u.b] = true;
    	if (!vis[A][u.b]) {
    		q.push(mp(Node(A, u.b), d+1));
    		path[A][u.b] = Node(u.a, u.b);
    		sprintf(cmd[A][u.b], "FILL(1)");
    	}
    	if (!vis[u.a][B]) {
    		q.push(mp(Node(u.a, B), d+1));
    		path[u.a][B] = Node(u.a, u.b);
    		sprintf(cmd[u.a][B], "FILL(2)");
    	}
    	if (!vis[0][u.b]) {
    		q.push(mp(Node(0, u.b), d+1));
    		path[0][u.b] = Node(u.a, u.b);
    		sprintf(cmd[0][u.b], "DROP(1)");
    	}
    	if (!vis[u.a][0]) {
    		q.push(mp(Node(u.a, 0), d+1));
    		path[u.a][0] = Node(u.a, u.b);
    		sprintf(cmd[u.a][0], "DROP(2)");
    	}
    	int pour = min(u.a, B-u.b);
    	if (!vis[u.a-pour][u.b+pour]) {
    		q.push(mp(Node(u.a-pour, u.b+pour), d+1));
    		path[u.a-pour][u.b+pour] = Node(u.a, u.b);
    		sprintf(cmd[u.a-pour][u.b+pour], "POUR(1,2)");
    	}
    	pour = min(u.b, A-u.a);
    	if (!vis[u.a+pour][u.b-pour]) {
    		q.push(mp(Node(u.a+pour, u.b-pour), d+1));
    		path[u.a+pour][u.b-pour] = Node(u.a, u.b);
    		sprintf(cmd[u.a+pour][u.b-pour], "POUR(2,1)");
    	}
    }
    if (!ok) printf("impossible");
	return 0;
}
