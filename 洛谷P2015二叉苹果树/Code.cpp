//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: max;
using std :: min;
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
const int Maxn = 100 + 10;
struct TREE {
	int nxt, to, dis;
}t[Maxn << 1];
int n, m, cnt;
int head[Maxn], siz[Maxn];
int f[Maxn][Maxn];
void ADD(int from, int to, int dis) {
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	t[cnt].dis = dis;
	head[from] = cnt;
}
void dfs(int now, int fa) {
	for(int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		if(to != fa) {
			dfs(to, now);
			siz[now] += siz[to] + 1;
			for(int j = min(siz[now], m); j >= 0; --j)
				for(int k = min(siz[to], j - 1); k >= 0; --k)
					if(j - k >= 0)
						f[now][j] = max(f[now][j], f[now][j - k - 1] + f[to][k] + t[i].dis);
		}
	}
}
int main() {
	n = sc(), m = sc();
	for(int i = 1; i < n; ++i) {
		int x = sc(), y = sc(), z = sc();
		ADD(x, y, z);
		ADD(y, x, z);
	}
	dfs(1, 0);
	out(f[1][m]), pc('\n');
	return 0;
}
