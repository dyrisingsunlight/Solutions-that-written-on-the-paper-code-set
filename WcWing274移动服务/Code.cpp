//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
using std :: min;
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
int n, m, ans = 2147483647;
int f[3][210][210];
int v[210][210];
int p[1010];
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i <= n; ++i)
		for(re int j = 1; j <= n; ++j)
			v[i][j] = sc();
	for(re int i = 1; i <= m; ++i)
		p[i] = sc();
	p[0] = 3;
	memset(f, 0x3f, sizeof(f));
	f[0 & 1][1][2] = 0;
	for(re int i = 0; i < m; ++i) {
		for(re int x = 1; x <= n; ++x) {
			for(re int y = 1; y <= n; ++y) {
				int z = p[i];
//				if(x == y || x == z || y == z || f[i & 1][x][y] == 0x3f3f3f3f)
//					continue;
				if(f[i & 1][x][y] == 0x3f3f3f3f)
					continue;
				if(x != p[i + 1] && y != p[i +  1])
					f[(i + 1) & 1][x][y] = min(f[(i + 1) & 1][x][y], f[i & 1][x][y] + v[z][p[i + 1]]);
				if(y != p[i + 1] && z != p[i +  1])
					f[(i + 1) & 1][z][y] = min(f[(i + 1) & 1][z][y], f[i & 1][x][y] + v[x][p[i + 1]]);
				if(x != p[i + 1] && z != p[i +  1])
					f[(i + 1) & 1][x][z] = min(f[(i + 1) & 1][x][z], f[i & 1][x][y] + v[y][p[i + 1]]);
				f[i & 1][x][y] = 0x3f3f3f3f;
			}
		}
	}
	for(re int i = 1; i <= n; ++i) {
		for(re int j = 1; j <= n; ++j) {
//			if(i == j || i == p[m] || j == p[m])
//				continue;
			ans = min(ans, f[m & 1][i][j]);
		}
	}
	out(ans), pc('\n');
    return 0;
}
