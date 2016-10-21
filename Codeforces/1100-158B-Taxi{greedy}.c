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
const int maxn = 2e2;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif  
    int n, t, ans = 0;
    scanf("%d", &n);
    VI a;
    F(i, n) {
        scanf("%d", &t);
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    int i = n-1, j = 0;
    while(i >= j && i >= 0) {
        ++ans;
        int t = a[i];
        while (t + a[j] <= 4) {
            j++;
            t += a[j];
        }
        i--;
    }
    printf("%d", ans);
    return 0;
}
 
