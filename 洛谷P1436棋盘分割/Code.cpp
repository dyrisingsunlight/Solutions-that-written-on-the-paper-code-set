//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: min;
using std :: cerr;
typedef long long ll;
#define re register
int n;
ll a[10][10], sum[10][10];
ll f[20][10][10][10][10];
int main() {
	// Input
	scanf("%d", &n);
	for(re int i = 1; i <= 8; ++i)
		for(re int j = 1; j <= 8; ++j)
			scanf("%lld", &a[i][j]);
	for(re int i = 1; i <= 8; ++i)
		for(re int j = 1; j <= 8; ++j) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
//			cerr << sum[i][j] << '\n';
		}
			
	// Deal with it.
	memset(f, 0x3f, sizeof(f));
	for(re int i = 1; i <= 8; ++i) {
		for(re int j = 1; j <= 8; ++j) {
			for(re int k = i; k <= 8; ++k) {
				for(re int l = j; l <= 8; ++l) {
					ll now = sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1];
//					cerr << now << '\n';
					f[1][i][j][k][l] = now * now;
				}
			}
		}
	}
	for(re int i = 2; i <= n; ++i) {
		for(re int x1 = 1; x1 <= 8; ++x1) {
			for(re int y1 = 1; y1 <= 8; ++y1) {
				for(re int x2 = x1; x2 <= 8; ++x2) {
					for(re int y2 = y1; y2 <= 8; ++y2) {
						for(re int nowx = x1 + 1; nowx <= x2; ++nowx) {
							f[i][x1][y1][x2][y2] = min(f[i][x1][y1][x2][y2], min(f[i - 1][x1][y1][nowx - 1][y2] + f[1][nowx][y1][x2][y2], f[1][x1][y1][nowx - 1][y2] + f[i - 1][nowx][y1][x2][y2]));
//							cerr << f[i][x1][y1][x2][y2] << '\n';
						}
						for(re int nowy = y1 + 1; nowy <= y2; ++nowy) {
							f[i][x1][y1][x2][y2] = min(f[i][x1][y1][x2][y2], min(f[i - 1][x1][y1][x2][nowy - 1] + f[1][x1][nowy][x2][y2], f[1][x1][y1][x2][nowy - 1] + f[i - 1][x1][nowy][x2][y2]));
						}
					}
				}
			}
		}
	}
	// Output
	printf("%lld\n", f[n][1][1][8][8]);
	return 0;
}
