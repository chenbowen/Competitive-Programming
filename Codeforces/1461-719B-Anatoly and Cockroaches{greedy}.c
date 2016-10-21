// #define LOCAL
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
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define F(i,n)                      for(int i=0;i<(n);++i)
#define FOR(i,x,y)                  for(int i=(x);i<=(y);++i)
#define FD(i,n)                     for(int i=(n-1);i>=0;--i)
#define FORD(i,y,x)                 for(int i=(y);i>=(x);--i)
#define MEM(x,i)                    memset(x,i,sizeof(x))
#define mp                          make_pair
#define DB(a)                       cout<<(a)<<endl
#define BUG                         puts("here!!!")
#define fi                          first
#define se                          second
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf(LLD,&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
typedef vector<int> VI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;
int n;
char s[maxn];

int count(bool r) {
    int cntbr = 0, cntrb = 0;
    F(i, n) {
        if (r && s[i] == 'b') cntbr++;
        else if (!r && s[i] == 'r') cntrb++;
        r = !r;
    }
    return max(cntbr, cntrb);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif  
    scanf("%d", &n);
    scanf("%s", s);
    printf("%d", min(count(true), count(false)));
    return 0;
}
