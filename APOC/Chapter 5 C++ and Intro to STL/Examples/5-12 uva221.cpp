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
#define maxn (100+5)

struct Building {
    int id;
    double x, y, l, w, h;
    bool operator < (const Building& b) const{
        return x < b.x || (x == b.x && y < b.y);
    }
}b[maxn];

int n;
double x[maxn*2];

bool cover(double mx, int i) {
    return b[i].x <= mx && b[i].x + b[i].l >= mx;
}

bool vis(double mx, int i) {
    if (!cover(mx, i)) return false;
    for (int j = 0; j < n; j++) 
        if (b[j].y < b[i].y && b[j].h >= b[i].h && cover(mx, j)) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T = 0;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].l, &b[i].w, &b[i].h);
            x[i*2] = b[i].x; x[i*2+1] = b[i].x + b[i].l;
            b[i].id = i + 1;
        }
        sort(b, b + n);
        sort(x, x + 2*n);
        int m = unique(x, x + n*2) - x;
        if (T++) printf("\n");
        printf("For map #%d, the visible buildings are numbered as follows:\n%d", T, b[0].id);
        for (int i = 1; i < n; i++) 
            for (int j = 0; j < m - 1; j++) 
                if (vis((x[j] + x[j + 1]) / 2, i)) { printf(" %d", b[i].id); break;}
        printf("\n");
    }
    return 0;
}