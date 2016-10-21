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
    int n, t, ans = 0, tot = 0, sum = 0;
    scanf("%d", &n);
    VI a;
    F(i, n) {
        scanf("%d", &t);
        tot += t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    F(i, n) {
        sum += a[n-1-i];
        ans++;
        if (tot - sum < sum) break;
    }
    printf("%d", ans);
    return 0;
}
 
