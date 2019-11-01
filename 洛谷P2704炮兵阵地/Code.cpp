//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: cerr;
typedef long long ll;
#define re register
int n, m, cnt;
int a[100 + 10], num[110], s[110];
ll ans;
ll f[4][110][110];
inline int Count(int S) {
	int res = 0;
	while(S) {
		S &= (S - 1);
		++res;
	}
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	for(re int i = 1; i <= n; ++i) {
		for(re int j = 0; j < m; ++j) {
			char c[2];
//			scanf("%c", &c[1]);
			std :: cin >> c[1];
			a[i] <<= 1;
			a[i] += (c[1] == 'P');
		}
	}
//	for(re int i = 1; i <= n; ++i)
//		cerr << a[i] << ' ';
//	cerr << '\n';
	#define lim (1 << m)
	for(re int i = 0; i < lim; ++i)
		if(!(i & (i << 1)) && !(i & (i << 2)) && !(i & (i >> 1)) && !(i & (i >> 2))) {
			s[++cnt] = i;
			num[cnt] = Count(i);
		}
//	for(re int i = 1; i <= cnt; ++i)
//		cerr << s[i] << ' ' << num[i] << '\n';
	#undef lim
	for(re int i = 1; i <= cnt; ++i)
		if((s[i] | a[1]) == a[1])
			f[1][i][0] = num[i];
	for(re int i = 1; i <= cnt; ++i)
		for(re int j = 1; j <= cnt; ++j) {
//			cerr << ((s[i] | a[2]) == a[2]) << ' ' << ((s[j] | a[1]) == a[1]) << ' ' << (s[i] & s[j]) << '\n';
			if((s[i] | a[2]) == a[2] && (s[j] | a[1]) == a[1] && (s[i] & s[j]) == 0) {
				f[2][i][j] = num[i] + num[j];
//				cerr << i << ' ' << j << '\n';
			}
		}
			
	for(re int i = 3; i <= n; ++i) {
		for(re int j = 1; j <= cnt; ++j) {
			if((s[j] | a[i]) != a[i])
				continue;
			for(re int k = 1; k <= cnt; ++k) {
				if((s[k] | a[i - 1]) != a[i - 1] || (s[k] & s[j]))
					continue;
				for(re int l = 1; l <= cnt; ++l) {
//					if((s[l] | a[i - 2]) != a[i - 2] || (s[k] & s[l]) || (s[j] & s[l]))
//						continue;
					if((s[l] | a[i-2]) == a[i-2] && !(s[j] & s[l]) && !(s[k] & s[l]))
						f[i % 3][j][k] = std :: max(f[i % 3][j][k], f[(i - 1) % 3][k][l] + num[j]);
//					cerr << f[i % 3][j][k] << '\n';
				}
			}
		}
	}
	for(re int i = 1; i <= cnt; ++i)
		for(re int j = 1; j <= cnt; ++j)
				ans = std :: max(ans, f[n % 3][i][j]);
	printf("%lld\n", ans);
	return 0;
}
