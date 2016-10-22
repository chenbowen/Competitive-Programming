---
title: UVa 725 - Division [1]
date: 2016-10-21 20:04:36
tags:
- brute force
categories:
- apoc
- 07-暴力求解法
- 难度1
---
# 链接
[传送门](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=666)

# 难度
- 思考$0$
- 实现$1$

# 题意
输入$n$，从大到小输出所有形如$abcde/fghij = n$的表达式，其中$a\sim j$是$0\sim 9$的排列(可有前导$0$)，$2\leqslant n\leqslant 79$

# 思路
略

# 实现
LRJ把两个数字拼成一个字符串，再排序，判重。更容易实现

# 代码
```cpp
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
  int n, kase = 0;
  char buf[99];
  while(scanf("%d", &n) == 1 && n) {
    int cnt = 0;
    if(kase++) printf("\n");
    for(int fghij = 1234; ; fghij++) {
      int abcde = fghij * n;
      sprintf(buf, "%05d%05d", abcde, fghij);
      if(strlen(buf) > 10) break;
      sort(buf, buf+10);
      bool ok = true;
      for(int i = 0; i < 10; i++)
        if(buf[i] != '0' + i) ok = false;
      if(ok) {
        cnt++;
        printf("%05d / %05d = %d\n", abcde, fghij, n);
      }
    }
    if(!cnt) printf("There are no solutions for %d.\n", n);
  }
  return 0;
}
```
