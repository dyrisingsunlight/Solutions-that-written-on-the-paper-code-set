//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
inline void out(ll x) {
    if(x < 0)
        pc('-'), x = -x;
    if(x >= 10)
        out(x / 10);
    pc(x % 10 + '0');
}
const ll INF = 0x7FFFFFFFFFFFFFFF - 1;
ll n, m, tot;
ll v[50010], pri[50010];
bool pos[1000010];
void Selection(ll lim) {
    memset(v, 0, sizeof(v));
    memset(pri, 0, sizeof(pri));
    tot = 0;
    for(ll i = 2; i <= lim; ++i) {
        if(v[i] == 0) {
            pri[++tot] = i, v[i] = i;
        }
        for(int j = 1; j <= tot; ++j) {
            if(pri[j] > v[i] || i * pri[j] > lim)
                break;
            v[i * pri[j]] = pri[j];
        }
    }
}
int main() {
    while(scanf("%lld%lld", &n, &m) != EOF) {
        if(n > m)
            std :: swap(n, m);
        Selection((ll)sqrt(m));
        memset(pos, 0, sizeof(pos));
        ll lst = 0, maxx = -INF, minn = INF, maxx1, maxx2, minn1, minn2;
        if(n == 1)
            pos[0] = 1;
        for(ll i = 1; i <= tot; ++i) {
            for(ll j = (ll)ceil(n / pri[i]); j <= (ll)floor(m / pri[i]); ++j)
                if(j != 1)
                    pos[pri[i] * j - n] = 1;
        }
        for(ll i = n; i <= m; ++i) {
            if(!pos[i - n])
                if(!lst)
                    lst = i;
                else {
                    if(maxx < i - lst) {
                        maxx = i - lst;
                        maxx1 = lst;
                        maxx2 = i;
                    }
                    if(minn > i - lst) {
                        minn = i - lst;
                        minn1 = lst;
                        minn2 = i;
                    }
                    lst = i;
                }
        }
        if(maxx == -INF && minn == INF)
            puts("There are no adjacent primes.");
        else
            out(minn1), pc(','), out(minn2), printf(" are closest, "), out(maxx1), pc(','), out(maxx2), puts(" are most distant.");
    }
    return 0;
}

作者：RisingSunlight
链接：https://www.acwing.com/activity/content/code/content/144058/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
