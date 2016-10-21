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
#define MAXL 80
int n, m;
string data[10001][40];
map<string, int> ID;
map<pair<int, int>, int> rec;

int getID(string s) {
    if (ID.count(s)) return ID[s];
    ID[s] = ID.size();
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (cin >> n >> m) {
        getchar();
        ID.clear();
        string t;
        
        for (int i = 1; i <= n; i++) {
            getline(cin, t);
            int j, last, k;
            for (j = last = 0, k = 1; j < t.length(); j++) if (t[j] == ',') {
                    data[i][k] = t.substr(last, j - last);
                    getID(data[i][k++]);
                    last = j + 1;
                }
            data[i][k] = t.substr(last, j - last);
            getID(data[i][k++]);
        }
        bool YES = true;
        int r1, r2, c1, c2;
        for (int i = 1; i <= m && YES; i++)
            for (int j = i + 1; j <= m && YES; j++) {
                rec.clear();
                for (int k = 1; k <= n; k++) {
                    pair<int, int> p(getID(data[k][i]), getID(data[k][j]));
                    if(rec.count(p)) { 
                        YES = false; 
                        c1 = i; c2 = j;
                        r1 = rec[p];
                        r2 = k;
                        break;
                    }
                    rec[p] = k;
                }
            }
        if (YES) cout << "YES\n";
        else cout << "NO\n" << r1 << " " << r2 << "\n" << c1 << " " << c2 << "\n";
    }
    return 0;
}