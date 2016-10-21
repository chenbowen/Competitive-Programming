#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctype.h>

using namespace std;

#define LOCAL
#define MAXN 10
char puzzle[MAXN][MAXN], c;
int x, y, dead;

void find_space() {
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (!isalpha(puzzle[i][j])) {
                puzzle[i][j] = ' ';
                x = i;
                y = j;
                break;
            }
}

void output() {
    if (dead) printf("This puzzle has no final configuration.\n");
    else
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) 
                printf("%c ", puzzle[i][j]);
            printf("%c\n", puzzle[i][4]);
        }
}

void update(int xx, int yy) {
    int nx = xx + x, ny = yy + y;
    if (nx < 0 || nx > 4 || ny < 0 || ny > 4) {
        dead = 1;
        return;
    }
    swap(puzzle[x][y], puzzle[nx][ny]);
    x = nx;
    y = ny;
}

void move(char order) {
    if (dead) return;
    switch (order) {
        case 'A':
            update(-1, 0);
            break;
        case 'B':
            update(1, 0);
            break;
        case 'L':
            update(0, -1);
            break;
        case 'R':
            update(0, 1);
            break;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int T = 0;
    while (cin.getline(puzzle[0], 6) && puzzle[0][0] != 'Z') {

        for (int i = 1; i < 5; i++) cin.getline(puzzle[i], 6);
        dead = 0;
        find_space();

        while (c != '0') {
            c = getchar();
            move(c);
        }
        c = getchar();

        if (T++) printf("\n");
        printf("Puzzle #%d:\n", T);
        output();
    }


    return 0;
}
