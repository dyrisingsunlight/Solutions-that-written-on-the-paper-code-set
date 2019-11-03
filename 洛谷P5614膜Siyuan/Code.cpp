//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
int n, m, ans;
int a[10], b[10], c[10];
int fabs(int x) {
	return x > 0 ? x : -x;
}
inline int control(int now) {
//	int goal = 0, cnt = 0;
//	while(now) {
//		int tem = (now & 1);
//		++cnt;
//		if(cnt == 1 || cnt == 4) {
//			if(tem == 0)
//				goal = goal + (1 << (cnt - 1));
//		}
//		else if(cnt == 2 || cnt == 3) {
//			if(tem == 1)
//				goal = goal + (1 << (cnt - 1));
//		}
//		else {
//			if(tem == 1)
//				goal = goal + (1 << (cnt - 1));
//		}
//		now >>= 1;
//	}
//	return goal;
	return 9 ^ now; 
}
int main() {
	scanf("%d%d", &n, &m);
	for(re int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	for(re int i = 1; i <= m; ++i)
		for(re int j = 1; j <= m; ++j) {
			int now = (fabs(a[1] - i) ^ fabs(b[1] - j));
			int g = control(now);
			int g1 = c[1] - g, g2 = c[1] + g;
			int aaa = 0;
			if(g1 > 0 && g1 <= m) {
				bool pd = 1;
				for(re int k = 2; k <= n; ++k) {
					if((fabs(a[k] - i) ^ fabs(b[k] - j) ^ fabs(c[k] - g1)) != 9) {
						pd = 0;
						break;
					}
				}
				if(pd)
					++ans, aaa = 1;
			}
			if(g2 <= m && g2 > 0) {
				bool pd = 1;
				for(re int k = 2; k <= n; ++k) {
					if((fabs(a[k] - i) ^ fabs(b[k] - j) ^ fabs(c[k] - g2)) != 9) {
						pd = 0;
						break;
					}
				}
				if(pd && (g1 != g2 && aaa == 1 || aaa == 0))
					++ans;
			}
		}
	printf("%d\n", ans);
	return 0;
}
