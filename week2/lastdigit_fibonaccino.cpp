#include<bits/stdc++.h>
typedef  unsigned long long ll;
using namespace std;
void get_pasino_period(ll m,vector<ll>&v)//finding paisino period and storing them in vector..
{
    ll a=0,b=1,i=0,c=a+b;
    v.push_back(a);
    v.push_back(b);
    for(i=2;i<m*m;i++)
    {
        c=(a+b)%m;
        a=b;
        b=c;
        v.push_back(c);
        if(a==0 && b==1)
        {
         v.pop_back();
         v.pop_back();
         break;
        }
    }

}
int main()
{
ll i,j=0,n,s,a=0,b=1,c=a+b;

vector<ll> v;
cin>>n;// position of fibonacci  no..
get_pasino_period(10,v);
s=v.size();
ll rem=n %s;//taking mod with array size to small the size as this thing repeats after a period..
if(rem==0)
c=a;
if(rem==1)
c=b;
for(i=2;i<=rem;i++)
{
   c=(a+b)%10;
   a=b;
   b=c;
}
cout<<c<<endl;
}
