//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: cin;
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
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, m, stx, sty, fr, ans = 0x7fffffff;
int dis[40][40][5], Map[40][40];
void dfs(int nowx, int nowy, int nowf, int val)
{
	if(dis[nowx][nowy][nowf] <= val || val >= ans) return;
//	std :: cout << val << '\n';
	dis[nowx][nowy][nowf] = val;
	if(Map[nowx][nowy] == 2) ans = std :: min(ans, dis[nowx][nowy][nowf]);
	bool pd = 0;
	int xx = nowx + d[nowf][0], yy = nowy + d[nowf][1];
	int lf = (nowf + 1) % 4, lx = nowx + d[lf][0], ly = nowy + d[lf][1];
	int rf = (nowf + 3) % 4, rx = nowx + d[rf][0], ry = nowy + d[rf][1];
	int bf = (nowf + 2) % 4, bx = nowx + d[bf][0], by = nowy + d[bf][1];
	if(Map[xx][yy]) pd = 1, dfs(xx, yy, nowf, val);
	if(Map[lx][ly]) pd = 1, dfs(lx, ly, lf, val + 1);
	if(Map[rx][ry]) pd = 1, dfs(rx, ry, rf, val + 5);
	if(Map[bx][by] && pd == 0) dfs(bx, by, bf, val + 10);
}
int main()
{
	n = sc(), m = sc();
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			Map[i][j] = 1;
			char c[2];
			cin >> c[0];
			if(c[0] == '.') Map[i][j] = 0;
			else if(c[0] == 'F') Map[i][j] = 2;
			else if(c[0] == 'N') stx = i, sty = j, fr = 0;
			else if(c[0] == 'W') stx = i, sty = j, fr = 1;
			else if(c[0] == 'S') stx = i, sty = j, fr = 2;
			else if(c[0] == 'E') stx = i, sty = j, fr = 3;
		}
	memset(dis, 0x3f, sizeof(dis));
	dfs(stx, sty, fr, 0);
	out(ans), pc('\n');
	return 0;
}
