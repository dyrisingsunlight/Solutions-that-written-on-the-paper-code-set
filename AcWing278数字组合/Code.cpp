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
int n, m;
int a[110], f[10010];
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i <= n; ++i)
		a[i] = sc();
	f[0] = 1;
	for(re int i = 1; i <= n; ++i)
		for(re int j = m; j >= a[i]; --j)
			f[j] += f[j - a[i]];
	out(f[m]), pc('\n');
	return 0;
}
