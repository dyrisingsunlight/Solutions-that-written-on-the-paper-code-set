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
int n, m, ans;
int fa[100010];
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i <= n; ++i)
		fa[i] = i;
	for(re int i = 1; i <= m; ++i) {
		int x = sc(), y = sc();
		int aa = find(x), bb = find(y);
		if(aa != bb)
			fa[aa] = bb;
		else
			++ans;
	}
	out(ans), pc('\n');
    return 0;
}
