//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
int n, m;
int f[1010][1010];
int w[1010], v[1010];
int main() {
	scanf("%d%d", &n, &m);
	for(re int i = 1; i <= n; ++i)
		scanf("%d%d", &w[i], &v[i]);
	for(re int i = n; i >= 1; --i) {
		for(re int j = 0; j <= m; ++j) {
			f[i][j] = f[i + 1][j];
			if(j >= w[i] && f[i][j] < f[i + 1][j - w[i]] + v[i])
				f[i][j] = f[i + 1][j - w[i]] + v[i];
		}
	}
	int tem = m;
	for(re int i = 1; i <= n; ++i) {
		if(tem <= 0)
			break;
		if(tem >= w[i] && f[i][tem] == f[i + 1][tem - w[i]] + v[i]) {
			printf("%d ", i);
			tem -= w[i];
		}
	}
	putchar('\n');
	return 0;
}
