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
const int maxn = 8;
#define REP(i, n) for (int i = 0; i < n; i++)
int n, order[maxn], m, T;
string leaf, t;
vector<int> ans;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> n, n) {
        ans.clear();
        REP(i, n) {
            cin >> t;
            order[i] = t[1] - '0';
        }
        cin >> leaf;
        cin >> m;
        while (m--) {
            cin >> t;
            int start = 0, end = leaf.size();

            REP(i, n) {
                if (t[order[i] - 1] == '1') start = (start + end)/2;
                else end = (start + end) / 2;
            }
            ans.push_back(leaf[start] - '0');
        }
        cout << "S-Tree #" << ++T << ":\n";
        REP(i, ans.size()) cout << ans[i];
        cout << "\n\n";
    }
    return 0;
}
