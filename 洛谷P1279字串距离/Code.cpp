//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using std :: min;
#define re register
const int Maxn = 2000 + 10;
char s1[Maxn], s2[Maxn];
int len1, len2, k;
int f[Maxn][Maxn];
int main() {
	scanf("%s%s%d", s1 + 1, s2 + 1, &k);
	len1 = strlen(s1 + 1);
	len2 = strlen(s2 + 1);
	for(re int i = 1; i <= len1; ++i)
		f[i][0] = f[i - 1][0] + k;
	for(re int i = 1; i <= len2; ++i)
		f[0][i] = f[0][i - 1] + k;
	for(re int i = 1; i <= len1; ++i)
		for(re int j = 1; j <= len2; ++j)
			f[i][j] = min(f[i - 1][j] + k, min(f[i][j - 1] + k, f[i - 1][j - 1] + (int)abs(s1[i] - s2[j])));
	printf("%d\n", f[len1][len2]);
	return 0;
}
