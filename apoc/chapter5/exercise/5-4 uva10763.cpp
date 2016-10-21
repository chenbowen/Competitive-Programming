#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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
#define max 500005
int n;
map<pair<int, int>, int> s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &n) == 1 && n) {
        int a, b;
        bool flag = true;
        s.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            s[make_pair(a, b)]++;
        }
        for (auto i = s.begin(); i != s.end(); i++)
            if (s[make_pair(i->first.second, i->first.first)] != i->second) {
                flag = false;
                break;
            }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}