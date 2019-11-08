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
const int INF = 9223372036854775807LL - 1LL;
const int zs[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
#undef int
ll n, ans, maxx;
ll Cnt[20];
void dfs(ll now, ll cnt, ll c)
{
	if(cnt == 11)
	{
		if(c > maxx || (c == maxx && now < ans))
		{
			ans = now;
			maxx = c;
		}
		return;
	}
	ll tem = now;
	for(int i = 0; i <= Cnt[cnt - 1]; ++i)
	{
		if(tem > n)
			return;
		Cnt[cnt] = i;
		dfs(tem, cnt + 1, c * (i + 1));
		Cnt[cnt] = 0;
		tem *= zs[cnt];
	}
}
int main()
{
	n = sc();
	Cnt[0] = INF;
	dfs(1, 1, 1);
	out(ans), pc('\n');
	return 0;
}
