//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std :: cerr;
typedef long long ll;
#define re register
const int Maxn = 11 + 1;
int n, m;
bool pd[1 << Maxn];
ll f[Maxn][1 << Maxn];
int main() {
	while(scanf("%d%d", &n, &m) && n && m) {
		memset(f, 0, sizeof(f));
		memset(pd, 0, sizeof(pd));
		#define lim ((1 << m) - 1)
		for(re int i = 0; i <= lim; ++i) {
			bool db = 0, lst = 0;
			for(re int j = 0; j < m; ++j) {
				if(i >> j & 1)
					lst |= db, db = 0;
				else
					db ^= 1;
			}
			pd[i] = 1 - (lst | db);
//			cerr << pd[i] << '\n';
		}
		f[0][0] = 1;
		for(re int i = 1; i <= n; ++i) {
			for(re int j = 0; j <= lim; ++j) {
				for(re int k = 0; k <= lim; ++k) {
					if((j & k) || !pd[j | k])
						continue;
					f[i][j] += f[i - 1][k];
				}
			}
		}
		printf("%lld\n", f[n][0]);
	}
	return 0;
}
