#define 	LOCAL	
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
const int N = 105;
int n, t;
PII f[10], a[N][10];
char s[N];

void print(int c, int l, int r, int x, int y) {
	// whatis(c),whatis(l),whatis(r), whatis(x),whatis(y);
	// db("------------");
	if (r == -1) {
		putchar(s[l]);
		return;
	}
	int bound;
	FOR(i, x, y-1) {
		if (a[i][l].fi != -1) {
			print(l, a[i][l].fi, a[i][l].se, x, i + 1);
			bound = i;
			break;
		}
	}
	// whatis(bound);
	FORD(i, y-1, bound) {
		if (a[i][r].fi != -1) {
			print(r, a[i][r].fi, a[i][r].se, bound + 1, i + 1);
			break;
		}
	}	
}
void init() {
	n = strlen(s);
    F(i, 10) {
    	f[i] = mp(-1, -1);
    }
    F(i, n) {
    	F(j, 10) {
    		a[i][j] = mp(-1, -1);
    	}
    }
	f[(s[0]-'0')%8] = mp(0, -1);
    a[0][(s[0]-'0')%8] = mp(0, -1);
}
int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    ss(s);
	init();
    FOR(i, 1, n - 1) {
    	vector<pair<int, PII> > pool;

    	int si = (s[i] - '0') % 8;
		pool.pb( mp(si, mp(i, -1)));

    	FOR(j, 1, 7) {
    		if (f[j].fi != -1){
		    	int t = (j * 2 + si) % 8;

		    	if ((f[t].fi == j && f[t].se == si) || t == j || t == si) {
		    		continue;
		    	}

				pool.pb( mp(t, mp(j, si)));

				if (!t) {
					break;
				}
		    }
    	}
	    for (auto &it : pool) {
	    	f[it.fi] = it.se;
	    	if (a[i][it.fi].fi == -1) {
	    		a[i][it.fi] = it.se;
	    	}
	    }
	    if (f[0].fi != -1) {
	    	break;
	    }
	}


	if (f[0].fi != -1) {
		printf("YES\n");
		print(0, f[0].fi, f[0].se, 0, n);
	}
	else printf("NO");
	
	return 0;
}

