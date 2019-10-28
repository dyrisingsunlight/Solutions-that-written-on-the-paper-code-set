#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
int n, m;
int a[30][30], mem[30][30];
int f[30];
inline void print(int id, int num) {
	if(id == 0)
		return;
	print(id - 1, num - mem[id][num]);
	printf("%d %d\n", id, mem[id][num]);
}
int main() {
	scanf("%d%d", &n, &m);
	for(re int i = 1; i <= n; ++i)
		for(re int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(re int i = 1; i <= n; ++i) {
		for(re int j = m; j >= 0; --j) {
			for(re int k = 1; k <= j; ++k)
				if(f[j] < f[j - k] + a[i][k]) {
					f[j] = f[j - k] + a[i][k];
					mem[i][j] = k;
				}
		}
	}
	printf("%d\n", f[m]);
	print(n, m);
	return 0;
}
