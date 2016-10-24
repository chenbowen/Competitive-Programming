---
title: UVa 10976 Fractions Again?! [1]
date: 2016-10-21 21:35:26
categories:
- apoc
- 07-暴力求解法
- 难度1
tags:
- brute force
- math
---
# 链接
[传送门](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917)

# 难度
- 思考$2$
- 实现$0$

# 题意
输入$k$，找到所有正整数$x\geqslant y$，使得$\frac{1}{k}=\frac{1}{x}+\frac{1}{y}$。$k\leqslant 10000$

# 思路
把等式变形一下得到$x=\frac{yk}{y-k}$，$y=\frac{xk}{x-k}$。又因为$x\geqslant y$，可得$x\geqslant 2k$，$k\leqslant y\leqslant 2k$，枚举$y$即可。

# 代码
```cpp
const int N = 10001;
int k, cnt, a[2*N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	while (s(k) == 1) {
		cnt = 0;
		for(int i = k+1; i <= 2*k; i++) {
			if ((i*k)%(i-k) == 0 && (i*k)/(i-k) >= i)
				a[cnt++] = i; 
		}
		printf("%d\n", cnt);
		F(i, cnt) printf("1/%d = 1/%d + 1/%d\n", k, (a[i]*k)/(a[i]-k), a[i]);
	} 
	return 0;
}
```
