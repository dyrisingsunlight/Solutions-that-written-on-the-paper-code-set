//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
inline ll sc() {
	ll xx = 0, ff = 1; char cch = gc;
	while(!isdigit(cch) && cch != EOF) {
		if(cch == '-')
			ff = -1; cch = gc;
	}
	while(isdigit(cch)) {
		xx = (xx << 1) + (xx << 3) + (cch ^ '0'); cch = gc;
	}
	return xx * ff;
}
inline void out(ll x) {
	if(x < 0)
		pc('-'), x = -x;
	if(x >= 10)
		out(x / 10);
	pc(x % 10 + '0');
}
ll n, tot;
ll pri[1000010 << 2], v[1000010 << 2], a[1000010 << 2];
void Sel(ll lim) {
	memset(v, 0, sizeof(v));
	memset(pri, 0, sizeof(pri));
	tot = 0;
	for(ll i = 2; i <= lim; ++i) {
		if(v[i] == 0) {
			pri[++tot] = i, v[i] = i;
		}
		for(ll j = 1; j <= tot; ++j) {
			if(pri[j] > v[i] || i * pri[j] > lim)
				break;
			v[i * pri[j]] = pri[j];
		}
	}
}
ll qw(ll x, ll y) {
	ll ans = 1;
	while(y) {
		if(y & 1)
			ans *= x;
		x *= x;
		y >>= 1;
	}
	return ans;
}
int main() {
	n = sc();
	Sel(n);
//	for(int i = 1; i <= num; ++i)
//		out(p[i]), pc('^'), out(c[i]), pc('\n');
	for(ll i = 1; i <= tot; ++i) {
		for(ll j = 1; qw(pri[i], j) <= n; ++j)
			a[i] += (ll)floor(n / qw(pri[i], j));
		out(pri[i]), pc(' '), out(a[i]), pc('\n');
	}
	return 0;
}
