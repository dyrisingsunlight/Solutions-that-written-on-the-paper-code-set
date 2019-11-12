//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
#define int ll
int sc()
{
	int xx = 0, ff = 1; char cch = gc;
	while(!isdigit(cch) && cch != EOF)
	{
		if(cch == '-') ff = -1; cch = gc;
	}
	while(isdigit(cch))
	{
		xx = (xx << 1) + (xx << 3) + (cch ^ '0'); cch = gc;
	}
	return xx * ff;
}
void out(int x)
{
	if(x < 0) pc('-'), x = -x;
	if(x >= 10) out(x / 10);
	pc(x % 10 + '0');
}
#undef int
const ll mod = 10007;
ll a, b, k, n, m, ans;
ll inv[1010];
ll c[1010][1010];
ll qw(ll x, ll y)
{
	ll res = 1LL;
	while(y)
	{
		if(y & 1) res = (res * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return res;
}
void D_F()
{
	inv[1] = 1;
	for(int i = 2; i <= 1001; ++i)
		inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
}
void C(ll n, ll m)
{
	c[1][1] = c[1][2] = 1;
	for(ll i = 2; i <= n; ++i)
		for(ll j = 1; j <= i + 1; ++j)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}
int main()
{
	a = sc(), b = sc(), k = sc(), n = sc(), m = sc();
	ll tem = qw(a, n);
	tem = (tem * qw(b, m)) % mod;
	D_F();
	C(k, n);
	ans = (c[k][n + 1] * tem) % mod;
	out(ans), pc('\n');
	return 0;
}
