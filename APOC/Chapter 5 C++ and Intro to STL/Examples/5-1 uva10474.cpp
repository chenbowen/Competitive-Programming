#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

#define LOCAL
#define maxn 10000 + 10
int a[maxn], n, q, t;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T = 0;
    while (scanf("%d%d", &n, &q) == 2 && n) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        printf("CASE# %d:\n", ++T);
        for (int i = 0; i < q; i++) {
            scanf("%d", &t);
            printf("%d ", t);
            int j = lower_bound(a, a + n, t) - a;
            if (a[j] == t) printf("found at %d\n", j + 1);
            else printf("not found\n");
        }
    }
    return 0;
}