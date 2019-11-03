//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
const int Maxn = 100000 + 10;
struct TREE {
	int nxt, to;
}t[Maxn << 1];
int n, cnt, fir;
int val[Maxn], head[Maxn], in[Maxn];
int f[Maxn][2];
inline void ADD(int from, int to) {
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	head[from] = cnt;
}
inline void dp(int now, int fa) {
	f[now][0] = 0;
	f[now][1] = val[now];
	for(re int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		if(to == fa)
			continue;
		dp(to, now);
		f[now][0] += std :: max(f[to][0], f[to][1]);
		f[now][1] += f[to][0];
	}
}
int main() {
	scanf("%d", &n);
	for(re int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	for(re int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ADD(x, y);
		ADD(y, x);
		++in[y];
	}
	for(re int i = 1; i <= n; ++i)
		if(!in[i]) {
			dp(i, 0);
			fir = i;
			break;
		}
	printf("%d\n", std :: max(f[fir][0], f[fir][1]));
	return 0;
}
