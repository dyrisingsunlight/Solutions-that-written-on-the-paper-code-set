//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
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
int n, m;
ll ans;
int cnt[100010], a[110], c[110];
bool f[100010];
int main() {
	while(scanf("%d%d", &n, &m) && n && m) {
		memset(f, 0, sizeof(f));
		ans = 0;
		for(re int i = 1; i <= n; ++i)
			a[i] = sc();
		for(re int i = 1; i <= n; ++i)
			c[i] = sc();
		f[0] = 1;
		for(re int i = 1; i <= n; ++i) {
			memset(cnt, 0, sizeof(cnt));
			for(re int j = a[i]; j <= m; ++j) {
				if(!f[j] && f[j - a[i]] && cnt[j - a[i]] + 1 <= c[i]) {
					f[j] = 1;
					cnt[j] = cnt[j - a[i]] + 1;
				}
			}
		}
		for(re int i = 1; i <= m; ++i)
			if(f[i])
				++ans;
		out(ans), pc('\n');
	}
    return 0;
}
