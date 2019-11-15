#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<queue>
#include<cmath>
using std :: cin;
using std :: queue;
using std :: pair;
using std :: make_pair;
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
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int T, n, m, num, t;
int gx[10], gy[10];
int Map[810][810], pd[810][810];
pair <int, int> boy, girl;
queue <pair <int, int> > g, b;
int Manh(int i, int j, int k, int l)
{
	return abs(i - k) + abs(j - l);
}
bool check(int x, int y)
{
	if(x < 0 || y < 0 || x > n || y > m || Map[x][y] == 0) return 1;
	for(int i = 1; i <= num; ++i)
		if(Manh(x, y, gx[i], gy[i]) <= 2 * t) return 1;
	return 0;
}
pair<int, int> Clear(queue <pair<int, int> > &x)
{
	queue <pair<int, int> > now;
	std :: swap(x, now);
}
int main()
{
	T = sc();
	while(T--)
	{
		memset(Map, 0, sizeof(Map));
		memset(pd, 0, sizeof(pd));
		Clear(g); Clear(b);
		girl = make_pair(0, 0);
		boy = make_pair(0, 0);
		num = t = 0;
		n = sc(), m = sc();
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
			{
				char c[2]; cin >> c[0];
				Map[i][j] = 1;
				if(c[0] == 'X') Map[i][j] = 0;
				else if(c[0] == 'Z') Map[i][j] = 0, gx[++num] = i, gy[num] = j;
				else if(c[0] == 'G') Map[i][j] = 1, girl = make_pair(i, j);
				else if(c[0] == 'M') Map[i][j] = 1, boy = make_pair(i, j);
			}
		g.push(girl); b.push(boy);
		pd[boy.first][boy.second] = 1;
		pd[girl.first][girl.second] = 2;
		t = 0;
		while(!g.empty() && !b.empty())
		{
			++t;
			for(int i = 1; i <= 3; ++i)
			{
				for(int j = 0, lst = b.size(); j < lst; ++j)
				{
					pair <int, int> now = b.front(); b.pop();
					int nowx = now.first, nowy = now.second;
					if(check(nowx, nowy) == 1) continue;
					for(int k = 0; k < 4; ++k)
					{
						int xx = nowx + dx[k], yy = nowy + dy[k];
						if(check(xx, yy) == 0)
						{
							if(pd[xx][yy] == 2)
							{
								out(t), pc('\n');
								goto goal;
							}
							if(pd[xx][yy] == 0)
							{
								pd[xx][yy] = 1;
								b.push(std :: make_pair(xx, yy));
							}
						}
					}
				}
			}
			for(int i = 0, lst = g.size(); i < lst; ++i)
			{
				pair <int, int> now = g.front(); g.pop();
				int nowx = now.first, nowy = now.second;
				if(check(nowx, nowy) == 1) continue;
				for(int j = 0; j < 4; ++j)
				{
					int xx = nowx + dx[j], yy = nowy + dy[j];
					if(check(xx, yy) == 0)
					{
						if(pd[xx][yy] == 1)
						{
							out(t), pc('\n');
							goto goal;
						}
						if(pd[xx][yy] == 0)
						{
							pd[xx][yy] = 2;
							g.push(make_pair(xx, yy));
						}
					}
				}
			}
		}
		out(-1), pc('\n');
		goal:;
	}
	return 0;
}
