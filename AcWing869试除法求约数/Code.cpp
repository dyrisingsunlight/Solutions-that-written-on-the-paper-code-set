//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using std :: priority_queue;
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
struct NUM
{
	int num;
	bool operator < (const NUM &x) const
	{
		return num > x.num;
	}
};
priority_queue <NUM> q;
int n;
int main()
{
	n = sc();
	while(n--)
	{
		int x = sc();
		for(int i = 1; i * i <= x; ++i)
		{
			if(x % i == 0)
			{
				q.push((NUM){i});
				if(i != x / i) q.push((NUM){x / i});
			}
		}
		while(!q.empty())
		{
			NUM now = q.top(); q.pop();
			out(now.num), pc(' ');
		}
		pc('\n');
	}
	return 0;
}
