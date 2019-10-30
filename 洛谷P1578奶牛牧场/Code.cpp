//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: max;
using std :: min;
#define re register
const int Maxn = 5000 + 10;
struct NODE {
	int x, y;
	bool operator < (const NODE &now) const {
		if(x == now.x)
			return y < now.y;
		return x < now.x;
	}
}a[Maxn];
int L, W, n, ans;
inline bool cmp(NODE xx, NODE yy) {
	return xx.y < yy.y;
}
int main() {
	scanf("%d%d", &L, &W);
	scanf("%d", &n);
	for(re int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].x, &a[i].y);
	a[++n].x = 0, a[n].y = 0;
	a[++n].x = L, a[n].y = W;
	a[++n].x = 0, a[n].y = W;
	a[++n].x = L, a[n].y = 0;
	std :: sort(a + 1, a + 1 + n);
	for(re int i = 1; i <= n; ++i) {
		int l = 0, h = W, r = L - a[i].x;
		for(re int j = i + 1; j <= n; ++j) {
			if(r * (h - l) <= ans)
				break;
			ans = max(ans, (a[j].x - a[i].x) * (h - l));
			if(a[i].y == a[j].y)
				break;
			if(a[j].y > a[i].y)
				h = min(h, a[j].y);
			else
				l = max(l, a[j].y);
		}
		l = 0, h = W, r = a[i].x;
		for(re int j = i - 1; j >= 1; --j) {
			if(r * (h - l) <= ans)
				break;
			ans = max(ans, (a[i].x - a[j].x) * (h - l));
			if(a[j].y == a[i].y)
				break;
			if(a[j].y > a[i].y)
				h = min(h, a[j].y);
			else
				l = max(l, a[j].y);
		}
	}
	std :: sort(a + 1, a + 1 + n, cmp);
	for(re int i = 1; i <= n - 1; ++i)
		ans = max(ans, (a[i + 1].y - a[i].y) * L);
	printf("%d\n", ans);
	return 0;
}
