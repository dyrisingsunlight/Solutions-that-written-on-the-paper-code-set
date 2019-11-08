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
ll n, k, ans;
int main()
{
	n = sc(), k = sc();
	ans = n * k;
	for(ll l = 1, r; l <= n; l = r + 1)
	{
		if(k / l == 0) r = n;
		else r = std :: min(n, k / (k / l));
		ans -= (k / l) * (ll)((((l + r) * (r - l + 1))) >> 1);
	}
	out(ans), pc('\n');
	return 0;
}
