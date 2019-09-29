//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
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
using std :: queue;
struct NODE {
	int nxt, to;
}Map1[2000010], Map2[2000010];
int n, cnt1, cnt2;
int head1[200010], head2[200010];
ll dis[200010], all[200010], v1[200010], v2[200010];
bool vis[200010];
queue <int> q;
inline void ADD(int from, int to) {
	Map1[++cnt1].nxt = head1[from];
	Map1[cnt1].to = to;
	head1[from] = cnt1;
	Map2[++cnt2].nxt = head2[to];
	Map2[cnt2].to = from;
	head2[to] = cnt2;
}
int main() {
//	freopen("monster.in","r",stdin);
//    freopen("monster.out","w",stdout);
	n = sc();
	for(re int i = 1; i <= n; ++i) {
//		v1[i] = sc(), v2[i] = sc();
		scanf("%lld%lld", &v1[i], &v2[i]);
		int x = sc();
		for(re int j = 1; j <= x; ++j) {
			int y = sc();
			ADD(i, y);
		}
	}
	for(re int i = 1; i <= n; ++i) {
		dis[i] = v2[i];
		q.push(i);
		for(re int j = head1[i]; j; j = Map1[j].nxt) {
			int to = Map1[j].to;
			all[i] += v2[to];
		}
	}
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		vis[now] = 1;
		if(all[now] + v1[now] >= dis[now])
			continue;
		for(re int i = head2[now]; i; i = Map2[i].nxt) {
			int to = Map2[i].to;
			all[to] -= dis[now] - all[now] - v1[now];
			if(vis[to]) {
				vis[to] = 0;
				q.push(to);
			}
		}
		dis[now] = all[now] + v1[now];
	}
	out(dis[1]), pc('\n');
    return 0;
}
