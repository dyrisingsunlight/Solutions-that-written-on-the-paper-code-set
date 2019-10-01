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
const int INF = 0x7fffffff;
int n, ans = INF, res = INF;
int a[2010], b[2010];
int f[2010][2010];
int main() {
	n = sc();
	for(re int i = 1; i <= n; ++i) {
		a[i] = sc();
		b[i] = a[i];
	}
	std :: sort(b + 1, b + 1 + n);
	for(re int i = 1; i <= n; ++i) {
		int lst = INF;
		for(re int j = 1; j <= n; ++j) {
			lst = std :: min(lst, f[i - 1][j]);
			f[i][j] = lst + (int)abs(a[i] - b[j]);
		}
	}
	for(re int i = 1; i <= n; ++i)
		ans = std :: min(ans, f[n][i]);
	std :: reverse(a + 1, a + 1 + n);
	for(re int i = 1; i <= n; ++i) {
		int lst = INF;
		for(re int j = 1; j <= n; ++j) {
			lst = std :: min(lst, f[i - 1][j]);
			f[i][j] = lst + (int)abs(a[i] - b[j]);
		}
	}
	for(re int i = 1; i <= n; ++i)
		ans = std :: min(ans, f[n][i]);
	out(ans), pc('\n');
	return 0;
}
