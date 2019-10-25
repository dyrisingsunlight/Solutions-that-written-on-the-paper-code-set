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
const int mod = 1e9 + 7;
const int Maxn = 10000000 + 10;
const int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int n;
int f[Maxn];
int main() {
	n = sc();
//	n *= 100;
	f[0] = 1;
	for(re int i = 0; i < 13; ++i) {
		for(re int j = a[i]; j <= n; ++j)
				f[j] = (f[j] + f[j - a[i]]) % mod;
	}
	out(f[n] % mod), pc('\n');
    return 0;
}
