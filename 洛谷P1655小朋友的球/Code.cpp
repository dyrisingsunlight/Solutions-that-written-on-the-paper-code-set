//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using std :: cin;
using std :: cout;
using std :: max;
using std :: string;
#define gc getchar()
#define pc(x) putchar(x)

struct BI
{
	static const int w = 4, mod = 1e4;
	int s[1010], len;
	BI () {memset(s, 0, sizeof(s)); len = 0;}
	void sc()
	{
		string in;
		cin >> in;
		*this = in;
	}
	void out()
	{
		printf("%d", s[len]);
		for(int i = len - 1; i >= 1; --i) printf("%04d", s[i]);
	}
	BI operator = (int num)
	{
		memset(s, 0, sizeof(s)), len = 0;
		do
		{
			s[++len] = num % mod;
			num /= mod;
		}while(num);
		return *this;
	}
	BI operator = (const string &str) {
		memset(s, 0, sizeof(s)); len = 0;
		int x, l = (str.size() - 1) / w + 1;
		for (register int i = 0; i < l; ++i) {
			int r = str.size() - i * w;
				int l = std::max(0, r - w);
				sscanf(str.substr(l, r - l).c_str(), "%d", &x);
				s[++len] = x;
			}
			return *this;
		}
	BI operator + (const BI &b) const
	{
		BI c;
		c.len = max(len, b.len);
		for(int i = 1; i <= c.len; ++i)
		{
			c.s[i] += s[i] + b.s[i];
			c.s[i + 1] += c.s[i] / mod;
			c.s[i] %= mod;
		}
		while(c.s[c.len + 1]) ++c.len;
		return c;
	}
	BI operator *(const BI &b) const {
		BI c;
		c.len = len + b.len;
		for (register int i = 1; i <= len; ++i) 
			for (register int j = 1; j <= b.len; ++j) {
				c.s[i + j - 1] += s[i] * b.s[j];
				c.s[i + j] += c.s[i + j - 1] / mod;
				c.s[i + j - 1] %= mod;
			}
		while (c.len > 1 && c.s[c.len] == 0) c.len--;
		return c;
	}
};
BI f[150][150];
int n, m;
int main()
{
	for(int i = 1; i <= 110; ++i) f[i][1] = 1;
	for(int i = 2; i <= 110; ++i)
		for(int j = 1; j <= i; ++j)
		{
			BI now;
			now = j;
			now = now * f[i - 1][j];
			f[i][j] = f[i - 1][j - 1] + now;
		}
	while(scanf("%d%d", &n, &m) != EOF)
	{
		f[n][m].out();
		putchar('\n');
	}
	return 0;
}
