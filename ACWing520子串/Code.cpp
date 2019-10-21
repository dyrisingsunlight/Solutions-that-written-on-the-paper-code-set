//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
const int mod = 1000000007;
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
const int Maxn = 1010;
int n, m, k, ans = -1;
char a[Maxn], b[Maxn];
int f[3][210][210], sum[3][210][210];
int main() {
	n = sc(), m = sc(), k = sc();
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	f[0][0][0] = 1;
	for(re int i = 1; i <= n; ++i) {
		f[i & 1][0][0] = 1;
		for(re int j = 1; j <= m; ++j) {
			for(re int l = 1; l <= k; ++l) {
				if(a[i] == b[j])
					sum[i & 1][j][l] = (sum[(i - 1) & 1][j - 1][l] + f[(i - 1) & 1][j - 1][l - 1]) % mod;
				else
					sum[i & 1][j][l] = 0;
				f[i & 1][j][l] = (f[(i - 1) & 1][j][l] + sum[i & 1][j][l]) % mod;
			}
		}
	}
	out(f[n & 1][m][k] % mod), pc('\n');
    return 0;
}
