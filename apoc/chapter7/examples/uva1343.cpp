/**
 * @authors Bowen Chen (chenbowen9612@gmail.com)
 * @date    2016-10-26
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
const int N = 24;
int A[N], maxd;
const int idx[8][7] = {
	{0, 2, 6, 11, 15, 20, 22},
	{1, 3, 8, 12, 17, 21, 23},
	{10, 9, 8, 7, 6, 5, 4},
	{19, 18, 17, 16, 15, 14, 13},
	{23, 21, 17, 12, 8, 3, 1},
	{22, 20, 15, 11, 6, 2, 0},
	{13, 14, 15, 16, 17, 18, 19},
	{4, 5, 6, 7, 8, 9, 10}
};
const int mid[] = {6, 7, 8, 11, 12, 15, 16, 17};
const int rev[] = {5, 4, 7, 6, 1, 0, 3, 2};
char ans[1000];
bool is_final() {
	F(i, 8) if(A[mid[i]] != A[mid[0]]) return false;
	return true;
}

inline void turn(int i) {
	int t = A[idx[i][0]];
	F(j, 6) A[idx[i][j]] = A[idx[i][j+1]];
	A[idx[i][6]] = t;
}

int diff(int k) {
	int cnt = 0;
	F(i, 8) if (A[mid[i]] != k) cnt++;
	return cnt;
}

inline int h() {
	return min(diff(1), min(diff(2), diff(3)));
}

bool dfs(int d) {
	if (is_final()) {
		ans[d] = '\0';
		printf("%s\n", ans);
		return true;
	}
	if(d + h() > maxd) return false;
	F(i, 8) {
	    ans[d] = 'A' + i;
	    turn(i);
	    if(dfs(d+1)) return true;
	    turn(rev[i]);
	}
  	return false;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	while(s(A[0]) == 1 && A[0]) {
		F(i, N-1) s(A[i+1]);
		F(i, N) if (!A[i]) return 0;
		if (is_final())
			printf("No moves needed\n");
		else 
			for(maxd = 1; ; maxd++) 
				if(dfs(0)) break;
		printf("%d\n", A[6]);
	}
	return 0;
}
