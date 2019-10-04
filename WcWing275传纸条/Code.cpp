//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
using std :: max;
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
int v[60][60];
int f[3][60][60];
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i <= n; ++i)
		for(re int j = 1; j <= m; ++j)
			v[i][j] = sc();
	for(re int k = 2; k <= n + m; ++k) {
		for(re int i = max(1, k - m); i <= n && i < k; ++i) {
			for(re int j = max(1, k - m); j <= n && j < k; ++j) {
				for(re int x = 0; x <= 1; ++x)
					for(re int y = 0; y <= 1; ++y) {
						int now = v[i][k - i];
						if(i != j)
							now += v[j][k - j];
						f[k & 1][i][j] = max(f[k & 1][i][j], f[k - 1 & 1][i - x][j - y] + now);
					}
			}
		}
	}
	out(f[n + m & 1][n][n]), pc('\n');
    return 0;
}
