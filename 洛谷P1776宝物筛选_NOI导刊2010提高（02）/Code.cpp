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
const int Maxn = 100010;
int n, m, ans;
int f[Maxn], v[Maxn], w[Maxn], c[Maxn], q[Maxn];
inline int calc(int i, int u, int k) {
	return f[u + k * w[i]] - k * v[i];
}
int main() {
	n = sc(), m = sc();
	memset(f, 0xcf, sizeof(f));
	f[0] = 0;
	for(re int i = 1; i <= n; ++i) {
		v[i] = sc(), w[i] = sc(), c[i] = sc();
		for(re int u = 0; u < w[i]; ++u) {
			int l = 1, r = 0;
			int maxp = (m - u) / w[i];
			for(re int k = maxp - 1; k >= max(0, maxp - c[i]); --k) {
				while(l <= r && calc(i, u, q[r]) <= calc(i, u, k))
					--r;
				q[++r] = k;
			}
			for(re int p = maxp; p >= 0; --p) {
				while(l <= r && q[l] > p - 1)
					++l;
				if(l <= r)
					f[u + p * w[i]] = max(f[u + p * w[i]], calc(i, u, q[l]) + p * v[i]);
				if(p - c[i] - 1 >= 0) {
					while(l <= r && calc(i, u, q[r]) <= calc(i, u, p - c[i] - 1))
						--r;
					q[++r] = p - c[i] - 1;
				}
			}
		}
	}
	for(re int i = 1; i <= m; ++i)
		ans = max(ans, f[i]);
	out(ans), pc('\n');
    return 0;
}
