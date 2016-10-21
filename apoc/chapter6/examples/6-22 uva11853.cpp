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
const int maxn = 1010;
#define REP(i, n) for (int i = 0; i < n; i++)
int n, idx;
double left_y[maxn], right_y[maxn];
vector<int> areas[maxn];
bool f[maxn], top[maxn], LEFT[maxn], RIGHT[maxn], bottom[maxn], stop;

void init() {
    REP(i, idx + 1) areas[i].clear();
    memset(f, 0, sizeof (f));
    memset(top, 0, sizeof (top));
    memset(LEFT, 0, sizeof (LEFT));
    memset(RIGHT, 0, sizeof (RIGHT));
    memset(bottom, 0, sizeof (bottom));
    REP(i, maxn) left_y[i] = right_y[i] = 1000;

    idx = 0;
    stop = false;
}

struct Circle {
    double x, y, r;

    Circle(double x = 0, double y = 0, double r = 0) : x(x), y(y), r(r) {
    }

    double distance(Circle& rhs) const {
        return sqrt((rhs.x - x)*(rhs.x - x)+(rhs.y - y)*(rhs.y - y));
    }

    bool intersect(Circle& rhs) {
        return distance(rhs) < r + rhs.r;
    }

    bool inter_bound(int dir) {
        // 1: up, 2: left, 3:bottom, 4:right
        Circle c2;
        if (dir == 1) c2 = Circle(x, 1000, 0);
        else if (dir == 2) c2 = Circle(0, y, 0);
        else if (dir == 3) c2 = Circle(x, 0, 0);
        else c2 = Circle(1000, y, 0);
        return intersect(c2);
    }
} c[maxn];

void dfs(int u, int id) {
    Circle &tc = c[u];
    f[u] = 1;
    areas[id].push_back(u);
    if (tc.inter_bound(1)) top[id] = true;
    if (tc.inter_bound(2)) LEFT[id] = true;
    if (tc.inter_bound(3)) bottom[id] = true;
    if (tc.inter_bound(4)) RIGHT[id] = true;
    if (LEFT[id])
        left_y[id] = min(left_y[id], tc.y - sqrt(tc.r * tc.r - tc.x * tc.x));
    if (RIGHT[id])
        right_y[id] = min(right_y[id], tc.y - sqrt(tc.r * tc.r - (1000 - tc.x) * (1000 - tc.x)));
    REP(i, n) if (!f[i] && tc.intersect(c[i])) dfs(i, id);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &n) == 1 && n) {
        init();
        REP(i, n) scanf("%lf%lf%lf", &c[i].x, &c[i].y, &c[i].r);

        REP(i, n) if (!f[i]) {
            dfs(i, idx++);
            if (top[idx - 1] && bottom[idx - 1]) {
                stop = true;
                break;
            }
        }
        if (stop) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        double entery = 1000, exity = 1000;
        REP(i, idx) if (top[i]) {
            if (LEFT[i]) entery = min(entery, left_y[i]);
            if (RIGHT[i]) exity = min(exity, right_y[i]);
        }
        printf("0.00 %.2f 1000.00 %.2f\n", entery, exity);
    }
    return 0;
}
