#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctype.h>

using namespace std;

#define MAXN 100
char a[MAXN];
#define LOCAL

bool is_p(int n) {
    if (strlen(a) % n != 0) return false;
    for (int i = n; i < strlen(a); i++) 
        if (a[i] != a[i % n]) return false;
    return true;
}



int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int T, first = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", a);
        for (int i = 1; i <= strlen(a); i++) {
            if (is_p(i)) {
                if (!first) printf("\n");
                printf("%d\n", i);
                break;
            }
        }
        first = 0;
    }
    
    return 0;
}
