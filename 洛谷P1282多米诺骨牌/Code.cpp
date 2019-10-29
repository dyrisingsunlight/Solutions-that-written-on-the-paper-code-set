//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
const int Maxn = 1000 + 10;
const int Maxm = 6 * 1000 + 10;
int n, num, tot;
int w[Maxn], v[Maxn];
int f[Maxn][Maxm];
bool vis[Maxn][Maxm];
inline void control(int x, int y, int i) {
	if(x > y) {
		w[i] = x - y << 1;
		v[i] = 1;
		tot += (x - y);
	}
	else if(x < y) {
		w[i] = y - x << 1;
		v[i] = -1;
		tot += (y - x);
		++num;
	}
}
int main() {
	scanf("%d", &n);
	for(re int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		control(x, y, i);
	}
	vis[0][0] = 1;
	for(re int i = 1; i <= n; ++i) {
		for(re int j = tot; j >= 0; --j) {
			f[i][j] = f[i - 1][j];
			vis[i][j] = vis[i - 1][j];
			if(vis[i - 1][j - w[i]] || j - w[i] == 0) {
				if(!vis[i][j]) {
					f[i][j] = f[i - 1][j - w[i]] + v[i];
					vis[i][j] = 1;
				}
				else
					f[i][j] = std :: min(f[i][j], f[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	for(; tot >= 0; --tot)
		if(vis[n][tot])
			break;
	printf("%d\n", f[n][tot] + num);
	return 0;
}
