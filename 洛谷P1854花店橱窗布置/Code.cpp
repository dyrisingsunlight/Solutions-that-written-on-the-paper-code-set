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
const int INF = 0x7fffffff - 1;
int n, m;
int a[110][110], f[110][110];
inline void recursive(int i, int j) {
	if(j == 0)
		return;
	for(re int k = 0; k <= i - j; ++k)
		if(f[j + k - 1][j - 1] + a[j][j + k] == f[i][j]) {
			recursive(j + k - 1, j - 1);
			out(j + k), pc(' ');
			break;
		}
}
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i <= n; ++i)
		for(re int j = 1; j <= m; ++j)
			a[i][j] = sc();
	for(re int i = 1; i <= n; ++i)
		f[i][i] = f[i - 1][i - 1] + a[i][i];
	for(re int i = 1; i <= m; ++i) {
		for(re int j = 1; j <= n; ++j) {
			f[i][j] = -INF;
			for(re int k = 0; k <= i - j; ++k)
				f[i][j] = std :: max(f[i][j], f[j + k - 1][j - 1] + a[j][j + k]);
		}
	}
	out(f[m][n]), pc('\n');
	recursive(m, n);
	pc('\n');
    return 0;
}
