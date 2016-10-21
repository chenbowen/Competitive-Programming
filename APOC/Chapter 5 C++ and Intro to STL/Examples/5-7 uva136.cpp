#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <functional>

using namespace std;


#define maxn 1010
typedef long long LL;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    LL ans, last = 0, i = 0;
    pq.push(1);
    while(i < 1500) {
        ans = pq.top(); pq.pop();
        if (ans == last) continue;
        i += 1;
        last = ans;
        pq.push(ans * 2);
        pq.push(ans * 3);
        pq.push(ans * 5);
    }
    
    printf("The 1500'th ugly number is %d.\n", ans);
    return 0;
}