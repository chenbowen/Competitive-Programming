/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-29
 */
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
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <functional>
using namespace std;
typedef vector<int> VI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define F(i,n)                      for(int i=0;i<(n);++i)
#define FOR(i,x,y)                  for(int i=(x);i<=(y);++i)
#define FD(i,n)                     for(int i=(n-1);i>=0;--i)
#define FORD(i,y,x)                 for(int i=(y);i>=(x);--i)
#define MEM(x,i)                    memset(x,i,sizeof(x))
#define mp                          make_pair
#define db(a)                       cout<<(a)<<endl
#define whatis(a)                   cout<<#a<<" is "<<a<<endl
#define bug                         printf("\nhere!!!\n")
#define fi                          first
#define se                          second
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define s(n)                        scanf("%d",&(n))
#define sc(n)                       scanf("%c",&(n))
#define sf(n)                       scanf("%lf",&(n))
#define ss(n)                       scanf("%s",(n))
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define sl(n)                       scanf(LLD,&(n))
const int INFS = 0x3fffffff;
int grid[25][25], row, col, ans;
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

inline bool judge(int x, int y) {
    if (0 < x && x <= row && 0 < y && y <= col) {
        return true;
    }
    return false;
}

void dfs(int x, int y, int step) {
    if (step > 10)
        return ;

    for (int i = 0; i < 4; ++i) {
        int a = x, b = y, cflag = 0;
        while (judge(a, b)) {
            a += dir[i][0];
            b += dir[i][1];
            cflag += 1;

            if (grid[a][b] == 3) {
                ans = min(ans, step + 1);
                return ;
            }
            if (grid[a][b] == 1) 
                break ;
        }
        if (grid[a][b] == 1 && cflag > 1) {
            grid[a][b] = 0;
            dfs(a-dir[i][0], b-dir[i][1], step+1);
            grid[a][b] = 1;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
    while (scanf("%d%d", &col, &row) && col && row) {
        int x, y;
        memset(grid, 0, sizeof(grid));

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                scanf("%d", &grid[i][j]);
                if (grid[i][j] == 2) 
                    x = i, y = j;
            }
        }

        ans = INFS;
        dfs(x, y, 0);
        if (ans <= 10)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
}