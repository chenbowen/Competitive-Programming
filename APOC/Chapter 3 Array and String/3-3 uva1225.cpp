#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctype.h>

using namespace std;

#define MAXN 100
int a[MAXN];
#define LOCAL

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof(a));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int t = i;
            while (t != 0) {
                a[t % 10]++;
                t /= 10;
            }
        }
        for (int i = 0; i < 9; i++) printf("%d ", a[i]);
        printf("%d\n", a[9]);
    }
    
    return 0;
}
