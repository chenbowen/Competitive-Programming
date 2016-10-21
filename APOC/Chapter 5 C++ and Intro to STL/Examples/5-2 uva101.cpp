#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>

using namespace std;

//#define LOCAL
#define maxn 30
int n, a, b, h[maxn];
string cmd1, cmd2;
vector<int> piles[maxn];

void output() {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < piles[i].size(); j++) printf(" %d", piles[i][j]);
        putchar('\n');
    }
}
void reset(int x) {
    int i = h[x], j;
    for (j = 0; j < piles[i].size(); j++) if (piles[i][j] == x) break;
    for (int k = piles[i].size() - 1; k > j; k--) {
        piles[piles[i][k]].push_back(piles[i][k]);
        h[piles[i][k]] = piles[i][k];
        piles[i].pop_back();
    }

}

void add(int x, int y) {
    int i1 = h[x], i2 = h[y], j1;
    for (j1 = 0; j1 < piles[i1].size(); j1++) if (piles[i1][j1] == x) break;
    for (int i = j1; i < piles[i1].size(); i++) {
        piles[i2].push_back(piles[i1][i]);
        h[piles[i1][i]] = i2;
    }
    for (int i = piles[i1].size() - 1; i >= j1; i--) 
        piles[i1].pop_back();
    
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        piles[i].push_back(i);
        h[i] = i;
    }
    while (cin >> cmd1, cmd1 != "quit") {
        cin >> a >> cmd2 >> b;
        if (h[a] == h[b]) continue;
        if (cmd1 == "move") reset(a);
        if (cmd2 == "onto") reset(b);
        add(a, b);
        
    }
    output();
    return 0;
}