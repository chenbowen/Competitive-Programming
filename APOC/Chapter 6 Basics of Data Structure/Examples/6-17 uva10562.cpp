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
#define maxn 210
#define REP(i, n) for (int i = 0; i < n; i++)
int n, T;
vector<string> pic;

bool is_valid(int r, int c) {
    return !(r >= n || c >= pic[r].length() || r < 0 || c < 0);
}

bool is_node(int r, int c) {
    char ch = pic[r][c];
    return is_valid(r, c) && ch != '|' && ch != ' ' && ch != '-';
}

string dfs(int r, int c) {
    string t1 = "";
    t1.push_back(pic[r][c]);
    if (!is_valid(r+1, c) || pic[r+1][c] != '|') 
        return t1 + "()";
    
    int start = c, end = c;
    while (is_valid(r+2, start) && pic[r+2][start] == '-') start--;
    while (is_valid(r+2, end) && pic[r+2][end] == '-') end++;
    end = min(int(pic[r+3].length()), end);
    string t = "";
    for (int i = start + 1; i < end; i++)
        if (is_node(r+3, i)) 
            t += dfs(r+3, i);
    return t1 + "(" + t + ")";
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> T;
    getchar();
    while (T--) {
        pic.clear();
        string t;
        while (getline(cin, t), t[0] != '#')
            pic.push_back(t);
        n = pic.size();
        
        REP(i, pic[0].length()) if (is_node(0, i)) {
            cout << "(" + dfs(0, i) + ")" << endl;
            break;
        }
        if (n == 0) cout << "()" << endl;
    }
    return 0;
}