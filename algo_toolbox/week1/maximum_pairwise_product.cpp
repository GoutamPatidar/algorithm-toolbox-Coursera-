#include<bits/stdc++.h>
typedef long long ll;

using namespace std;
ll findmax(vector<ll>&v)
{
ll max1=-1;
ll p=v.size();
for(ll i=0;i<v.size();i++)//finding max in array for 1st no. ....
{
    if(max1==-1||v[i]>v[max1])
    {
        max1=i;
    }
}
ll max1x=-1;
for(ll j=0;j<v.size();j++)// finding max in array for 2nd no.. other than first index no..
{
    if((max1x==-1|| v[j]>v[max1x] )&& (j!=max1))
    {
        max1x=j;
}
}
return(v[max1]*v[max1x]);
}

int main()
{ll data,n;
    vector<ll>v;
    cin>>n;// size of vector or array...
    for(ll i=0;i<n;i++)
    {
        cin>>data;// value to be enter ...
        v.push_back(data);
    }
    ll m=findmax(v);
    cout<<m<<endl;
}
