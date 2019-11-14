//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using std :: queue;
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
const int Maxn = 400000 + 10;
struct NODE
{
	int nxt, to, dis;
}t[Maxn << 1];
int n, m, cnt;
int a[Maxn], head[Maxn], dis[Maxn];
bool vis[Maxn];
queue <int> q;
void ADD(int from, int to, int dis)
{
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	t[cnt].dis = dis;
	head[from] = cnt;
}
int main()
{
	n = sc(), m = sc();
	for(int i = 1; i <= n; ++i) a[i] = sc();
	#define v a  
	for(int i = 1; i <= m; ++i)
	{
		int x = sc(), y = sc(), z = sc();
		if(z == 1) ADD(x, y, 0), ADD(x, y + n, -v[x]), ADD(x + n, y + n, 0), ADD(x + n, y + 2 * n, v[x]), ADD(x + 2 * n, y + 2 * n, 0);
		else
		{
			ADD(x, y, 0), ADD(x, y + n, -v[x]), ADD(x + n, y + n, 0), ADD(x + n, y + 2 * n, v[x]), ADD(x + 2 * n, y + 2 * n, 0);
			std :: swap(x, y);
			ADD(x, y, 0), ADD(x, y + n, -v[x]), ADD(x + n, y + n, 0), ADD(x + n, y + 2 * n, v[x]), ADD(x + 2 * n, y + 2 * n, 0);
		}
	}
	#undef v
	int x = n, y = 1 + 3 * n;
	ADD(x, y, 0), ADD(x * 3, y, 0);
	n = n * 3 + 1;
	memset(dis, 0xcf, sizeof(dis));
	q.push(1); vis[1] = 1; dis[1] = 0;
	while(!q.empty())
	{
		int now = q.front(); q.pop();
		vis[now] = 0;
		for(int i = head[now]; i; i = t[i].nxt)
		{
			int to = t[i].to;
			if(dis[to] < dis[now] + t[i].dis)
			{
				dis[to] = dis[now] + t[i].dis;
				if(vis[to] == 0)
				{
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
	out(dis[n]), pc('\n');
	return 0;
}
