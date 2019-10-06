//Coded by Dy.
#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
using std :: max;
typedef long long ll;
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
inline void out(ll x) {
    if(x < 0)
        pc('-'), x = -x;
    if(x >= 10)
        out(x / 10);
    pc(x % 10 + '0');
}
#define re register
int t, n, m;
ll p[10010], f[10010];
int w[10010];
ll W, maxx;
int main() {
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	t = sc();
	while(t--) {
		memset(f, 0x3f, sizeof(f));
		n = sc(), m = sc();
		for(re int i = 1; i <= n; ++i) {
			scanf("%lld", &p[i]);
			w[i] = sc();
		}
		maxx = 1LL << 62, W = 0;
		f[0] = 0;
		for(re int i = 1; i <= n; ++i) {
			for(re int j = w[i]; j <= m; ++j)
				f[j] = std :: min(f[j], f[j - w[i]] + p[i]);
			for(re int j = max(0, m - w[i]); j <= m; ++j)
				if(maxx == f[j] + p[i])
					W = max(W, (ll)j + w[i]);
				else if(maxx > f[j] + p[i])
					maxx = f[j] + p[i], W = (ll)j + w[i];
		}
		out(maxx), pc(' '), out(W), pc('\n');
	}
    return 0;
}
