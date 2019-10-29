//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
const int Maxn = 100000 + 10;
int n, ans;
int a[Maxn][5];
int f[Maxn][5][5][5];
int main() {
	scanf("%d", &n);
	for(re int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
	for(re int i = 1; i <= 3; ++i)
		for(re int j = 1; j <= 3; ++j)
			f[1][i][j][i] = a[1][i];
	for(re int i = 2; i <= n; ++i)
		for(re int pre = 1; pre <= 3; ++pre)
			for(re int now = 1; now <= 3; ++now)
				for(re int lst = 1; lst <= 3; ++lst)
					for(re int fir = 1; fir <= 3; ++fir)
						if((lst > now && now < pre) || (lst < now && now > pre))
							f[i][pre][now][fir] = std :: max(f[i][pre][now][fir], f[i - 1][now][lst][fir] + a[i][pre]);
			
	for(re int now = 1; now <= 3; ++now)
		for(re int lst = 1; lst <= 3; ++lst)
			for(re int fir = 1; fir <= 3; ++fir)
				if((lst > now && now < fir) || (lst < now && now > fir))
					ans = std :: max(ans, f[n][now][lst][fir]);
	printf("%d\n", ans);
	return 0;
}
