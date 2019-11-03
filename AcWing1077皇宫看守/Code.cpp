//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
#define re register
const int Maxn = 1500 + 10;
const int INF = 0x3f3f3f3f;
struct TREE {
	int nxt, to;
}t[Maxn << 1];
int n, cnt, rt;
int val[Maxn], in[Maxn], head[Maxn];
int f[Maxn][3];
inline void ADD(int from, int to) {
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	head[from] = cnt;
}
inline void dfs(int now, int fa) {
	f[now][1] = val[now];
	int tem = INF;
	for(re int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		if(to != fa) {
			dfs(to, now);
			f[now][0] += min(f[to][1], f[to][2]);
			f[now][1] += min(f[to][0], min(f[to][1], f[to][2]));
			f[now][2] += min(f[to][1], f[to][2]);
			tem = min(tem, f[to][1] - min(f[to][1], f[to][2]));
		}
	}
	if(tem != INF)
		f[now][2] += tem;
	if(f[now][2] == 0)
		f[now][2] = INF;
}
int main() {
	n = sc();
	for(re int i = 1; i <= n; ++i) {
		int x = sc();
		val[x] = sc();
		int y = sc();
		while(y--) {
			int z = sc();
			ADD(x, z);
			ADD(z, x);
			++in[z];
		}
	}
	for(re int i = 1; i <= n; ++i)
		if(!in[i]) {
			dfs(i, 0);
			rt = i;
			break;
		}
	printf("%d\n", min(f[rt][1], f[rt][2]));
	return 0;
}
