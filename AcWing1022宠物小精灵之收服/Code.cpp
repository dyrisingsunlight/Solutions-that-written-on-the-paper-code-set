//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
int n, m, amo, ans, rest;
int f[1010][510];
int main() {
	scanf("%d%d%d", &n, &m, &amo);
	--m;
	for(re int i = 1; i <= amo; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		for(re int j = n; j >= 0; --j)
			for(re int k = m; k >= 0; --k)
				if(j >= x && k >= y)
					f[j][k] = std :: max(f[j][k], f[j - x][k - y] + 1);
	}
	for(re int i = 0; i <= m; ++i)
		if(ans < f[n][i]) {
			ans = f[n][i];
			rest = i;
		}
	printf("%d %d\n", ans, m - rest + 1);
	return 0;
}
