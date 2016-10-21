#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctype.h>

using namespace std;

#define N 100
char a[N];
double mc = 12.01, mh = 1.008, mo = 16, mn = 14.01;
#define LOCAL

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", a);
        double tot = 0.0;
        for (int i = 0; i < strlen(a); i++) if (isalpha(a[i])) {
            int num = 0;
            for (int j = i + 1; j < strlen(a); j++) {
                if (isalpha(a[j])) break;
                num = num * 10 + a[j] - '0';
            }
            num = max(num, 1);
            
            switch(a[i]) {
                case 'C': tot += num * mc; break;
                case 'H': tot += num * mh; break;
                case 'O': tot += num * mo; break;
                case 'N': tot += num * mn; break;
            }
        }
        printf("%.3f\n", tot);
        
    }
    
    return 0;
}
