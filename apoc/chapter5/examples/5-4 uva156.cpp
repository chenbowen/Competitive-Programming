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
set<string> ans;
map<string, int> m;
map<string, string> m2;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (getline(cin, s)) {
        if (s[0] == '#') break;
        stringstream ss(s);
        while (ss >> s) {
            string t = s;
            for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
            sort(s.begin(), s.end());
            m2[s] = t;
            m[s]++;
        }
        
    }
    for (auto it = m.begin(); it != m.end(); it++) 
        if (it->second == 1) ans.insert(m2[it->first]);
    for (auto it = ans.begin(); it != ans.end(); it++) 
        cout << *it << endl;
    return 0;
}