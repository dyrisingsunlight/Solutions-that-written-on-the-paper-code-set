//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
void out(ll x)
{
	if(x < 0) pc('-'), x = -x;
	if(x >= 10) out(x / 10);
	pc(x % 10 + '0');
}
const int Maxn = 310;
const ll mod = 1e9;
char s[Maxn];
ll f[Maxn][Maxn];
ll dfs(int l, int r)
{
	if(l > r) return 0;
	if(l == r) return 1;
	if(s[l] != s[r]) return 0;
	if(f[l][r] != -1) return f[l][r];
	f[l][r] = 0;
	for(int k = l + 2; k <= r; ++k)
		f[l][r] = (f[l][r] + ((dfs(l + 1, k - 1) * dfs(k, r)) % mod)) % mod;
	return f[l][r];
}
int main()
{
	memset(f, -1, sizeof(f));
	scanf("%s", s + 1);
	int lens = strlen(s + 1);
	out(dfs(1, lens)), pc('\n');
	return 0;
}
