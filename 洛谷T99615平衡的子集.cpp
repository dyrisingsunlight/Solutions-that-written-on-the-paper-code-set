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
const int Maxn = 30;
const int mod = 19530615;
struct NUM {
	int hash, nxt;
}b[(1 << 22)];
int n, ans, mid, cnt;
int a[Maxn], bit[Maxn], tag[(1 << 22)], temp[mod], head[mod];
inline void D_F() {
	bit[0] = 1;
	for(re int i = 1; i <= n; ++i)
		bit[i] = (bit[i - 1] << 1);
}
inline void ADD(int id, int Hash) {
	b[++cnt].nxt = head[id];
	b[cnt].hash = Hash;
	head[id] = cnt;
}
inline int calc(int num) {
	int id = num % mod;
	while(temp[id] && temp[id] != num) {
		++id;
		if(id == mod)
			id = 0;
	}
	temp[id] = num;
	return id;
}
inline void dfs1(int now, int sum, int Hash) {
	if(now > n) {
		if(sum >= 0)
			ADD(calc(sum), Hash);
		return;
	}
	dfs1(now + 1, sum + a[now], Hash + bit[now]);
	dfs1(now + 1, sum - a[now], Hash + bit[now]);
	dfs1(now + 1, sum, Hash);
}
inline void dfs2(int now, int sum, int Hash) {
	if(now >= mid) {
		if(sum >= 0)
			for(re int i = head[calc(sum)]; i; i = b[i].nxt)
				if(!tag[b[i].hash + Hash]) {
					tag[b[i].hash + Hash] = 1;
					++ans;
				}
		return;
	}
	dfs2(now + 1, sum + a[now], Hash + bit[now]);
	dfs2(now + 1, sum - a[now], Hash + bit[now]);
	dfs2(now + 1, sum, Hash);
}
int main() {
	n = sc();
	D_F();
	for(re int i = 1; i <= n; ++i)
		a[i] = sc();
	mid = 1 + n >> 1;
	dfs1(mid, 0, 0);
	memset(tag, 01, sizeof(tag));
	for(re int i = 0; i < mod; ++i) {
		if(!head[i])
			continue;
		int lst = 0;
		for(re int j = head[i]; j; j = b[j].nxt) {
			if(tag[b[j].hash] == i) {
				if(lst)
					b[lst].nxt = b[j].nxt;
			}
			lst = j;
			tag[b[j].hash] = i;
		}
	}
//	for(re int i = 0; i <= (1 << 21); ++i)
//		tag[i] = 0;
	memset(tag, 0, sizeof(tag));
	dfs2(1, 0, 0);
	out(--ans), pc('\n');
    return 0;
}
