#include <bits/stdc++.h>
using namespace std;
#define re register
inline __int128 sc()
{
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void out(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        out(x/10);
    putchar(x%10+'0');
}
__int128 n, m, res;
__int128 a[100];
__int128 f[100][100];
inline __int128 qw(__int128 x, __int128 y) {
    __int128 ans = 1;
    while(y) {
        if(y & 1)
            ans = ans * x;
        x *= x;
        y >>= 1;
    }
    return ans;
}
int main() {
    n = sc(), m = sc();
    for(re __int128 i = 1; i <= n; ++i) {
        for(re __int128 j = 1; j <= m; ++j)
            a[j] = sc();
        memset(f, 0, sizeof(f));
        for(re __int128 k = 1; k <= m; ++k) {
            for(re __int128 j = 1; j <= m - k + 1; ++j) {
                re __int128 l = j + k - 1;
                if(j == l)
                    f[j][l] = a[j] * qw(2, m - k + 1);
                else {
                    __int128 teml = a[j] * qw(2, m - k + 1) + f[j + 1][l];
                    __int128 temr = a[l] * qw(2, m - k + 1) + f[j][l - 1];
                    f[j][l] = max(f[j][l], max(teml, temr));
                }
            }
        }
        res += f[1][m];
    }
    out(res);
    return 0;
}
