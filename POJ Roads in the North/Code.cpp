//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
inline int sc() {
	int xx = 0, ff = 1; char cch = gc;
	while(!isdigit(cch) && cch != EOF) {
		if(cch == '-')
			ff = -1; cch = gc;
	}
	while(isdigit(cch)) {
		xx = (xx << 1) + (xx << 3) + (cch ^ '0'); cch = gc;
	}
	return xx * ff;
}
inline void out(int x) {
	if(x < 0)
		pc('-'), x = -x;
	if(x >= 10)
		out(x / 10);
	pc(x % 10 + '0');
}
const int Maxn = 50000 + 10;
const int INF = 0x3f3f3f3f;
struct TREE {
	int nxt, to, dis;
}t[Maxn << 1];
int ans, cnt;
int head[Maxn], f[Maxn], g[Maxn];
void ADD(int from, int to, int dis) {
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	t[cnt].dis = dis;
	head[from] = cnt;
}
void dfs(int now, int fa) {
	for(int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		if(to == fa)
			continue;
		dfs(to, now);
		if(f[now] < f[to] + t[i].dis) {
			g[now] = f[now];
			f[now] = f[to] + t[i].dis;
		}
		else if(g[now] < f[to] + t[i].dis)
			g[now] = f[to] + t[i].dis;
		ans = std :: max(ans, f[now] + g[now]);
	}
}
int main() {
	int x, y, z;
	while(scanf("%d%d%d", &x, &y, &z) != EOF) {
		ADD(x, y, z);
		ADD(y, x, z);
	}
	dfs(1, 0);
	out(ans), pc('\n');
	return 0;
}
