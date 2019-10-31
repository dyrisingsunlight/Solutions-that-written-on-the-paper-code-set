//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using std :: max;
#define re register
const int Maxn = 262144;
int n, ans;
int a[Maxn + 10];
int f[60][Maxn + 1];
int main() {
	scanf("%d", &n);
	for(re int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		f[a[i]][i] = i + 1;
		ans = max(ans, a[i]);
	}
	for(re int i = 1; i <= (int)log2(Maxn) + 40; ++i)
		for(re int j = 1; j <= n; ++j) {
			if(!f[i][j])
				f[i][j] = f[i - 1][f[i - 1][j]];
			if(f[i][j])
				ans = max(ans, i);
		}
	printf("%d", ans);
	return 0;
}
