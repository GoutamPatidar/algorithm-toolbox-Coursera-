#include<bits/stdc++.h>
typedef unsigned long long ll;

using namespace std;
ll get_gcd(int x,int y)
{
    if(x%y==0)
    return y;
    return get_gcd(y,x%y);
}

int main()
{
    ll a,b;
    cin>>a>>b;// enter two no. to find gcd
    if(b>a)
    cout<<get_gcd(b,a);
    else
    cout<<get_gcd(a,b)<<endl;
}