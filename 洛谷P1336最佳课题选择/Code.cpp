//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: cerr;
typedef long long ll;
#define re register
const int Maxn = 200 + 10;
const int Maxm = 20 + 10;
const ll INF = 2147483648LL;
int n, m;
ll a[Maxn], b[Maxn], f[Maxn];
ll v[Maxm][Maxn], num[Maxn][Maxm];
inline ll qw(ll x, ll y) {
	if(num[x][y] != -1)
		return num[x][y];
	ll ans = 1;
	ll xx = x, yy = y;
	while(y) {
		if(y & 1)
			ans = ans * x;
		x = x * x;
		y >>= 1;
	}
	num[xx][yy] = ans;
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for(re int i = 1; i <= m; ++i)
		scanf("%lld%lld", &a[i], &b[i]);
	memset(num, -1, sizeof(num));
	for(re int i = 1; i <= m; ++i) {
		for(re int j = 1; j <= n; ++j)
			v[i][++v[i][0]] = a[i] * qw(j, b[i]);
	}
	for(re int i = 1; i <= n; ++i)
		f[i] = INF;
	for(re int i = 1; i <= m; ++i) {
		for(re int j = n; j >= 0; --j)
			for(re int k = 0; k <= j; ++k) {
				f[j] = std :: min(f[j], f[j - k] + v[i][k]);
//				cerr << f[j] << " ";
			}
	}
	printf("%lld\n", f[n]);
	return 0;
}
