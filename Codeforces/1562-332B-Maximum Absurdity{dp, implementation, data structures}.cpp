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
#define bug                         puts("here!!!")
#define fi                          first
#define se                          second
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define s(n)                        scanf("%d",&(n))
#define sc(n)                       scanf("%c",&(n))
#define sf(n)                       scanf("%lf",&(n))
#define ss(n)                       scanf("%s",(n))
// #define     			LOCAL   
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define sl(n)                       scanf(LLD,&(n))

const int N = 200010;
int a[N], n, k;
LL sum1[N], sum2[N];
pair<int, LL> f1[N], f2[N];

// void calc() {

// }

int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    s(n), s(k);
    F(i, n) s(a[i]);
    sum1[0] = a[0];
    sum2[n-1]= a[n-1];
    FOR(i, 1, n-1) {
		sum1[i] = sum1[i-1] + a[i];
		sum2[n-i-1] = sum2[n-i] + a[n-1-i];
    }
    f1[k-1].fi = k-1;
    f1[k-1].se = sum1[k-1];
    f2[n-k].fi = n-k;
    f2[n-k].se = sum2[n-k];
    FOR(i, k, n-1) {
    	f1[i].fi = f1[i-1].fi;
    	f1[i].se = f1[i-1].se;
    	if (f1[i].se < sum1[i] - sum1[i-k]) {
    		f1[i].se = sum1[i] - sum1[i-k];
    		f1[i].fi = i;
    	}
    	int i2 = n-1-i;
    	f2[i2].fi = f2[i2+1].fi;
    	f2[i2].se = f2[i2+1].se;
    	if (f2[i2].se <= sum2[i2] - sum2[i2+k]) {
    		f2[i2].se = sum2[i2] - sum2[i2+k];
    		f2[i2].fi = i2;
    	}
    }

     // F(i, n) whatis(f2[i].se), whatis(f1[i].se);
    LL ans = 0;
    int a, b;
    FOR(i, k-1, n-k-1) {
    	// whatis(ans), whatis(f1[i].se + f2[i+1].se);
    	if (ans < f1[i].se + f2[i+1].se) {
    		ans = f1[i].se + f2[i+1].se;
    		a = f1[i].fi, b = f2[i+1].fi;
    	}
    	// whatis(b);
    }
    printf("%d %d", a+2-k, b+1);
	return 0;
}
