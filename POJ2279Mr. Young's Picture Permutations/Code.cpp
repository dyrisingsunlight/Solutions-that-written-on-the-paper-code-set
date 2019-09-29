#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define re register
int n;
int a[10];
//long long f[31][30][29][28][27];
int main() {
	while(scanf("%d", &n) && n) {
		memset(a, 0, sizeof(a));
		for(re int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		long long f[a[1]+1][a[2]+1][a[3]+1][a[4]+1][a[5]+1];
		memset(f, 0, sizeof(f));
		f[0][0][0][0][0] = 1LL;
		for(re int i = 0; i <= a[1]; ++i)
			for(re int j = 0; j <= a[2]; ++j)
				for(re int k = 0; k <= a[3]; ++k)
					for(re int l = 0; l <= a[4]; ++l)
						for(re int z = 0; z <= a[5]; ++z) {
//							if(!i && !j && !k && !l && !z)
//								continue;
							if(i < a[1])
								f[i + 1][j][k][l][z] += f[i][j][k][l][z];
							if(j < a[2] && j < i)
								f[i][j + 1][k][l][z] += f[i][j][k][l][z];
							if(k < a[3] && k < j && k < i)
								f[i][j][k + 1][l][z] += f[i][j][k][l][z];
							if(l < a[4] && l < k && l < j && l < i)
								f[i][j][k][l + 1][z] += f[i][j][k][l][z];
							if(z < a[5] && z < l && z < k && z < j && z < i)
								f[i][j][k][l][z + 1] += f[i][j][k][l][z];
						}
		printf("%lld\n", f[a[1]][a[2]][a[3]][a[4]][a[5]]);
	}
	return 0;
}
