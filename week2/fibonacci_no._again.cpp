#include<bits/stdc++.h>
typedef unsigned long long ll ;
using namespace std;

void get_pasino_period(ll m,vector<ll>&v)//finding pasino period and storing in vector for further use..
{
   ll a=0,b=1,c=a+b,i;
   v.push_back(a);
   v.push_back(b);
   for(i=0;i<m*m;i++)
   {
       c=(a+b)%m;
       a=b;
       b=c;
       v.push_back(c);
       if(a==0 && b==1)// if this thing happen then its starts repeating all value ..
    {
        v.pop_back();
        v.pop_back();
        break;
    }
   }
}
ll fibo(ll m,ll n)
{ ll a=0,b=1,c=0,i;
    vector<ll> v;
    get_pasino_period(m,v);
    ll size=v.size();
   ll rem=c=n%size;
 
for(i=2;i<=rem;i++)
{
    c=(a+b)%m;
    a=b;
    b=c;
}
return c;
}

int main()
{ ll m,n,c;
    cin>>n;//enter position of fibonnaci no...
    cin>>m;//enter modulos of fibonnaci no...
    c=fibo(m,n);
cout<<c<<endl;
}
