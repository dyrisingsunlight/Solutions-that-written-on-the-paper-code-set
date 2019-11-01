//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
#define re register
const int mod = 1e8;
int n, m, cnt;
int a[20], s[1 << 13];
ll ans;
ll f[20][1 << 13];
int main() {
	scanf("%d%d", &n, &m);
	for(re int i = 1; i <= n; ++i) {
		for(re int j = 1; j <= m; ++j) {
			int x;
			scanf("%d", &x);
			a[i] <<= 1;
			a[i] += x;
		}
	}
	#define lim (1 << m)
	for(re int i = 0; i < lim; ++i) {
		if(!(i & (i << 1)) && !(i & (i >> 1)))
			s[++cnt] = i;
	}
	f[0][0] = 1;
	for(re int i = 1; i <= n; ++i) {
		for(re int j = 1; j <= cnt; ++j) {
			if((s[j] & a[i]) != s[j])
				continue;
			for(re int k = 0; k < lim; ++k) {
				if(!(s[j] & k))
					f[i][s[j]] = (f[i][s[j]] + f[i - 1][k]) % mod; 
			}
		}
	}
	for(re int i = 0; i < lim; ++i)
		ans = (ans + f[n][i]) % mod;
	printf("%lld\n", ans);
	return 0;
}
