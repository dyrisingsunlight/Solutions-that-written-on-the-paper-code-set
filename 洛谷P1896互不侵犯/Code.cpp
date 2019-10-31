//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
#define re register
const int Maxn = 9 + 1;
int n, m, cnt;
ll ans;
int sta[1 << Maxn], num[1 << Maxn];
ll f[Maxn][1 << Maxn][Maxn * Maxn];
inline int Cnt(int S) {
	int res = 0;
	while(S) {
		S &= (S - 1);
		++res;
	}
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	#define lim ((1 << n) - 1)
	for(re int i = 0; i <= lim; ++i)
		if(!(i & (i << 1)))
			sta[++cnt] = i, num[cnt] = Cnt(i), f[1][cnt][num[cnt]] = 1;
	for(re int i = 2; i <= n; ++i)
		for(re int j = 1; j <= cnt; ++j) {
			int nows = sta[j];
			for(re int k = 1; k <= cnt; ++k) {
				int nxts = sta[k];
				if((nows & nxts) || (nows & (nxts << 1)) || (nows & (nxts >> 1)))
					continue;
				for(re int l = 0; l <= m; ++l)
					f[i][j][l + num[j]] += f[i - 1][k][l];
			}
		}
	for(re int i = 1; i <= cnt; ++i)
		ans += f[n][i][m];
	printf("%lld\n", ans);
	return 0;
}
