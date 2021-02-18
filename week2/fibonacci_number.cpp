#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
int main()
{
    ll i,n;
    ll a=0,b=1,c=0;
//cout<<"enter the no..";
    cin>>n;
    if(n==0)
    c=a;
    if(n==1)
    c=b;

    for(i=2; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;      
    }

   cout<<c<<endl;
}
