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
const int mod = 1e9 + 7;
int n, m;
int f[2][1010], cnt[2][1010];
int main() {
	n = sc(), m = sc();
	for(re int i = 0; i <= m; ++i)
		cnt[1][i] = cnt[0][i] = 1;
	for(re int i = 1; i <= n; ++i) {
		int w = sc(), v = sc();
		for(re int j = w; j <= m; ++j) {
			f[i & 1][j] = f[i - 1 & 1][j];
			cnt[i & 1][j] = cnt[i - 1 & 1][j];
			if(f[i & 1][j] < f[i - 1 & 1][j - w] + v) {
				f[i & 1][j] = f[i - 1 & 1][j - w] + v;
				cnt[i & 1][j] = cnt[i - 1 & 1][j - w];
			}
			else if(f[i & 1][j] == f[i - 1 & 1][j - w] + v)
				cnt[i & 1][j] = (cnt[i & 1][j] + cnt[i - 1 & 1][j - w]) % mod;
		}
		for(re int j = w; j <= m; ++j)
			f[i - 1 & 1][j] = f[i & 1][j], cnt[i - 1 & 1][j] = cnt[i & 1][j];
	}
	out(cnt[n & 1][m]), pc('\n');
    return 0;
}
