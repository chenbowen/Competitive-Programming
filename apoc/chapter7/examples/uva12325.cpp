/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-25
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
#define sl(n)                       scanf("%lld",&(n))
const int N = 5002;
LL n, s1, v1, s2, v2;
int T, kase;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	s(T);
	while(T--) {
		sl(n), sl(s1), sl(v1), sl(s2), sl(v2);
		if(v2*s1 > v1*s2) swap(s1, s2), swap(v1, v2);
		LL l = s1*s2 / gcd(s1, s2);
		int ans = (n/l)*(l/s1)*v1;
		n %= l;
		if (n) {
			int n1 = n/s1;
			int n2 = (n-s1*n1)/s2;
			int ans2 = n1*v1+n2*v2, t;
			while(n1>0) {
				if(s1>=s2) {
					n1--; 
					n2 = (n-s1*n1)/s2;
				}
				else {
					n2++;
					if(n < s2*n2) break;
					n1 = (n-s2*n2)/s1;
				}
				t = n1*v1+n2*v2;
				if(t <= ans2) break;
				ans2 = t;
			}
			ans += ans2;
		}
		printf("Case #%d: %d\n", ++kase, ans);
	}
	return 0;
}
