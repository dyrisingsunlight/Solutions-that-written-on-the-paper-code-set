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
		if(cch == '-')
			ff = -1; cch = gc;
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
const int Maxn = 20010;
int n, m;
int f[Maxn], g[Maxn], q[Maxn];
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i <= n; ++i) {
		int w = sc(), v = sc(), c = sc();
		memcpy(g, f, sizeof(f));
		for(re int u = 0; u < w; ++u) {
			int l = 0, r = -1;
			for(re int j = u; j <= m; j += w) {
				while(l <= r && (j - q[l]) / w > c)
					++l;
				if(l <= r)
					f[j] = std :: max(f[j], g[q[l]] + (j - q[l]) / w * v);
				while(l <= r && g[q[r]] - (q[r] - u) / w * v <= g[j] - (j - u) / w * v)
					--r;
				q[++r] = j;
			}
		}
	}
	out(f[m]), pc('\n');
	return 0;
}
