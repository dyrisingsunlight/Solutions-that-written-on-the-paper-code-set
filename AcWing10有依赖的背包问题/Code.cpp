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
const int Maxn = 100 + 10;
struct TREE {
	int nxt, to;
}t[Maxn << 1];
int n, m, rt, cnt;
int w[Maxn], v[Maxn], head[Maxn];
int f[Maxn][Maxn];
void ADD(int from, int to) {
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	head[from] = cnt;
}
void dfs(int now) {
	for(int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		dfs(to);
		for(int j = m - w[now]; j >= 0; --j)
			for(int k = j; k >= 0; --k)
				if(j - k >= 0)
					f[now][j] = std :: max(f[now][j], f[now][j - k] + f[to][k]);
	}
	for(int i = m; i >= w[now]; --i)
			f[now][i] = f[now][i - w[now]] + v[now];
	for(int i = 0; i < w[now]; ++i)
		f[now][i] = 0;
}
int main() {
	n = sc(), m = sc();
	for(int i = 1; i <= n; ++i) {
		int x = sc(), y = sc(), z = sc();
		w[i] = x, v[i] = y;
		if(z != -1)
			ADD(z, i);
		else
			rt = i;
	}
	dfs(rt);
	printf("%d\n", f[rt][m]);
	return 0;
}
