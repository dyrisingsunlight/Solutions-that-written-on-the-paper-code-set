//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
const int Maxn = 3000 + 10;
struct TREE {
	int nxt, to, dis;
}t[Maxn << 1];
int n, m, cnt;
int head[Maxn], val[Maxn];
int f[Maxn][Maxn]; 
void ADD(int from, int to, int dis) {
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	t[cnt].dis = dis;
	head[from] = cnt;
}
int dfs(int now) {
	if(now > n - m) {
		f[now][1] = val[now];
		return 1;
	}
	int tot = 0;
	for(int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		int siz = dfs(to);
		tot += siz;
//		out(tot), pc('\n');
		for(int j = tot; j > 0; --j)
			for(int k = j; k > 0; --k)
				if(j - k >= 0)
					f[now][j] = max(f[now][j], f[now][j - k] + f[to][k] - t[i].dis);
	}
	return tot;
}
int main() {
	n = sc(), m = sc();
	for(int i = 1;  i <= n - m; ++i) {
		int x = sc();
		while(x--) {
			int y = sc(), z = sc();
			ADD(i, y, z);
		}
	}
	for(int i = n - m + 1; i <= n; ++i)
		val[i] = sc();
	memset(f, 0xcf, sizeof(f));
	for(int i = 1; i <= n; ++i)
		f[i][0] = 0;
	dfs(1);
	for(int i = m; i >= 0; --i)
		if(f[1][i] >= 0) {
			out(i), pc('\n');
			return 0;			
		}
	return 0;
}
