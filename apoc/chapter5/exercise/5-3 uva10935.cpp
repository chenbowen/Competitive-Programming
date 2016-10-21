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

int n, T;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d", &n) == 1 && n) {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);
        printf("Discarded cards:");

        while (q.size() > 2) {
            printf(" %d,", q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        if (q.size() == 2) {
            printf(" %d", q.front());
            q.pop();
        }
        printf("\nRemaining card: %d\n", q.front());
        
    }
    return 0;
}