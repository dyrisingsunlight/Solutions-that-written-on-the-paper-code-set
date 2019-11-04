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
const int Maxn = 30 + 10;
int n;
int f[Maxn][Maxn], rt[Maxn][Maxn];
int dfs(int l, int r) {
	if(f[l][r] > 0)
		return f[l][r];
	if(l > r)
		return 1;
	for(int i = l; i <= r; ++i) {
		int tem = dfs(l, i - 1) * dfs(i + 1, r) + f[i][i];
		if(tem > f[l][r]) {
			f[l][r] = tem;
			rt[l][r] = i;
		}
	}
	return f[l][r];
}
void DFS(int l, int r) {
	if(l > r)
		return;
	if(l == r) {
		out(l), pc(' ');
		return;
	}
	out(rt[l][r]), pc(' ');
	DFS(l, rt[l][r] - 1);
	DFS(rt[l][r] + 1, r);
}
int main() {
	n = sc();
	for(int i = 1; i <= n; ++i)
		f[i][i] = sc();
	out(dfs(1, n)), pc('\n');
	DFS(1, n), pc('\n');
	return 0;
}
