#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

#define LOCAL
#define maxn 1010
int n, m, t, T;
map<int, int> teamID;
queue<int> q, teams[maxn];
set<int> team_in_queue;

void init() {
        teamID.clear();
        team_in_queue.clear();
        while (!q.empty()) q.pop();
        for (int i = 0; i < maxn; i++)
            while (!teams[i].empty()) teams[i].pop();
        printf("Scenario #%d\n", ++T);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &n) == 1 && n) {
        init();
        for (int i = 0; i < n; i++) {
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &t);
                teamID[t] = i;
            }
        }
        char order[20];
        while (scanf("%s", order), order[0] != 'S') {
            if (order[0] == 'D') {
                int teamA = q.front();
                printf("%d\n", teams[teamA].front());
                teams[teamA].pop();
                if (teams[teamA].empty()) {
                    team_in_queue.erase(teamA);
                    q.pop();
                }
            }
            else {
                scanf("%d", &t);
                int teamA = teamID[t];
                teams[teamA].push(t);
                if (team_in_queue.count(teamA) == 0) {
                    team_in_queue.insert(teamA);
                    q.push(teamA);
                }
            }
        }
        putchar('\n');
    }
    return 0;
}