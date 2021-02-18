#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
ll get_gcd(int x,int y)
{
    if(x%y==0)
    return y;
    return get_gcd(y,x%y);
}
ll get_lcm(int a,int b)
{
return (a/get_gcd(a,b)*b);//lcm using formulaa
}
int main()
{
    ll a,b;
    cin>>a>>b;// enter two value to find lcm...
  cout<<get_lcm(a,b)<<endl;   
}