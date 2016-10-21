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
#define maxn 1001
int n, T, a[20];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        bool flag = false;
        for (int i = 0; i < maxn; i++) {
            int sum = 0, t = a[0];
            for (int j = 0; j < n; j++) {
                if (j != n - 1)
                    a[j] = abs(a[j] - a[j + 1]);
                else 
                    a[j] = abs(a[n - 1] - t);
                sum += a[j];
            }
            if (sum == 0) { flag = true; break;}
        }
        if (flag) printf("ZERO\n");
        else printf("LOOP\n");

    }



    return 0;
}