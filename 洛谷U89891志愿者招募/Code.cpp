//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
using std :: lower_bound;
using std :: vector;
using std :: pair;
using std :: make_pair;
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
#define mp make_pair
struct MAN {
	int l, r, d;
}a[4600000];
int n, m, len, lens, top = 1;
int temp[13000000], s[13000000];
ll f[13000000];
vector <pair <int, ll> > in[4600000];
int main() {
	n = sc(), m = sc();
	for(re int i = 1; i <= m; ++i) {
		a[i].l = sc(), a[i].r = sc(), a[i].d = sc();
		temp[++len] = a[i].l, temp[++len] = a[i].r;
		if(a[i].l != 1)
			temp[++len] = a[i].l - 1;
		if(a[i].r != n)
			temp[++len] = a[i].r + 1;
		if(a[i].l != n)
			temp[++len] = a[i].l + 1;
		if(a[i].r != 1)
			temp[++len] = a[i].r - 1;
	}
//	printf("%d\n", len);
	std :: sort(temp + 1, temp + 1 + len);
	lens = std :: unique(temp + 1, temp + 1 + len) - temp - 1;
//	lens = len;
//	printf("%d\n", lens);
	for(re int i = 1; i <= m; ++i) {
		a[i].l = lower_bound(temp + 1, temp + 1 + lens, a[i].l) - temp;
		a[i].r = lower_bound(temp + 1, temp + 1 + lens, a[i].r) - temp;
		in[a[i].r].push_back(mp(a[i].l, a[i].d));
	}
	memset(f, 0x3f, sizeof(f));
//	for(re int i = 1; i <= lens; ++i)
//		f[i] = 0x7fffffff;
	f[0] = 0;
	for(re int i = 1; i <= lens; ++i) {
		for(re int j = 0; j < in[i].size(); ++j) {
			int now = in[i][j].first;
			ll dis = in[i][j].second;
			int pos = lower_bound(s + 1, s + 1 + top, now - 1) - s;
			f[i] = std :: min(f[i], dis + f[s[pos]]);
//			out(f[i]), pc('\n');
		}
		while(f[i] < f[s[top]])
			--top;
		s[++top] = i;
	}
	out(f[lens]), pc('\n');
    return 0;
}
