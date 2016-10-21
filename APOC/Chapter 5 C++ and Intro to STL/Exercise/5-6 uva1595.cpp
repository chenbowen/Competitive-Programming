#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <functional>

using namespace std;

#define LOCAL
#define maxn 1010
int n, T;
pair<int, int> a[maxn];

bool cmp1(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int tx, ty, left_x = 1e5, right_x = -1e5, m;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &tx, &ty);
            a[i] = make_pair(tx, ty);
            left_x = min(left_x, tx);
            right_x = max(right_x, tx);
        }
        sort(a, a + n);
        sort(a + n / 2 , a + n, cmp1);
        m = left_x + right_x;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (a[i].first * 2 == m) continue;
            if (a[i].first + a[n - 1 - i].first != m || a[i].second != a[n - 1 - i].second) {
                flag = false;
                break;
            }
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}