#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

#define LOCAL   
#define maxn 1000 + 10
int a[5], b[5], s[5], bi_b[35], bi_s[35], ans;

void init() {
    memset(bi_b, 0, sizeof (bi_b));
    memset(bi_s, 0, sizeof (bi_s));
    for (int i = 0; i < 4; i++) {
        b[i] = -1;
        s[i] = 256;
    }
    ans = -1;
}

bool biggerthan(int *a1, int *a2) {
    if (a1[0] > a2[0]) return true;
    if (a1[0] < a2[0]) return false;
    if (a1[1] > a2[1]) return true;
    if (a1[1] < a2[1]) return false;
    if (a1[2] > a2[2]) return true;
    if (a1[2] < a2[2]) return false;
    if (a1[3] > a2[3]) return true;
    if (a1[3] < a2[3]) return false;
    return true;
}

void print(int *a1) {
    for (int i = 0; i < 3; i++) printf("%d.", a1[i]);
    printf("%d\n", a1[3]);
}

void bi_print(int *bi_a1) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", bi_a1[i]);
        if (i % 8 == 0) putchar('.');
    }
    putchar('\n');
}

void tobinary(int *a1, int *bi_a1) {
    for (int i = 3; i >= 0; i--) {
        int t = a1[i], cnt = 0;
        while (t != 0) {
            bi_a1[(3 - i) * 8 + cnt++] = t % 2;
            t /= 2;
        }
    }
}

void to_decimal(int *bi_a1, int *a1) {
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            a1[3 - i] += bi_a1[i * 8 + j] << j;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int m;
    while (scanf("%d", &m) == 1) {
        init();

        for (int i = 0; i < m; i++) {
            scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
            if (biggerthan(a, b))
                for (int j = 0; j < 4; j++) b[j] = a[j];
            if (biggerthan(s, a))
                for (int j = 0; j < 4; j++) s[j] = a[j];
        }
        tobinary(b, bi_b);
        tobinary(s, bi_s);
        for (int i = 31; i >= 0; i--) if (bi_b[i] != bi_s[i]) {
            ans = i;
            break;
        }
        for (int i = 31; i >= 0; i--) {
            if (i > ans) bi_b[i] = 1;
            else bi_b[i] = bi_s[i] = 0;
        }
        memset(s, 0, sizeof(s));
        memset(b, 0, sizeof(b));
        to_decimal(bi_s, s);
        to_decimal(bi_b, b);
        print(s);
        print(b);
        
    }
    return 0;
}