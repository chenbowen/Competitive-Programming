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

#define MAXL 60
int n, width, cols, rows;
vector<string> names;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> n) {
        names.clear();
        width = 0;
        string t;
        for (int i = 0; i < n; i++) {
            cin >> t; 
            names.push_back(t);
            width = max(width, int(t.length()));
        }
        sort(names.begin(), names.end());
        cols = MAXL / width;
        if (cols * width + (cols - 1) * 2 > MAXL) cols--;
if (cols * width + (cols - 1) * 2 > MAXL) cols--;
        rows = (n - 1) / cols + 1;
        for (int i = 0; i < MAXL; i++) cout << "-";
        cout << "\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rows * j + i >= n) continue;
                cout << names[j * rows + i];
                int l = names[j * rows + i].length();
                for (int k = 0; k < width - l + 2; k++) cout << " ";
            }
            cout << "\n";
            
        }
    }
    return 0;
}