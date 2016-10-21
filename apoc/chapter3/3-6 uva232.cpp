#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctype.h>

using namespace std;

#define LOCAL
#define MAXN 15
char puzzle[MAXN][MAXN];
int m, n, a[MAXN][MAXN];

bool above_test(int x, int y) {
    if (x == 0 || puzzle[x - 1][y] == '*') return true;
    return false;
}

bool left_test(int x, int y) {
    if (y == 0 || puzzle[x][y - 1] == '*') return true;
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int T = 0;
    while (scanf("%d%d", &m, &n) == 2) {
        for (int i = 0; i < m; i++) scanf("%s", puzzle[i]);

        memset(a, 0, sizeof (a));
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (puzzle[i][j] != '*' && (above_test(i, j) || left_test(i, j)))
                    a[i][j] = ++cnt;


        if (T++ > 0) putchar('\n');
        printf("puzzle #%d:\nAcross\n", T);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] && left_test(i, j)) {
                    printf("%3d.", a[i][j]);
                    int k = j;
                    while (k < n && puzzle[i][k] != '*') 
                        putchar(puzzle[i][k++]);
                    putchar('\n');
                }
        printf("Down\n");
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] && above_test(i, j)) {
                    printf("%3d.", a[i][j]);
                    int k = i;
                    while (k < m && puzzle[k][j] != '*') 
                        putchar(puzzle[k++][j]);
                    putchar('\n');
                }
    }

    return 0;
}
