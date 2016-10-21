#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

#define LOCAL   
#define maxn 100 + 10
int m, n, ans[maxn];
bool h[15][15], v[15][15];

bool in_square(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > n) return false;
    return true;
}

bool test_if_possible(int x, int y, int l) {
    if (!in_square(x, y + l)) return false;
    if (!in_square(x + l, y)) return false;
    if (!in_square(x + l, y + l)) return false;
    return true;
}

bool test_if_exist(int x, int y, int l) {
    for (int i = 0; i < l; i++)
        if (!h[x][y + i] || !h[x + l][y + i] || !v[x + i][y + l] || !v[x + i][y])
            return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T = 0, x, y;
    while (cin >> n >> m) {
        memset(h, 0, sizeof (h));
        memset(v, 0, sizeof (v));
        memset(ans, 0, sizeof (ans));
        char c;
        bool none = true;
        for (int i = 0; i < m; i++) {
            cin >> c >> x >> y;
            if (c == 'H') h[x][y] = 1;
            else v[y][x] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k < n; k++) {
                    if (test_if_possible(i, j, k))
                        if (test_if_exist(i, j, k)) {
                            ans[k]++;
                            none = false;
                        }
                }
        if (T > 0) cout << "\n**********************************\n\n";
        cout << "Problem #" << ++T << "\n\n";
        if (none) cout << "No completed squares can be found.\n";
        else
            for (int i = 1; i < n; i++) if (ans[i])
                    cout << ans[i] << " square (s) of size " << i << endl;


    }
    return 0;
}