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
const int maxn = 2e5+10;
int n, t, p, f59, epos;
char s[maxn];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif  
    scanf("%d%d", &n, &t);
    scanf("%s", s);
    F(i, n) {
        if (s[i] == '.') p = i;
        if (p && !f59 && s[i] > '4') {
            f59 = i;
            break;
        }
    }
    if (!f59) printf("%s", s);
    else {
        bool addOne;
        while (t-- && f59 > p) {
            addOne = true;
            while(f59 > 0 && addOne) {
                f59--;
                if (s[f59] == '.') continue;
                if (s[f59] == '9') s[f59] = '0';
                else {
                    if (++s[f59] < '5') t = 0;
                    addOne = false;
                }
            }
        }
        f59 = max(f59, p-1);
        if (addOne) printf("1");
        F(i, f59+1) printf("%c", s[i]);
    }
    return 0;
}
