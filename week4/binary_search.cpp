#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll bsa(ll arr[],ll b,ll e,ll data)
{
    if(e<b)
    return b-1;
    ll x=(b+((e-b)/2));
    if(arr[x]==data)
    return x;
    if(arr[x-1]<data && arr[x+1]>data)
    return -1;
    if(arr[x]>=data)
    {
        return bsa(arr,b,x-1,data);
    }
    else
    {
        return bsa(arr,x+1,e,data);
    }

}

int main()
{
    ll n,m;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i];

    cin>>m;
    ll a[m];
    for(ll i=0;i<m;i++)
    cin>>a[i];
for(ll i=0;i<m;i++)
{
    ll b=bsa(arr,0,n-1,a[i]);
    cout<<b<<" ";
}
}
