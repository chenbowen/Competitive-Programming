#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

#define LOCAL
#define maxn 30
string s;
set<string> m;


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) if (!isalpha(s[i])) s[i] = ' ';
        stringstream ss(s);
        while (ss >> s) {
            for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
            m.insert(s);
        }
    }
    for (auto it = m.begin(); it != m.end(); it++) cout << *it << endl;
    
    
    return 0;
}