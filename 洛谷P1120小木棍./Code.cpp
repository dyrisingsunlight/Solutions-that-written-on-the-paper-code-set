//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
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
const int Maxn = 65 + 10;
int n, tot, maxx, cnt, ans, lens, all;
int a[Maxn];
bool vis[Maxn];
bool cmp(int x, int y)
{
	return x > y;
}
#define goal lens
#define len cab
bool dfs(int num, int len, int lst)
{
	if(num > cnt) return 1;
	if(len == goal) return dfs(num + 1, 0, 1);
	int fail = 0;
	for(int i = lst; i <= n; ++i)
		if(!vis[i] && len + a[i] <= goal && fail != a[i])
		{
			vis[i] = 1;
			if(dfs(num, len + a[i], i + 1)) return 1;
			fail = a[i];
			vis[i] = 0;
			if(len == 0 || len + a[i] == goal) return 0;
		}
	return 0;
}
#undef len
int main()
{
	n = sc();
	for(int i = 1; i <= n; ++i)
	{
		int x = sc();
		if(x > 50) continue;
		a[++all] = x;
		tot += a[all];
		maxx = std :: max(maxx, a[all]);
	}
	std :: sort(a + 1, a + 1 + all, cmp);
	#define i lens
	for(i = maxx; i <= tot; ++i)
	{
		if(tot % i) continue;
		cnt = tot / i;
		memset(vis, 0, sizeof(vis));
		if(dfs(1, 0, 1)) break;
	}
	out(i), pc('\n');
	#undef i
	return 0;
}
