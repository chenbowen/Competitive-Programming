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
const int N = 210;
int n, ans;
char s1[N], s2[N], s[N], t[N], e[N];

int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int T, kase = 0;
    s(T);
    while (T--) {
    	s(n), ss(s1), ss(s2), ss(e);
    	strcpy(s, s1);
    	strcpy(s+n, s2);
    	char st[N];
    	strcpy(st, s);
    	n <<= 1;
    	ans = -1;
    	int l = n >> 1;
    	if (strcmp(s, e) == 0) ans = 0;
    	else {
    		F(i, n) {
	    		F(j, l) {
	    			t[j*2] = s[j+l];
	    			t[j*2+1] = s[j];
	    		}
	    		t[n] = '\0';
	    		swap(t, s);
	    		if (strcmp(s, e) == 0) {
		    		ans = i+1;
		    		break;
		    	}
	    	}
    	}
    	printf("%d %d\n", ++kase, ans);
    }
	return 0;
}



