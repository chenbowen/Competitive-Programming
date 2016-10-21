// #define                             LOCAL
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
const int maxn = 1010;
int n, l;
char s[maxn];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif  
    s(n);
    while (n--) {
        ss(s);
        int split = 0, l = strlen(s), r = 0, c = 0, t = 0;
        if (s[0] == 'R' && isdigit(s[1]) && strchr(s+1, 'C')) {
            bool isRow = true;
            FOR(i, 1, l-1) {
                if (isRow && s[i] == 'C') { isRow = false; continue;}
                if (isRow) r = r * 10 + s[i] - '0';
                else c = c * 10 + s[i] - '0';
            }
            char col[maxn];
            while (c) {
                col[t++] = (c-1) % 26 + 'A';
                c = (c-1)/26;
            }
            FORD(i, t-1, 0) printf("%c", col[i]);
            printf("%d\n", r);
        }
        else {
            //BC23
            bool isRow = false;
            F(i, l) { 
                if (!isRow && isdigit(s[i])) isRow = true;
                if (isRow) r = r * 10 + s[i] - '0';
                else c = c * 26 + s[i] - 'A' + 1;
            }
            printf("R%dC%d\n", r, c);
        }
    }
    return 0;
}


    
