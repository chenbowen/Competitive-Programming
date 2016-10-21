// #define              LOCAL   
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
const int N = 1001;
int r, c, ans, dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
char s[N][N];

struct Node{
	int x, y, d;
};

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int T;
    s(T);
    while (T--) {
    	s(r), s(c);
    	queue<Node> q;
    	Node J;
    	F(i, r) {
    		ss(s[i]);
    		F(j, c) {
    			if (s[i][j] == 'J') {
    				J = (Node){i, j, 0};
    			}
    			else if (s[i][j] == 'F'){
    				q.push((Node){i, j, 0});
    			}
    		}
    	}
    	q.push(J);
    	ans = -1;
    	while(!q.empty()) {
    		Node u = q.front(); q.pop();
    		if (s[u.x][u.y]=='J'&&(u.x==0||u.x==r-1||u.y==0||u.y==c-1)) {
    			ans = u.d+1;
    			break;
    		}
    		F(i, 4) {
    			int nx = u.x+dx[i], ny = u.y+dy[i];
    			if (nx>=0&&ny>=0&&nx<r&&ny<c&&s[nx][ny]=='.') {
    				s[nx][ny] = s[u.x][u.y];
    				q.push((Node){nx,ny,u.d+1});
    			}
    		}
    	}
    	// F(i, r) printf("%s\n", s[i]);
    	if (ans == -1) printf("IMPOSSIBLE\n");
    	else printf("%d\n", ans);

    }
    return 0;
}
