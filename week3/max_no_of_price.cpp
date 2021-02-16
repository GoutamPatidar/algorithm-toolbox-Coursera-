#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> solve(ll n)
{
    vector<ll> v;
    for (ll i = 1; i <= n; i++)
    {
        if (2 * i >= n){
            v.push_back(n);
            break;
        }
        else
        {
            v.push_back(i);
            n = n - i;
        }
    }
    return v;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> v;
    v = solve(n);
    cout<<v.size()<<endl;
    for(ll i=0;i<v.size();i++)
cout<<v[i]<<" ";
}