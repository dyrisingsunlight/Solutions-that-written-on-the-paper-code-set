//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define re register
//int dir[6][3];
int dir[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
struct MAP {
	int xx, yy, zz, dis;
};
int x, y, z, stx, sty, stz, fix, fiy, fiz;
bool pd;
int vis[32][32][32];
char s[32][32][32];
std :: queue <MAP> q;
inline void bfs() {
	q.push((MAP){stx, sty, stz, 0});
//	q.push((MAP){fix, fiy, fiz, 0});
	vis[stx][sty][stz] = 1;
//	vis[fix][fiy][fiz] = -1;
	while(!q.empty()) {
		MAP now = q.front();
		q.pop();
		if(now.xx == fix && now.yy == fiy && now.zz == fiz) {
			printf("Escaped in ");
			printf("%d", now.dis);
			printf(" minute(s).\n");
			pd = 1;
			return;
		}
		for(re int i = 0; i < 6; ++i) {
			MAP nxt;
			nxt.xx = now.xx + dir[i][0];
			nxt.yy = now.yy + dir[i][1];
			nxt.zz = now.zz + dir[i][2];
			#define X nxt.xx
			#define Y nxt.yy
			#define Z nxt.zz
			if(X < 0 || X >= x || Y < 0 || Y >= y || Z < 0 || Z >= z || s[X][Y][Z] == '#' || vis[X][Y][Z])
				continue;
//			if(vis[now.xx][now.yy][now.zz] + vis[nxt.xx][nxt.yy][nxt.zz] == 0) {
//				printf("Escaped in ");
//				printf("%d", now.dis + nxt.dis);
//				printf(" minute(s).\n");
//				pd = 1;
//				return;
//			}
//			if(vis[nxt.xx][nxt.yy][nxt.zz] != 0)
//				continue;
			nxt.dis = now.dis + 1;
			vis[nxt.xx][nxt.yy][nxt.zz] = vis[now.xx][now.yy][now.zz];
			q.push(nxt);
		}
	}
}
int main() {
//	dir[0][0] = 0, dir[0][1] = 0, dir[0][2] = 1;
//	dir[1][0] = 0, dir[1][1] = 0, dir[1][2] = -1;
//	dir[2][0] = 0, dir[2][1] = -1, dir[2][2] = 0;
//	dir[3][0] = 0, dir[3][1] = 1, dir[3][2] = 0;
//	dir[4][0] = 1, dir[4][1] = 0, dir[4][2] = 0;
//	dir[5][0] = -1, dir[5][1] = 0, dir[5][2] = 0;
	while(scanf("%d%d%d", &x, &y, &z) && x && y && z) {
		memset(vis, 0, sizeof(vis));
		pd = 0;
		while(!q.empty())
			q.pop();
		//Chu Shi Hua memset!!!!!!!
		for(re int i = 0; i < x; ++i) {
			for(re int j = 0; j < y; ++j) {
				scanf("%s", s[i][j]);
				for(re int k = 0; k < z; ++k) {
					if(s[i][j][k] == 'S')
						stx = i, sty = j, stz = k;
					if(s[i][j][k] == 'E')
						fix = i, fiy = j, fiz = k;	
				}
			}
		}
		bfs();
		if(!pd)
			puts("Trapped!");
	}
    return 0;
}
