#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define N 100
char a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", a);
        int tot = 0, flag = 0, temp;
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] != 'O') {
                flag = 0; 
                continue;
            }
            if (flag) temp += 1;
            else temp = 1;
            tot += temp;
            flag = 1;
        }
        printf("%d\n", tot);
        
    }
    
    return 0;
}
