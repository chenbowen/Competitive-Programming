#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctype.h>

using namespace std;

#define LOCAL
#define MAXN 3000 + 10
int r[MAXN],u[MAXN],s[MAXN];


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n,m,t;  
    while (cin >> n >> m) {  
        t = n;  
        memset(r, 0, sizeof(r));  
        memset(u, 0, sizeof(u));  
        int count = 0;  
        r[count++] = n/m;  
        n = n%m;  
        while (!u[n] && n) {  
            u[n] = count;  
            s[count] = n;  
            r[count++] = 10*n/m;  
            n = 10*n%m;  
        }  
        printf("%d/%d = %d",t,m,r[0]);  
        printf(".");  
        for (int i = 1 ; i < count && i <= 50 ; i++) {  
            if (n && s[i] == n) printf("(");  
            printf("%d",r[i]);  
        }  
        if (!n) printf("(0");  
        if (count > 50) printf("...");  
        printf(")\n");  
        printf("   %d = number of digits in repeating cycle\n\n",!n?1:count-u[n]);  
    }  

    return 0;
}
