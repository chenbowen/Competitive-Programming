#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <map>

using namespace std;

#define LOCAL
#define inf 0x7fffffff
#define maxn 35
int m, n, a[maxn*maxn], w;
double min_h, ans, p;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T = 0;
    while (scanf("%d%d", &m, &n) == 2 && m) {
        min_h = inf;
        a[m*n+1] = inf;
        for (int i = 1; i <= m * n; i++) {
            scanf("%d", &a[i]);
            min_h = min(min_h, a[i] * 1.0);
        }
        scanf("%d", &w);
        sort(a + 1, a + m * n + 1);
        if (w == 0) {
            p = 0.0;
            ans = min_h;
        } else {
            ans = 0;
            for (int i = 1; i <= m * n; i++) {
                ans += a[i];
                double temp = (double(w) / 100.0 + ans) / double(i);
                if (temp >= a[i] && temp <= a[i + 1]) {
                    ans = temp;
                    p = i / double(m * n);
                    break;
                }
            }

        }
        printf("Region %d\nWater level is %.2f meters.\n", ++T, ans);
        printf("%.2f percent of the region is under water.\n\n", p * 100.0);
    }
    return 0;
}