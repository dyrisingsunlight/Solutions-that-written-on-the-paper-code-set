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
int t, n, ans;
bool vis[25000 + 10];
int a[110];
int main() {
	t = sc();
	while(t--) {
		memset(vis, 0, sizeof(vis));
		int maxx = -1;
		ans = 0;
		n = sc();
		for(re int i = 1; i <= n; ++i)
			a[i] = sc(), maxx = std :: max(maxx, a[i]);
		std :: sort(a + 1, a + 1 + n);
		vis[0] = 1;
		for(re int i = 1; i <= n; ++i) {
			if(vis[a[i]])
				continue;
			++ans;
			for(re int j = a[i]; j <= maxx; ++j)
				vis[j] |= vis[j - a[i]];
		}
		out(ans), pc('\n');
	}
    return 0;
}
