#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const int maxn  = 55;
const int maxc = 1001;
#define REP(i, n) for (int i = 0; i < n; i++)
int n, T, nx, ny, nz;
int x0[maxn], x1[maxn], y0[maxn], y1[maxn], z0[maxn], z1[maxn];
int xs[maxn * 2], ys[maxn * 2], zs[maxn * 2];
int color[maxn * 2][maxn * 2][maxn * 2];


int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void discretize(int *a, int& na) {
    sort(a, a + na);
    na = unique(a, a + na) - a;
}

int ID(int *a, int na, int v) {
    return lower_bound(a, a + na, v) - a;
}

struct Cell {
    int x, y, z;

    Cell(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {
    }

    bool valid() const{
        return x >= 0 && y >= 0 && z >= 0 && x < nx - 1 && y < ny - 1 && z < nz - 1;
    }

    bool solid() const{
        return color[x][y][z] == 1;
    }

    bool getVis() const{
        return color[x][y][z] == 2;
    }

    void setVis() const{
        color[x][y][z] = 2;
    }

    Cell neighbor(int dir) const{
        return Cell(x + dx[dir], y + dy[dir], z + dz[dir]);
    }

    int volume() const{
        return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
    }

    int area(int dir) const{
        if (dx[dir] != 0) return (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
        if (dy[dir] != 0) return (xs[x + 1] - xs[x]) * (zs[z + 1] - zs[z]);
        return (ys[y + 1] - ys[y]) * (xs[x + 1] - xs[x]);
    }

};

void floodfill(int& v, int& s) {
    s = v = 0;
    Cell c;
    c.setVis();
    queue<Cell> q;
    q.push(c);
    while (!q.empty()) {
        Cell t = q.front();
        q.pop();
        v += t.volume();

        REP(i, 6) {
            Cell c2 = t.neighbor(i);
            if (!c2.valid()) continue;
            if (c2.solid()) s += t.area(i);
            else if (!c2.getVis()) {
                c2.setVis();
                q.push(c2);
            }
        }
    }
    v = maxc*maxc*maxc - v;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        nx = ny = nz = 2;
        xs[0] = ys[0] = zs[0] = 0;
        xs[1] = ys[1] = zs[1] = maxc;

        REP(i, n) {
            scanf("%d%d%d%d%d%d", &x0[i], &y0[i], &z0[i], &x1[i], &y1[i], &z1[i]);
            x1[i] += x0[i];
            y1[i] += y0[i];
            z1[i] += z0[i];
            xs[nx++] = x0[i];
            xs[nx++] = x1[i];
            zs[nz++] = z0[i];
            zs[nz++] = z1[i];
            ys[ny++] = y0[i];
            ys[ny++] = y1[i];

        }
        discretize(xs, nx);
        discretize(ys, ny);
        discretize(zs, nz);
        memset(color, 0, sizeof (color));

        REP(i, n) {
            int X1 = ID(xs, nx, x0[i]), X2 = ID(xs, nx, x1[i]);
            int Y1 = ID(ys, ny, y0[i]), Y2 = ID(ys, ny, y1[i]);
            int Z1 = ID(zs, nz, z0[i]), Z2 = ID(zs, nz, z1[i]);
            for (int X = X1; X < X2; X++)
                for (int Y = Y1; Y < Y2; Y++)
                    for (int Z = Z1; Z < Z2; Z++)
                        color[X][Y][Z] = 1;
        }
        int s, v;
        floodfill(v, s);
        printf("%d %d\n", s, v);
    }
    return 0;
}