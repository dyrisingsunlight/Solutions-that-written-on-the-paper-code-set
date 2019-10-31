//Copied by Dy.
#include<cstdio>
int n,a[301],F[301][301],Ans[301][301],ll[301][301];
void print(){                   //类似BFS的输出
    int l=1,r=1;
    ll[1][0]=1,ll[1][1]=n; //ll[i][0]当前区间左端点，ll[i][1]当前区间右端点
    while(l<=r)      //没输完
    {
        int aa=Ans[ll[l][0]][ll[l][1]];   //当前区间的分界
        printf("%d ",aa);
        if(ll[l][0]!=aa)  //分界左侧还可以分
        {
            r++;          //存入要输出的队列
            ll[r][0]=ll[l][0];
            ll[r][1]=aa;
        }
        if(ll[l][1]!=aa+1) //分界右侧还可以分
        {
            r++;          //存入要输出的队列
            ll[r][0]=aa+1;
            ll[r][1]=ll[l][1];
        }
        l++;
    }
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	  scanf("%d",&a[i]);
	for(int k=2;k<=n;++k)       //区间长度
	  for(int i=1;i<=n-k+1;++i){   //起始点
	  	int r=i+k-1;               //结尾点
	  	for(int j=i;j<r;++j){      //分界
	  		int u=F[i][j]+F[j+1][r]+(a[i]+a[r])*a[j];
	  		if(u>F[i][r]){
	  			F[i][r]=u;     //得到的最大价值
	  			Ans[i][r]=j;      //存怎么分的。
	  		}
	  	}
	  }
	printf("%d\n",F[1][n]);
	print();
}
/*
————————————————
版权声明：本文为CSDN博主「SSL_HKY」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_42937087/article/details/88075198
*/
