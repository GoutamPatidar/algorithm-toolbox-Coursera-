 #include<bits/stdc++.h>
typedef unsigned long long ll ;
using namespace std;

ll last_digit(ll n)
{
  ll a=0,b=1,c=a+b;
  ll i,rem=0;
  if(n<=1)
  return n;
  // as pasino period of 10 is 60.
  c=rem=n%60;
  if(rem<=1)
    return rem;
  ll sum=a+b;
  for(i=2;i<=rem;i++)
  {
     c=(a+b)%10;
     a=b;
     b=c;
     sum=sum +c;
  }
  return sum%10;
}
int main()
{
   ll n,m;
   cin>>n;//enter the position of fibonacci no.
   m=last_digit(n);
   cout<<m<<endl;
}
