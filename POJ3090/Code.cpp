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
const int Maxn = 1000000 + 10;
ll n, T, ans;
int tot;
ll v[Maxn], pri[Maxn], p[Maxn];
int main()
{
	T = sc();
	int cnt = 0;
	while(T--)
	{
		ans = 0;
		n = sc();
		p[1] = 1;
		for(ll i = 2; i <= n; ++i)
		{
			if(v[i] == 0) {v[i] = i, p[i] = i - 1, pri[++tot] = i;}
			for(int j = 1; j <= tot; ++j)
			{
				if(pri[j] > v[i] || i * pri[j] > n) break;
				v[pri[j] * i] = pri[j];
				if(i % pri[j] == 0) p[i * pri[j]] = p[i] * (p[pri[j]] + 1);
				else p[i * pri[j]] = p[i] * p[pri[j]];
			}
		}
		for(int i = 2; i <= n; ++i)
			ans += p[i];
		ans <<= 1; ans += 3;
		out(++cnt), pc(' '), out(n), pc(' '), out(ans), pc('\n');
	}
	return 0;
}
