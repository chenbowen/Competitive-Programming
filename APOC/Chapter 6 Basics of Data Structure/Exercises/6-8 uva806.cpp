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
const int maxn = 70;
#define REP(i, n) for (int i = 0; i < n; i++)
int n, path[maxn], T, num;
int five[12] = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125};
char s[maxn][maxn];
vector<vector<int> > child;
vector<int> ans;

void newTree() {
    child.clear();
    ans.clear();
}

int newNode() {
    vector<int> t; REP(i, 4) t.push_back(-1);
    child.push_back(t);
    return child.size() - 1;
}

void build_tree(int r, int c, int dep, int u, int dir) {
    int m = n >> dep;
    bool allblack = true, allwhite = true;

    REP(i, m)REP(j, m) {
        if (s[r + i][c + j] == '0') allblack = false;
        else allwhite = false;
    }
    if (dep) path[dep] = dir;
    if (allblack || allwhite) {
        if (allblack) {
            int t = 0;
            REP(i, dep) t += five[dep - i - 1] * path[dep - i];
            ans.push_back(t);
        }
        return;
    }
    build_tree(r, c, dep + 1, child[u][0] = newNode(), 1);
    build_tree(r, c + (n >> (dep + 1)), dep + 1, child[u][1] = newNode(), 2);
    build_tree(r + (n >> (dep + 1)), c, dep + 1, child[u][2] = newNode(), 3);
    build_tree(r + (n >> (dep + 1)), c + (n >> (dep + 1)), dep + 1, child[u][3] = newNode(), 4);
}

void draw(int r, int c, vector<int> &p, int dep) {
    if (dep < p.size()) {
        if (p[dep] == 1) draw(r, c, p, dep + 1);
        else if (p[dep] == 2) draw(r, c + (n >> (dep + 1)), p, dep + 1);
        else if (p[dep] == 3) draw(r + (n >> (dep + 1)), c, p, dep + 1);
        else draw(r + (n >> (dep + 1)), c + (n >> (dep + 1)), p, dep + 1);
    } else {
        REP(i, n >> dep) REP(j, n >> dep) s[r + i][c + j] = '*';
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &n) == 1 && n) {
        if (++T > 1) printf("\n");
        printf("Image %d\n", T);
        if (n > 0) {
            REP(i, n) scanf("%s", s[i]);
            newTree();
            build_tree(0, 0, 0, newNode(), -1);
            sort(ans.begin(), ans.end());

            REP(i, ans.size()) {
                if (i % 12) printf(" ");
                printf("%d", ans[i]);
                if (i % 12 == 11) printf("\n");
            }
            if (ans.size() % 12) printf("\n");
            printf("Total number of black nodes = %d\n", ans.size());
        } else {
            n = -n;
            REP(i, n)REP(j, n) s[i][j] = '.';
            while (scanf("%d", &num), num != -1) {
                vector<int> p;
                while (num != 0) {
                    p.push_back(num % 5);
                    num /= 5;
                }
                draw(0, 0, p, 0);
            }

            REP(i, n) {
                REP(j, n) putchar(s[i][j]);
                putchar('\n');
            }
        }
    }
    return 0;
}
