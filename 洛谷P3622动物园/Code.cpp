//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
int n, c, ans;
int num[10000 + 10][33], f[10000 + 10][33];
int main() {
	scanf("%d%d", &n, &c);
	#define lim (1 << 5)
	for(re int i = 1; i <= c; ++i) {
		int x, y, z;
		int fe = 0, li = 0;
		scanf("%d%d%d", &x, &y, &z);
		for(re int j = 1; j <= y; ++j) {
			int now;
			scanf("%d", &now);
			now = (now - x + n) % n;
			fe |= 1 << now;
		}
		for(re int j = 1; j <= z; ++j) {
			int now;
			scanf("%d", &now);
			now = (now - x + n) % n;
			li |= 1 << now;
		}
		for(re int j = 0; j < lim; ++j) {
			if((j & fe) || (~j & li))
				++num[x][j];
		}
	}
	for(re int i = 0; i < lim; ++i) {
		memset(f[0], 0xcf, sizeof(f[0]));
		f[0][i] = 0;
		for(re int j = 1; j <= n; ++j) {
			for(re int k = 0; k < lim; ++k) {
				f[j][k] = std :: max(f[j - 1][(k & 15) << 1], f[j - 1][(k & 15) << 1 | 1]) + num[j][k];
			}
		}
		ans = std :: max(ans, f[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}
