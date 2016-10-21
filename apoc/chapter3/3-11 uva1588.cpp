#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

#define LOCAL   
#define maxn 100 + 10
string s1, s2;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (cin >> s1 >> s2) {
        if (s1.length() > s2.length()) swap(s1, s2);
        int n1 = s1.length(), n2 = s2.length();
        int ans = n1 + n2;
        bool flag;
        
        for (int i = -n1; i < 0; i++) {
            flag = true;
            for (int j = 0; j < i + n1 && flag; j++)
                if (s2[j] == '2' && s1[j - i] == '2') flag = false;
            if (flag) ans = min(ans, n2 - i);
        }
        
        for (int i = 0; i < n2; i++) {
            flag = true;
            for (int j = 0; i + j < n2 && j < n1 && flag; j++) 
                if (s1[j] == '2' && s2[i + j] == '2') flag = false;
            if (flag) ans = min(ans, max(i + n1, n2));
        }
        printf("%d\n", ans);
    }
    return 0;
}