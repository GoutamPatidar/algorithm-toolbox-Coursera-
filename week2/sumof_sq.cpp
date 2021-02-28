 #include<bits/stdc++.h>
typedef unsigned long long ll ;
using namespace std;

ll sum_sq(ll n)//finding fibonacci no..
{
  ll a=0,b=1,c=a+b;
  ll i,rem=0;
  n=n%60;// as pasino period of 10 is 60..
  if(n<=1)
  return n;
  
  for(i=2;i<=n;i++)
  {
    c=(a+b)%10;
    a=b;
    b=c;
  }
  return c%10;
}
int main()
{
   ll n,m;
   cin>>n;//enter the position of fibonacci no.
   m=(sum_sq(n)*sum_sq(n+1))%10;// using technique of n*n+1
   cout<<m<<endl;
}
