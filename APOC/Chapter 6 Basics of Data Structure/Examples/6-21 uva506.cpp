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
const int maxn = 10010;
#define REP(i, n) for (int i = 0; i < n; i++)
int support[maxn], status[maxn];

struct Edge {
    int u, v;

    Edge(int u = -1, int v = -1) : u(u), v(v) {
    }
};

vector<Edge> edges;
vector<int> G[maxn];
map<string, int> id;
map<int, string> rev;
vector<int> installed;

int ID(string t) {
    if (id.count(t)) return id[t];
    rev[id.size()] = t;
    return id[t] = id.size() - 1;
}

void addEdge(string t1, string t2) {
    int u = ID(t1), v = ID(t2);
    edges.push_back(Edge(u, v));
    int idx = edges.size() - 1;
    G[u].push_back(idx);
}

void InstallDFS(int u, bool toplevel) {
    if (status[u]) {
        cout << "   " << rev[u] << " is already installed.\n";
        return;
    }
    status[u] = toplevel ? 1 : 2;

    REP(i, G[u].size()) {
        Edge e = edges[G[u][i]];
        int v = e.v;
        support[v]++;
        if (!status[v]) {
            InstallDFS(v, false);
        }
    }
    cout << "   Installing " << rev[u] << "\n";
    installed.push_back(u);
}

void removeDFS(int u, bool toplevel) {
    if (!status[u]) {
        cout << "   " << rev[u] << " is not installed.\n";
        return;
    }
    if (support[u]) {
        cout << "   " << rev[u] << " is still needed.\n";
        return;
    }
    if (!toplevel && status[u] == 1) return;
    status[u] = 0;
    cout << "   Removing " << rev[u] << "\n";

    REP(i, G[u].size()) {
        Edge e = edges[G[u][i]];
        int v = e.v;
        support[v]--;
        if (status[v] && !support[v])
            removeDFS(v, false);
    }
    installed.erase(remove(installed.begin(), installed.end(), u), installed.end());
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string cmd, t;
    while (getline(cin, cmd)) {
        cout << cmd << "\n";
        stringstream ss(cmd);
        ss >> cmd;
        if (cmd[0] == 'D') {
            ss >> t;
            while (ss >> cmd) {
                addEdge(t, cmd);
            }
        } else if (cmd[0] == 'I') {
            ss >> cmd;
            InstallDFS(ID(cmd), true);
        } else if (cmd[0] == 'L') {
            REP(i, installed.size())
            cout << "   " << rev[installed[i]] << '\n';
        } else if (cmd[0] == 'R') {
            ss >> cmd;
            removeDFS(ID(cmd), true);
        } else {
            break;
        }
    }
    return 0;
}
