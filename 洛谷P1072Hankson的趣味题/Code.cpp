//Coded by Dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
#define int ll
int sc()
{
    int xx = 0, ff = 1; char cch = gc;
    while(!isdigit(cch) && cch != EOF)
    {
        if(cch == '-') ff = -1; cch = gc;
    }
    while(isdigit(cch))
    {
        xx = (xx << 1) + (xx << 3) + (cch ^ '0'); cch = gc;
    }
    return xx * ff;
}
void out(int x)
{
    if(x < 0) pc('-'), x = -x;
    if(x >= 10) out(x / 10);
    pc(x % 10 + '0');
}
#undef int
ll n, a0, a1, b0, b1, ans;
ll gcd(ll x, ll y)
{
    if(y == 0) return x;
    return gcd(y, x % y);
}
int main()
{
    n = sc();
    while(n--)
    {
        ans = 0;
        a0 = sc(), a1 = sc(), b0 = sc(), b1 = sc();
        for(ll i = 1; i * i <= b1; ++i)
        {
            if(b1 % i == 0)
            {
                if(i % a1 == 0 && gcd(b1 / b0, b1 / i) == 1 && gcd(i / a1, a0 / a1) == 1) ++ans;
                if(b1 / i != i)
                {
                    ll tem = b1 / i;
                    if(tem % a1 == 0 && gcd(b1 / b0, b1 / tem) == 1 && gcd(tem / a1, a0 / a1) == 1) ++ans;
                }
            }
        }
        out(ans), pc('\n');
    }
    return 0;
}
