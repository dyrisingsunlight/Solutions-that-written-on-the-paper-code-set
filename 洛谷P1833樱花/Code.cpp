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
const int Maxn = 10000 + 10;
char t1[10], t2[10];
int T1, T2, n, m, ans;
int c[Maxn], v[Maxn], w[Maxn], f[1000 * Maxn], q[Maxn * 1000];
inline int calc(int i, int u, int k) {
	return f[u + k * v[i]] - k * w[i];
}
int main() {
	scanf("%s%s", t1 + 1, t2 + 1);
	for(re int i = 1; i <= strlen(t1 + 1);) {
		int temp = 0;
		while(t1[i] != ':') {
			temp = (temp << 1) + (temp << 3) + (t1[i] ^ '0');
			++i;
		}
		++i;
		T1 = temp * 60;
		temp = 0;
		while(i <= strlen(t1 + 1)) {
			temp = (temp << 1) + (temp << 3) + (t1[i] ^ '0');
			++i;
		}
		T1 += temp;
	}
	for(re int i = 1; i <= strlen(t2 + 1);) {
		int temp = 0;
		while(t2[i] != ':') {
			temp = (temp << 1) + (temp << 3) + (t2[i] ^ '0');
			++i;
		}
		++i;
		T2 = temp * 60;
		temp = 0;
		while(i <= strlen(t2 + 1)) {
			temp = (temp << 1) + (temp << 3) + (t2[i] ^ '0');
			++i;
		}
		T2 += temp;
	}
	n = sc();
	m = T2 - T1;
//	out(m), pc('\n');
	memset(f, 0xcf, sizeof(f));
	f[0] = 0;
	for(re int i = 1; i <= n; ++i) {
		v[i] = sc(), w[i] = sc(), c[i] = sc();
		if(c[i] == 0)
			c[i] = 9999999;
		for(re int u = 0; u < v[i]; ++u) {
			int l = 1, r = 0;
			int maxp = (m - u) / v[i];
			for(re int k = maxp - 1; k >= max(maxp - c[i], 0); --k) {
				while(l <= r && calc(i, u, q[r]) <= calc(i, u, k))
					--r;
				q[++r] = k;
			}
			for(re int p = maxp; p >= 0; --p) {
				while(l <= r && q[l] > p - 1)
					++l;
				if(l <= r)
					f[u + p * v[i]] = max(f[u + p * v[i]], calc(i, u, q[l]) + p * w[i]);
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
