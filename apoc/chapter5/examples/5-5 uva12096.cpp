#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <sstream>

using namespace std;

#define LOCAL
#define maxn 30
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x, x.begin())
stack<int> a;
map<set<int>, int> IDcache;
vector<set<int>> Setcache;


int ID(set<int> x) {
    if (IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        while (!a.empty()) a.pop();
        int n;
        scanf("%d", &n);
        while (n--) {
            string order;
            cin >> order;
            if (order == "PUSH") a.push(ID(set<int>()));
            else if (order == "DUP") {
                set<int> t1 = set<int>(Setcache[a.top()]);
                a.push(ID(t1));
            } else if (order == "INTERSECT") {
                set<int> t1 = set<int>(Setcache[a.top()]);
                a.pop();
                set<int> t2 = set<int>(Setcache[a.top()]);
                a.pop();
                set<int> t3;
                set_intersection(ALL(t1), ALL(t2), INS(t3));
                a.push(ID(t3));
            } else if (order == "UNION") {
                set<int> t1 = set<int>(Setcache[a.top()]);
                a.pop();
                set<int> t2 = set<int>(Setcache[a.top()]);
                a.pop();
                set<int> t3;
                set_union(ALL(t1), ALL(t2), INS(t3));
                a.push(ID(t3));
            } else {
                set<int> t1 = set<int>(Setcache[a.top()]);
                a.pop();
                set<int> t2 = set<int>(Setcache[a.top()]);
                a.pop();
                t2.insert(ID(t1));
                a.push(ID(t2));
            }
            printf("%d\n", Setcache[a.top()].size());

        }
        printf("***\n");


    }



    return 0;
}