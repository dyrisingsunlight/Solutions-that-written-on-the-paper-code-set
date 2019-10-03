//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
using std :: sort;
using std :: unique;
using std :: lower_bound;
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
const ll mod = 1e9 + 7;
ll n, len;
ll ans;
ll a[200000 + 10], temp[200000 + 10], minn[200000 + 10], maxx[200000 + 10];
ll t[200000 + 10];
#define lowbit(x) (x & (-x))
inline void update(ll x) {
	for(; x <= n; x += lowbit(x))
		t[x] += 1;
}
inline ll query(ll x) {
	ll res = 0LL;
	for(; x > 0; x -= lowbit(x))
		res += t[x];
	return res;
}
int main() {
// 	freopen("sub6.in", "r", stdin);
	n = sc();
//	scanf("%d", &n);
	for(re int i = 1; i <= n; ++i) {
		a[i] = sc();
		temp[++len] = a[i];
	}
	sort(temp + 1, temp + 1 + len);
	len = unique(temp + 1, temp + 1 + len) - temp - 1;
	for(re int i = 1; i <= n; ++i)
		a[i] = lower_bound(temp + 1, temp + len + 1, a[i]) - temp;
	memset(t, 0, sizeof(t));
	for(re int i = 1; i <= n; ++i) {
		minn[i] = query(a[i] - 1);
		update(a[i]);
	}
	memset(t, 0, sizeof(t));
	for(re int i = n; i >= 1; --i) {
		maxx[i] = query(n) - query(a[i]);
		update(a[i]);
	}
	for(re int i = 1; i <= n; ++i)
		ans = (ans + (maxx[i] * minn[i] % mod)) % mod;
	memset(t, 0, sizeof(t));
	memset(maxx, 0, sizeof(maxx));
	memset(minn, 0, sizeof(minn));
	for(re int i = 1; i <= n; ++i) {
		minn[i] = query(n) - query(a[i]);
		update(a[i]);
	}
	memset(t, 0, sizeof(t));
	for(re int i = n; i >= 1; --i) {
		maxx[i] = query(a[i] - 1);
		update(a[i]);
	}
	for(re int i = 1; i <= n; ++i)
		ans = (ans + (maxx[i] * minn[i] % mod)) % mod;
	out(ans), pc('\n');
    return 0;
}
