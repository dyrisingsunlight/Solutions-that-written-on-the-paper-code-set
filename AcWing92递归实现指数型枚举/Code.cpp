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
int n, len;
int vis[20], in[20];
inline void dfs(int now) {
	len = 0;
	for(re int i = now; i >= 1; --i)
		if(vis[i])
			in[++len] = i;
	if(len != 1) {
		for(re int i = len; i >= 1; --i)
			out(in[i]), pc(' ');
		pc('\n');
	}
	for(re int i = now + 1; i <= n; ++i) {
		vis[i] = 1;
		dfs(i);
		vis[i] = 0;
	}
}
int main() {
	n = sc();
	pc('\n');
	for(re int i = 1; i <= n; ++i) {
		out(i), pc('\n');
		vis[i] = 1;
		dfs(i);
		vis[i] = 0;
	}
    return 0;
}
