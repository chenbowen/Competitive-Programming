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
const int maxn = 53;
#define REP(i, n) for (int i = 0; i < n; i++)
int LEFT[maxn], RIGHT[maxn], front, tail, ans;
stack<string> pp[maxn];

void clear(int i) {
    while (!pp[i].empty()) pp[i].pop();
}

int search_back(int k, int cur) {
    int origin = cur;
    REP(i, k) cur = LEFT[cur];
    if (!cur) return 0;
    if (pp[cur].top()[0] == pp[origin].top()[0] || pp[cur].top()[1] == pp[origin].top()[1])
        return cur;
    return 0;
}

void deleteNode(int i) {
    if (i == tail) {
        RIGHT[LEFT[i]] = 0;
        tail = LEFT[i];
    } else if (i == front) {
        LEFT[RIGHT[i]] = 0;
        front = RIGHT[i];
    } else {
        LEFT[RIGHT[i]] = LEFT[i];
        RIGHT[LEFT[i]] = RIGHT[i];
    }
    ans--;
}

void init() {
    memset(LEFT, 0, sizeof (LEFT));
    memset(RIGHT, 0, sizeof (RIGHT));
    clear(1);
    front = 1, tail = maxn - 1;
    ans = maxn - 1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string ts;
    while (cin >> ts, ts[0] != '#') {
        init();
        pp[1].push(ts);

        REP(i, maxn - 2) {
            cin >> ts;
            clear(i + 2);
            LEFT[i + 2] = i + 1;
            RIGHT[i + 1] = i + 2;
            pp[i + 2].push(ts);
        }
        while (true) {
            bool None = true;
            for (int i = front; i != 0; i = RIGHT[i]) if (!pp[i].empty()) {
                    int left_3 = search_back(3, i), left_1 = search_back(1, i);
                    if (!left_3&&!left_1) continue;
                    if (left_1 && !left_3) left_3 = left_1;
                    pp[left_3].push(pp[i].top());
                    pp[i].pop();
                    if (pp[i].empty())
                        deleteNode(i);
                    None = false;
                    break;
                }
            if (None) break;
        }
        printf("%d", ans);
        if (ans > 1) printf(" piles remaining:");
        else printf(" pile remaining:");
        for (int i = front; i != 0; i = RIGHT[i]) printf(" %d", int(pp[i].size()));
        printf("\n");
    }
    return 0;
}
