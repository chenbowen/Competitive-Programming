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
#define maxn 1010
#define REP(i, n) for (int i = 1; i <= n; i++)
int T, n, t[5], q;
deque<string> pro[maxn];
deque<int> que, block_que;
map<char, int> v;

string delete_space(string& s1) {
    string s2;
    for (int i = 0; i < s1.length(); i++) if (s1[i] != ' ') s2.push_back(s1[i]);
    return s2;
}

void init() {
    block_que.clear();
    que.clear();
    REP(i, n) que.push_back(i);
    v.clear();
}

void read() {
    cin >> n >> t[0] >> t[1] >> t[2] >> t[3] >> t[4] >> q;
    string line;
    getchar();
    REP(i, n) {
        pro[i].clear();
        while (getline(cin, line)) {
            pro[i].push_back(delete_space(line));
            if (line == "end") break;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> T;
    while (T--) {
        read();
        init();
        bool lock = false;
        while (!que.empty()) {
            bool insert = true;
            int id = que.front(), Q = q;
            que.pop_front();
            while (Q > 0) {
                string command = pro[id].front();
                pro[id].pop_front();
                if (command == "end") {
                    insert = false;
                    break;
                }
                if (command[1] == '=') {
                    char s[20];
                    strcpy(s, command.substr(2, command.length() - 2).c_str());
                    int value;
                    sscanf(s, "%d", &value);
                    v[command[0]] = value;
                    Q -= t[0];
                } else if (command.substr(0, 5) == "print") {
                    printf("%d: %d\n", id, v[command[5]]);
                    Q -= t[1];
                } else if (command == "lock") {
                    if (lock) {
                        pro[id].push_front(command);
                        block_que.push_back(id);
                        insert = false;
                        break;
                    } else {
                        lock = true;
                        Q -= t[2];
                    }
                } else {
                    if (!block_que.empty()) {
                        que.push_front(block_que.front());
                        block_que.pop_front();
                    }
                    lock = false;
                    Q -= t[3];
                }
            }
            if (insert) que.push_back(id);
        }
        if (T) printf("\n");
    }
    return 0;
}