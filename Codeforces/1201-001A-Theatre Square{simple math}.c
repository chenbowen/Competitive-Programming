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
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    long long n, m, a;
    scanf(LLD LLD LLD, &n, &m, &a);
    printf(LLD, (long long)((n+a-1.0)/a)*(long long)((m+a-1.0)/a));
    return 0;
}
