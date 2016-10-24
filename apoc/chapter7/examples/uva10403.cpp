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
const int N = 201;
int a[3], d;
bool vis[N][N];

struct Node{
	int a[3], m;
	Node() {
		F(i, 3) a[i] = 0;
		m = 0;
	}
	bool operator < (const Node& rhs) const {
		return m > rhs.m;
	}
};

priority_queue<Node> q;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	int T;
	s(T);
	while(T--) {
		Node start;
		s(a[0]),s(a[1]),s(a[2]),s(d);
		start.a[2] = a[2];
		MEM(vis, 0);
		while(!q.empty()) q.pop();
		q.push(start);
		vis[start.a[0]][start.a[1]] = true;
		int ansp = INF, dis = INF;
		while(!q.empty()) {
			Node u = q.top(); q.pop();
			// whatis(u.m), whatis(u.a[0]), whatis(u.a[1]), whatis(u.a[2]);
			F(i, 3) if(d >= u.a[i] && d - u.a[i] < dis) {
				dis = d - u.a[i];
				ansp = u.m;
			} 
			if (!dis) break;
			F(i, 3) F(j, 3) if(i != j) {
				int p = min(u.a[i], a[j] - u.a[j]);
				Node t; 
				t.a[i] = u.a[i] - p;
				t.a[j] = u.a[j] + p;
				t.a[3-i-j] = a[2] - t.a[i] - t.a[j];
				if (!vis[t.a[0]][t.a[1]]) {
					vis[t.a[0]][t.a[1]] = true;
					t.m = u.m + p;
					q.push(t);
				}
			}
		}
		printf("%d %d\n", ansp, d - dis);
	}
	return 0;
}
