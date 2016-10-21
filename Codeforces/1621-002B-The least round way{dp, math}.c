#define                             LOCAL
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define F(i,n)                      for(int i=0;i<(n);++i)
#define FOR(i,x,y)                  for(int i=(x);i<=(y);++i)
#define FD(i,n)                     for(int i=(n-1);i>=0;--i)
#define FORD(i,y,x)                 for(int i=(y);i>=(x);--i)
#define MEM(x,i)                    memset(x,i,sizeof(x))
#define mp                          make_pair
#define DB(a)                       cout<<(a)<<endl
#define WHATIS(a)                   cout<<#a<<" is "<<a<<endl
#define BUG                         puts("here!!!")
#define fi                          first
#define se                          second
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define s(n)                        scanf("%d",&(n))
#define sc(n)                       scanf("%c",&(n))
#define sl(n)                       scanf(LLD,&(n))
#define sf(n)                       scanf("%lf",&(n))
#define ss(n)                       scanf("%s",&(n))
typedef vector<int> VI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1010;
int n, a[maxn][maxn], f[maxn][maxn], _2[maxn][maxn], _5[maxn][maxn];
PII path[2][maxn][maxn];
char s[2*maxn];

int discompose(int i, int j, int num) {
    int cnt = 0, t = a[i][j];
    while (t && t % num == 0) {
        cnt++;
        t /= num;
    }
    return cnt;
}

int dp(int (*c)[maxn], PII (&p)[maxn][maxn]) {
    MEM(f, 0);
    F(i, n) F(j, n) {
        if (i || j) f[i][j] = INF;
        if (i && f[i-1][j] < f[i][j]) {
            f[i][j] = f[i-1][j];
            p[i][j] = mp(-1, 0);
        }
        if (j && f[i][j-1] < f[i][j]) {
            f[i][j] = f[i][j-1];
            p[i][j] = mp(0, -1);
        }
        f[i][j] += c[i][j];
    }
    return f[n-1][n-1];
}

void make_path(PII (&p)[maxn][maxn]) {
    int i = n-1, j = n-1, t;
    F(k, 2*n-2) {
        t = i;
        s[2*n-3-k] = (p[i][j].fi == -1 && !p[i][j].se ? 'D' : 'R');
        i += p[t][j].fi, j += p[t][j].se;
    }

}

int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    s(n);
    bool has0 = false;
    int x, y;
    F(i, n) F(j, n) {
        s(a[i][j]);
        if (!a[i][j]) {
            has0 = true;
            x = i, y = j;
            a[i][j] = 10;
        }
        _2[i][j] = discompose(i, j, 2);
        _5[i][j] = discompose(i, j, 5);
    }
    bool minis2 = true;
    int ans = dp(_2, path[1]); 
    if (dp(_5, path[0]) < ans) minis2 = false, ans = f[n-1][n-1];
    if (has0 && ans) {
        ans = 1;
        int i = 0, j = 0, k = 0;
        while (i++ < x) s[k++] = 'D';
        while (j++ < y) s[k++] = 'R';
        while (i++ < n) s[k++] = 'D';
        while (j++ < n) s[k++] = 'R';
    }
    else make_path(path[minis2]);
    printf("%d\n", ans);
    printf("%s", s);
    return 0;
}
