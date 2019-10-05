//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
inline int sc() {
    int xx = 0, ff = 1; char cch = gc;
    while(!isdigit(cch)) {
        if(cch == '-') ff = -1; cch = gc;
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
int n, m;
int g[5010], c[5010], sum[5010], ans[5010];
int f[110][5010], a[110][5010], b[110][5010];
inline bool cmp(int x, int y) {
	return g[x] > g[y];
}
inline void PRE(int x, int y) {
//	std :: cerr << x << " " << y << '\n';
	if(x == 0)
		return;
	PRE(a[x][y], b[x][y]);
	if(a[x][y] == x) {
		for(re int i = 1; i <= x; ++i)
			++ans[c[i]];
	}
	else {
		for(re int i = a[x][y] + 1; i <= x; ++i)
			ans[c[i]] = 1;
	}
}
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i <= n; ++i)
		g[i] = sc(), c[i] = i;
	std :: sort(c + 1, c + 1 + n, cmp);
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(re int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + g[c[i]];
		for(re int j = i; j <= m; ++j) {
			f[i][j] = f[i][j - i];
			a[i][j] = i;
			b[i][j] = j - i;
			for(re int k = 0; k <= i - 1; ++k) {
				if(f[i][j] > f[k][j - (i - k)] + k * (sum[i] - sum[k + 1 - 1])) {
					f[i][j] = f[k][j - (i - k)] + k * (sum[i] - sum[k + 1 - 1]);
					a[i][j] = k;
					b[i][j] = j - (i - k);
				}
			}
		}
	}
	out(f[n][m]), pc('\n');
	PRE(n, m);
	for(re int i = 1; i <= n; ++i)
		out(ans[i]), pc(' ');
	pc('\n');
    return 0;
}
