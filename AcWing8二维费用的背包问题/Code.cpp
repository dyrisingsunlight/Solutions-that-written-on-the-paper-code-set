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
int n, m, p;
int f[2][110][110];
int main() {
	n = sc(), m = sc(), p = sc();
	for(re int i = 1; i <= n; ++i) {
		int w = sc(), c = sc(), v = sc();
		for(re int j = w; j <= m; ++j)
			for(re int k = c; k <= p; ++k) {
				f[i & 1][j][k] = std :: max(f[i - 1 & 1][j][k], f[i - 1 & 1][j - w][k - c] + v);
			}
		for(re int j = w; j <= m; ++j)
			for(re int k = c; k <= p; ++k) {
				f[i - 1 & 1][j][k] = f[i & 1][j][k];
			}
	}
	out(f[n & 1][m][p]), pc('\n');
    return 0;
}
