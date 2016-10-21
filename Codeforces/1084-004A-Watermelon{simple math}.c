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

//#define LOCAL
#ifdef LOCAL
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
#define REP(i, n) for (int i = 0; i < n; i++)
const int maxn = 3e4 + 10;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    printf("%s", n<4||(n-2)%2 ? "NO" : "YES");
    return 0;
}
