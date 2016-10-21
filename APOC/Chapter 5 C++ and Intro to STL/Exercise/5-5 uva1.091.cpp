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
#define max 120000
int n;
set<string> s, ans;

bool is_substr(string a, string b) {
    for (int i = 0; i < a.length(); i++) if (a[i] != b[i]) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string t;
    while (cin >> t) s.insert(t);
    auto i = s.begin();
    while (i != s.end()) {
        auto j = i;
        j++;
        while (j != s.end() && is_substr(*i, *j)) { 
            if (s.count((*j).substr((*i).length(), (*j).length() - (*i).length())))
                ans.insert(*j);
            j++;
        }
        i++;
    }
    for (i = ans.begin(); i != ans.end(); i++) cout << *i << endl;
    return 0;
}