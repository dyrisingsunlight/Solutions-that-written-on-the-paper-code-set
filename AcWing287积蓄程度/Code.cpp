//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: min;
using std :: max;
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
const int Maxn = 2e5 + 10;
struct TREE {
	int nxt, to, dis;
}t[Maxn << 1];
int T, n, cnt, ans;
int head[Maxn], in[Maxn], f[Maxn], g[Maxn];
void ADD(int from, int to, int dis) {
	++in[to];
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	t[cnt].dis = dis;
	head[from] = cnt;
}
void dfs1(int now, int fa) {
	g[now] = 0;
	for(int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		if(to != fa) {
			dfs1(to, now);
			if(in[to] == 1)
				g[now] += t[i].dis;
			else
				g[now] += min(t[i].dis, g[to]);
		}
	}
}
void dfs2(int now, int fa) {
	for(int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		if(to != fa) {
			if(in[now] == 1)
				f[to] = g[to] + t[i].dis;
			else
				f[to] = g[to] + min(f[now] - min(t[i].dis, g[to]), t[i].dis);
			dfs2(to, now);
		}
	}
}
int main() {
	T = sc();
	while(T--) {
		cnt = ans = 0;
		memset(head, 0, sizeof(head));
		memset(t, 0, sizeof(t));
		memset(f, 0, sizeof(f));
		memset(in, 0, sizeof(in));
		n = sc();
		for(int i = 1; i < n; ++i) {
			int x = sc(), y = sc(), z = sc();
			ADD(x, y, z);
			ADD(y, x, z);
		}
		memset(g, 0x3f, sizeof(g));
		dfs1(1, 0);
		f[1] = g[1];
		dfs2(1, 0);
		for(int i = 1; i <= n; ++i)
			ans = max(ans, f[i]);
		out(ans), pc('\n');
	}
	return 0;
}
