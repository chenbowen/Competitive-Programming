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
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <functional>

using namespace std;

#define LOCAL
const int maxn = 1e6;
#define REP(i, n) for (int i = 0; i < n; i++)
int cur;
char tree[maxn];
map<long long, int> cnt;


void dfs(int dep) {
    if (isdigit(tree[cur])) {
        long long a = 0;
        while (isdigit(tree[cur])) {
            a = a * 10 + tree[cur] - '0';
            cur++;
        }
        cnt[a<<dep]++;
    }
    else {
        cur++;
        dfs(dep+1);
        cur++;
        dfs(dep+1);
        cur++;
    }
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        cur = 0;
        cnt.clear();
        scanf("%s", tree);
        dfs(0);
        int sum = 0, mx = 0;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            sum += it->second;
            mx = max(it->second, mx);
        }
        printf("%d\n", sum-mx);
    }
    
    
    return 0;
}
