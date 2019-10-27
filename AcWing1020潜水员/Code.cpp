//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
int n, m, s;
int f[110][110];
int main() {
	scanf("%d%d%d", &n, &m, &s);
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(re int i = 1; i <= s; ++i) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		for(re int j = n; j >= 0; --j)
			for(re int k =  m; k >= 0; --k) {
				int nowx = j + x;
				int nowy = k + y;
				nowx = std :: min(nowx, n);
				nowy = std :: min(nowy, m);
				f[nowx][nowy] = std :: min(f[nowx][nowy], f[j][k] + w);
			}
	}
	printf("%d\n", f[n][m]);
	return 0;
}
