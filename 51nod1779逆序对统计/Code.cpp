//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
const int Maxn = 20 + 1;
const int INF = -808464433;
int n, m;
long long f[1 << Maxn];
int main() {
	scanf("%d%d", &n, &m);
	#define lim (1 << n)
	for(re int i = 1; i < lim; ++i)
		f[i] = INF;
//	std :: cerr << f[0] << '\n';
	f[0] = 0;
	for(re int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		for(re int j = 0; j < lim; ++j) {
			if(f[j] != INF && ((j >> x) & 1) == 0) {
				int num = 0;
				for(re int k = x + 1; k <= n; ++k)
					num += ((j >> k) & 1);
				f[j | (1 << x)] = std :: max(f[j | (1 << x)], f[j] + num);
			}	
		}
	}
	printf("%lld\n", f[lim - 1]);
	return 0;
}
