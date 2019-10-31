//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
#define re register
const int Maxn = 18 + 1;
int n, m, N;
int a[Maxn];
int Map[Maxn][Maxn];
ll ans;
ll f[1 << Maxn][Maxn];
inline int Cnt(int S) {
	int res = 0;
	while(S) {
		S &= (S - 1);	
		++res;
	}
	return res;
}
int main() {
	scanf("%d%d%d", &n, &m, &N);
	for(re int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		f[1 << i][i] = a[i];
	}
	for(re int i = 1; i <= N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		scanf("%d", &Map[x - 1][y - 1]);
	}
	#define lim ((1 << n) - 1)
	for(re int i = 0; i <= lim; ++i) {
		int sum = Cnt(i);
		for(re int j = 0; j < n; ++j) {
			if(!(i & (1 << j)))
				continue;
			for(re int k = 0; k < n; ++k) {
				if(j == k || (!(i & (1 << k))))
					continue;
				f[i][j] = std :: max(f[i][j], f[i ^ (1 << j)][k] + a[j] + Map[k][j]);
			}
			if(sum == m)
				ans = std :: max(ans, f[i][j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
