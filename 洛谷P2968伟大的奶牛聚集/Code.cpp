//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
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
void out(ll x)
{
	if(x < 0) pc('-'), x = -x;
	if(x >= 10) out(x / 10);
	pc(x % 10 + '0');
}
const int Maxn = 1e5 + 10;
struct NODE
{
	int nxt, to;
	ll dis;
}t[Maxn << 1];
int n, cnt, tot;
ll ans;
int c[Maxn], head[Maxn], siz[Maxn];
ll f[Maxn], g[Maxn];
void ADD(int from, int to, ll dis)
{
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	t[cnt].dis = dis;
	head[from] = cnt;
}
void dfs(int now, int fa)
{
	siz[now] = c[now];
	for(int i = head[now]; i; i = t[i].nxt)
	{
		int to = t[i].to;
		if(to == fa) continue;
		dfs(to, now);
		siz[now] += siz[to];
		g[now] += g[to] + (ll)siz[to] * t[i].dis;
	}
}
void dp(int now, int fa)
{
	ans = std :: min(ans, f[now]);
	for(int i = head[now]; i; i = t[i].nxt)
	{
		int to = t[i].to;
		if(to == fa) continue;
		f[to] = f[now] - (ll)siz[to] * t[i].dis + (ll)(tot - siz[to]) * t[i].dis;
		dp(to, now);
	}
}
int main()
{
	n = sc();
	for(int i = 1; i <= n; ++i) c[i] = sc(), tot += c[i];
	for(int i = 1; i < n; ++i)
	{
		int x = sc(), y = sc();
		ll z; scanf("%lld", &z);
		ADD(x, y, z), ADD(y, x, z);
	}
	dfs(1, 0);
	f[1] = g[1];
	ans = f[1];
	dp(1, 0);
	out(ans), pc('\n');
	return 0;
}
