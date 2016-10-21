#define     LOCAL   
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
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
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
#define bug                         puts("here!!!")
#define fi                          first
#define se                          second
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define s(n)                        scanf("%d",&(n))
#define sc(n)                       scanf("%c",&(n))
#define sl(n)                       scanf(LLD,&(n))
#define sf(n)                       scanf("%lf",&(n))
#define ss(n)                       scanf("%s",(n))
typedef vector<int> VI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const int N = 505;
int m, n, q, f[N][N];
char s[N][N];

void init() {
    s(n), s(m);
    F(i, n) {
        ss(s[i]);
    }
}



int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    init();
    F(i, n) {
        F(j, m) {
        	if (i) f[i][j] += f[i-1][j];
        	if (j) f[i][j] += f[i][j-1];
        	if (i && j) f[i][j] -= f[i-1][j-1];
            if (s[i][j] == '.') {
            	if (j && s[i][j-1] == '.') f[i][j]++;
            	if (i && s[i-1][j] == '.') f[i][j]++;
            }
        }
        // whatis(f[i][i]);
    }
    // whatis(f[2][19]);
    s(q);
    int ans, r1, r2, c1, c2;

    F(i, q) {
        s(r1),s(r2),s(c1),s(c2);
        r1--,r2--,c1--,c2--;
        ans = f[c1][c2];
        if (r2) {
        	ans -= f[c1][r2-1];
        	FOR(i, r1, c1) {
        		if (s[i][r2-1] == '.' && s[i][r2] == '.') ans--;
        	}
        }
        if (r1) { 
        	ans -= f[r1-1][c2];
        	FOR(i, r2, c2) {
        		if (s[r1-1][i] == '.' && s[r1][i] == '.') ans--;
        	}
        }
        if (r1 && r2) ans += f[r1-1][r2-1];
        printf("%d\n", ans);
    }

    return 0;
}
