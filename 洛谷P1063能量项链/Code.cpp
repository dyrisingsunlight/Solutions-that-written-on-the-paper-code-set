//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: max;
#define re register
const int Maxn = 100 + 10;
int n, ans;
int til[Maxn << 1], head[Maxn << 1];
int f[Maxn << 1][Maxn << 1];
int main() {
	scanf("%d", &n);
	for(re int i = 1; i <= n; ++i) {
		scanf("%d", &head[i]);
		head[i + n] = head[i];
		til[i - 1] = head[i];
		til[i - 1 + n] = til[i - 1];
	}
	til[n] = head[1];
	til[n + n] = til[n];
	for(re int k = 2; k <= n; ++k) {
		for(re int i = 1; i <= (n << 1) - k + 1; ++i) {
			re int j = i + k - 1;
			for(re int l = i; l < j; ++l)	
				f[i][j] = max(f[i][j], f[i][l] + f[l + 1][j] + head[i] * til[l] * til[j]);
		}
	}
	for(re int i = 1; i <= n; ++i)
		ans = max(ans, f[i][i + n - 1]);
	printf("%d\n", ans);
	return 0;
}
