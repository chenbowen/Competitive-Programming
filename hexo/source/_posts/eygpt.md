---
title: codevs 1288 埃及分数[4]
tags:
- 难度4
- IDA*
categories:
- apoc
- 07-暴力求解法
date: 2016-10-25 00:19:30
---
# 链接
[传送门](http://codevs.cn/problem/1288/)

# 难度
- 思考$4$
- 实现$4$

# 题意
将分数$a/b$用单位分数的和表示。例如$\frac{2}{3}=\frac{1}{2}+\frac{1}{6}$，不可以有重复的单位分数。当表示法不唯一时，加数少的更好。若加数相同则最小的分数越大越好。

# 思路
用迭代加深搜索，从小到大枚举深度上限$maxd$，每次只考虑不超过$maxd$的节点。这样，只要解的深度有限，则一定可以在有限时间内枚举到。对于每次给定的$maxd$，如果拓展到$i$层时，待分解的分数为$\frac{c}{d}$，而第$i$个分数为$\frac{1}{e}$，则如果$\frac{c}{d}\div\frac{1}{e}\geqslant maxd-i$，应剪枝。

# 代码
```cpp
const int N = 1010;
LL ans[N], t[N], maxd;

LL get_first(LL a, LL b) {
	return b/a+1;
}

bool dfs(LL d, LL from, LL a, LL b) {
	if (d == maxd) {
		if (b % a) return false;
		t[d] = b;
		if (t[maxd] < ans[maxd] || ans[maxd] == -1) 
			memcpy(&ans, &t, sizeof(LL) * (d+1));
		return true;
	}
	bool ok = false;
	for(LL c = max(get_first(a, b), from); ; c++) {
		if (a*c >= (maxd-d+1)*b) break;
		LL g = gcd(a*c-b, b*c);
		t[d] = c;
		if (dfs(d+1, c+1, (a*c-b)/g, (b*c)/g)) 
			ok = true;
	}
	return ok;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	int a, b;
	while(s(a), s(b) == 1) {
		bool ok = false;
		for(maxd = 1; maxd < 100; maxd++) {
			MEM(ans, -1);
			if (dfs(0, get_first(a,b), a, b)) {
				ok = true;
				break;
			}
		}
		if (ok) {
			printf("%d", ans[0]);
			F(i, maxd) printf(" %d", ans[i+1]);
		}
		else printf("No solution");
		printf("\n");
	}
	return 0;
}
```