//Coded by Dy.
#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define gc getchar()
#define pc(x) putchar(x)
inline int sc() {
    int xx = 0, ff = 1; char cch = gc;
    while(!isdigit(cch)) {
        if(cch == '-') ff = -1; cch = gc;
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
#define re register
int t, n, m;
std :: unordered_map <int, bool> vis;
std :: unordered_map <int, int> ans;
bool pd;
int main() {
//	freopen("A.in", "r", stdin);
//	freopen("A.out", "w", stdout);
	t = sc();
	while(t--) {
		vis.clear();
		ans.clear();
		n = sc(), m = sc();
		while(m--) {
			int opt = sc(), x = sc();
			if(opt == 1)
				vis[x] = 1;
			else {
				if(!vis[ans[x]] && ans[x]) {
					out(ans[x]), pc('\n');
					continue;
				}
				else if(ans[x]) {
					for(re int i = ans[x]; i <= n; ++i) {
						if(!vis[i]) {
							ans[x] = i;
							out(i), pc('\n');
							break;
						}
					}
					continue;
				}
				else if(vis[x - 1] && ans[x - 1] && !vis[ans[x - 1]]) {
					ans[x] = ans[x - 1];
					out(ans[x]), pc('\n');
					continue;
				}
				for(re int i = x; i <= n; ++i) {
					if(!vis[i]) {
						ans[x] = i;
						out(i), pc('\n');
						for(re int j = x; j <= i; ++j)
							ans[j] = i;
						break;
					}
					if(ans[i] && !vis[ans[i]]) {
						ans[x] = ans[i];
						out(ans[x]), pc('\n');
						break;
					}
				}
			}
		}
	}
    return 0;
}
