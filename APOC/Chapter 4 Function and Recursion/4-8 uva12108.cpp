#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <map>

using namespace std;

#define LOCAL  
#define inf 10000
int n, n_sleep, temp;
bool flag;

typedef struct Student {
    int a, b, c;
    bool is_sleep;
    Student(int a = 0, int b = 0, int c = 0):a(a), b(b), c(c) {}
    bool init() {
        if (c > a) {
            is_sleep = true;
            c -= a;
        }
        else is_sleep = false;
        return is_sleep;
    }
    void time_to_choose() {
        if (is_sleep && c == b) {
            c = 1;
            is_sleep = false;
            n_sleep--;
        }
        else if (!is_sleep && c == a) {
            c = 1;
            if (temp > n - temp) {
                is_sleep = true;
                n_sleep++;
            }
        }
        else c++;
    }
}Student;
Student s[15];


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T = 0;
    while (scanf("%d", &n) == 1 && n) {
        temp = n_sleep = flag = 0;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            s[i] = Student(a, b, c);
            if (s[i].init()) n_sleep++;
        }
        
        for (int i = 1; i < inf; i++) {
            temp = n_sleep;
            if (n_sleep == 0) {
                printf("Case %d: %d\n", ++T, i);
                flag = true;
                break;
            }
            for (int j = 0; j < n; j++) s[j].time_to_choose();
        }
        if (!flag) printf("Case %d: -1\n", ++T);
        
    }
    
    return 0;
}