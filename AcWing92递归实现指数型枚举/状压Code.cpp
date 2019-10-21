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
int main() {
	int n = sc();
	int lim = (1 << n) - 1;
	pc('\n');
	for(re int i = 1; i <= lim; ++i) {
		for(re int j = 0; j < n; ++j)
			if((i >> j) & 1)
				out(j + 1), pc(' ');
		pc('\n');
	}
    return 0;
}
