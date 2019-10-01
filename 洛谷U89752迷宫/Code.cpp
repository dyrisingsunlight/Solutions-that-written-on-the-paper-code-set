//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
inline ll sc() {
    ll xx = 0, ff = 1; char cch = gc;
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
struct MAP {
	ll x, y;
};
ll n, m;
inline ll qw(ll base, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1)
			ans = ans * base;
		base = base * base;
		b >>= 1;
	}
	return ans;
}
inline MAP flist(ll nown, ll nowm) {
	if(nown == 1) {
		if(nowm == 0)	
			return (MAP){1, 1};
		if(nowm == 1)
			return (MAP){1, 2};
		if(nowm == 2)
			return (MAP){2, 2};
		if(nowm == 3)
			return (MAP){2, 1};
	}
	ll lim = qw(4, nown - 1);
//	std :: cerr << nowm << '\n';
	if(nowm / lim == 0) {
		MAP temp = flist(nown - 1, nowm % lim);
		std :: swap(temp.x, temp.y);
		return temp;
	}
	else if(nowm / lim == 1) {
		MAP temp = flist(nown - 1, nowm % lim);
		temp.y += (int)sqrt(lim);
		return temp;
	}
	else if(nowm / lim == 2) {
		MAP temp = flist(nown - 1, nowm % lim);
		temp.x += (int)sqrt(lim);
		temp.y += (int)sqrt(lim);
		return temp;
	}
	else {
		MAP temp = flist(nown - 1, nowm % lim);
		ll tem = temp.x;
		temp.x = (int)sqrt(lim) + (int)sqrt(lim) - temp.y + 1;
		temp.y = (int)sqrt(lim) - tem + 1;
		return temp;
	}
}
int main() {
//	freopen("maze.in", "r", stdin);
//	freopen("maze.out", "w", stdout);
	n = sc(), m = sc();
	MAP ans;
	ans = flist(n, m);
	out(ans.x), pc(' '), out(ans.y), pc('\n');
    return 0;
}
