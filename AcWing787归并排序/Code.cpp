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
const int Maxn = 1e5 + 10;
int n;
int a[Maxn], tem[Maxn];
inline void msort(int l, int r) {
	if(l == r)
		return;
	int mid = l + r >> 1;
	msort(l, mid);
	msort(mid + 1, r);
	int i = l, k = l, j = mid + 1;
	while(i <= mid && j <= r) {
		if(a[i] <= a[j])
			tem[k++] = a[i++];
		else
			tem[k++] = a[j++];
	}
	while(i <= mid)
		tem[k++] = a[i++];
	while(j <= r)
		tem[k++] = a[j++];
	for(re int now = l; now <= r; ++now)
		a[now] = tem[now];
}
int main() {
	n = sc();
	for(re int i = 1; i <= n; ++i)
		a[i] = sc();
	msort(1, n);
	for(re int i = 1; i <= n; ++i)
		out(a[i]), pc(' ');
	pc('\n');
    return 0;
}
