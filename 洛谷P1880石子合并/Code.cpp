//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: max;
using std :: min;
#define re register
const int Maxn = 100 + 10;
int n, ans, res = 0x3f3f3f3f;
int a[Maxn << 1], sum[Maxn << 1];
int f[Maxn << 1][Maxn << 1], g[Maxn << 1][Maxn << 1];
int main() {
	scanf("%d", &n);
	memset(g, 0x3f, sizeof(g));
	for(re int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]), a[i + n] = a[i];
	}
	for(re int i = 1; i <= (n << 1); ++i)
		g[i][i] = 0, sum[i] = sum[i - 1] + a[i];
	for(re int k = 2; k <= n; ++k) {
		for(re int i = 1; i <= (n << 1) - k + 1; ++i) {
			re int j = i + k - 1;
			for(re int l = i; l < j; ++l) {
				f[i][j] = max(f[i][j], f[i][l] + f[l + 1][j]);
				g[i][j] = min(g[i][j], g[i][l] + g[l + 1][j]);
			}
			g[i][j] += (sum[j] - sum[i - 1]);
			f[i][j] += (sum[j] - sum[i - 1]);
		}
	}
	for(re int i = 1; i <= n; ++i) {
		ans = max(ans, f[i][i + n - 1]);
		res = min(res, g[i][i + n - 1]);
	}
	printf("%d\n%d\n", res, ans);
	return 0;
}
