//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
using std :: max;
using std :: min;
typedef long long ll;
inline ll sc() {
    ll xx = 0, ff = 1; char cch = gc;
    while(!isdigit(cch)) {
        if(cch == '-') ff = -1; cch = gc;
    }
    while(isdigit(cch)) {
        xx = (xx << 1) + (xx << 3) + (cch ^ '0'); cch = gc;
    }
    return xx * ff;
}
inline void out(ll x) {
    if(x < 0)
        pc('-'), x = -x;
    if(x >= 10)
        out(x / 10);
    pc(x % 10 + '0');
}
#define re register
struct TREE {
	int nxt, to, dis;
}t[4010];
ll n, m, cnt;
int head[2010];
ll siz[2010];
ll f[2010][2010];
inline void ADD(int from, int to, int dis) {
	t[++cnt].nxt = head[from];
	t[cnt].to = to;
	t[cnt].dis = dis;
	head[from] = cnt;
}
inline void dfs(int now, int fa) {
	siz[now] = 1, f[now][0] = f[now][1] = 0;
	for(re int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		if(to == fa)
			continue;
		dfs(to, now);
		siz[now] += siz[to];
	}
	for(re int i = head[now]; i; i = t[i].nxt) {
		int to = t[i].to;
		if(to == fa)
			continue;
		for(re ll j = min(m, siz[now]); j >= 0; --j) {
			for(re ll k = 0; k <= min(j, siz[to]); ++k)
				if(f[now][j - k] != -1)
					f[now][j] = max(f[now][j], f[now][j - k] + f[to][k] + k * (m - k) * t[i].dis + (siz[to] - k) * (n - m - (siz[to] - k)) * t[i].dis); 
		}
	}
}
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i < n; ++i) {
		int x = sc(), y = sc(), z = sc();
		ADD(x, y, z);
		ADD(y, x, z);
	}
	memset(f, -1, sizeof(f));
	dfs(1, 0);
	out(f[1][m]), pc('\n');
    return 0;
}
