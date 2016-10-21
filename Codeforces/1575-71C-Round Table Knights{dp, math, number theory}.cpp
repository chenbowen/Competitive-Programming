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
// #define              LOCAL   
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define sl(n)                       scanf(LLD,&(n))

const int N = 100010;
int n;
bool a[N], vis[N];



int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    s(n);
    bool yes = true;
    F(i, n)  {
        s(a[i]);
        yes &= a[i];
    }
    if (!yes) {
        int j, t;
        FOR (i, 3, n-1) {
            if (!vis[i] && n % i == 0) {
                // whatis(i);
                j = n / i;
                
                F(k, j) {
                    t = k;
                    yes = true;
                    while (t < n) {
                        // whatis(t), whatis(a[t]), whatis(yes);
                        yes &= a[t];
                        t += j;
                    }
                    if (yes) break;
                }
                if (yes) break;
                int k = i;
                while (k < n) {
                    vis[k] = true;
                    k += k;
                }
            }
        }
    }
    printf("%s", yes ? "YES" : "NO");
    return 0;
}
