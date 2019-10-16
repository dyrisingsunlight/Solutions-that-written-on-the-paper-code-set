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
int n, m;
int f[32010], w[100], v[100], p[100], in[100];
int de[100][10];
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i <= m; ++i) {
		w[i] = sc(), v[i] = sc(), p[i] = sc();
		if(p[i])
			de[p[i]][++in[p[i]]] = i;
	}
	for(re int i = 1; i <= m; ++i) {
		if(p[i])
			continue;
		for(re int j = n; j >= 0; --j) {
			if(w[i] > j)
				break;
			#define x de[i][1]
			#define y de[i][2]
			if(w[i] <= j)
				f[j] = max(f[j], f[j - w[i]] + v[i] * w[i]);
			if(w[x] + w[i] <= j)
				f[j] = max(f[j], f[j - w[x] - w[i]] + v[x] * w[x] + v[i] * w[i]);
			if(w[y] + w[i] <= j)
				f[j] = max(f[j], f[j - w[y] - w[i]] + v[y] * w[y] + v[i] * w[i]);
			if(w[x] + w[y] + w[i] <= j)
				f[j] = max(f[j], f[j - w[x] - w[y] - w[i]] + v[x] * w[x] + v[y] * w[y] + v[i] * w[i]);
			#undef x
			#undef y
		}
	}
	out(f[n]), pc('\n');
    return 0;
}
