//#define LOCAL
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
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
#define F(i,n) for(int i=0;i<(n);i++)
#define FOR(i,x,y) for(int i=(x);i<=(y);i++)
#define MEM(x,i) memset(x,i,sizeof(x))
#define DB(a) cout<<(a)<<endl
#define BUG puts("here!!!")
typedef vector<int> VI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
const int maxn = 1e3+10;
int ln[maxn];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif  
    int n, m = 0;
    scanf("%d", &n);
    bool isLucky = false;
    FOR(i, 3, maxn-1) {
        int t = i;
        bool f = true;
        while (t && f) {
            if (t % 10 != 4 && t % 10 != 7) f = false; 
            t /= 10;
        }
        if (f) {
            ln[m++] = i;
            if (i == n) isLucky = true;
        }
    }
    if (!isLucky)
        F(i, m) {
            if (n < ln[i]) break;
            if (n%ln[i] == 0) {
                isLucky = true;
                break;
            }
        }
    if (isLucky) printf("YES");
    else printf("NO");
    return 0;
}
 
