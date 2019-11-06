//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
inline int sc() {
	int xx = 0, ff = 1; char cch = gc;
	while(!isdigit(cch) && cch != EOF) {
		if(cch == '-')
			ff = -1; cch = gc;
	}
	while(isdigit(cch)) {
		xx = (xx << 1) + (xx << 3) + (cch ^ '0'); cch = gc;
	}
	return xx * ff;
}
inline void out(int x) {
	if(x < 0)
		pc('-'), x = -x;
	if(x >= 10)
		out(x / 10);
	pc(x % 10 + '0');
}
const int Maxn = 1e7 + 10;
int n, tot;
int v[Maxn], pri[Maxn];
bool pd[Maxn];
int main() {
	n = sc();
	for(int i = 2; i <= Maxn; ++i) {
		if(v[i] == 0) {
			v[i] = i;
			pri[++tot] = i;
		}
		for(int j = 1; j <= tot; ++j) {
			if(pri[j] > v[i]|| pri[j] * i > Maxn)
				break;
			v[i * pri[j]] = pri[j];
		}
	}
	for(int i = 1; i <= tot; ++i)
		pd[pri[i]] = 1;
	while(n--) {
		int x = sc();
		if(pd[x])
			printf("%d is prime\n", x);
		else
			printf("%d is not prime\n", x);
	}
	return 0;
}
