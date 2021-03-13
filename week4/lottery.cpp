#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void find_(vector<pair<ll,ll>> &v, vector<ll> &v1, ll n, ll m)// checking elemnts here
{
    ll count = 0;
     for (ll i = 0; i < m; i++)
    { count=0;
        for (ll j = 0; j < n; j++)
        {
            if (v1[i] >= v[j].first && v1[i] <= v[j].second)
            {
                count++;
            }
            else if(v1[i]<v[j].first)
            j=v.size();
        }
        cout<<count<<" ";
    }
}

int main()
{
    ll n;
    ll m;
    ll a,b;
    cin >> n;// size of set (v);
    cin >> m;//size of set (v2) of which elements to check
    vector<pair<ll,ll>>v;// yha me jb size k sath likh rha to extra space generate ho rhi ex- vectr<pair<ll,ll>> v(n);?
    vector<ll>v1(m);

    for (ll i = 0; i < n; i++)
    { cin>>a>>b;
      v.push_back(make_pair(a,b));// taking input of ranges
    }

for(ll i=0;i<m;i++)
cin>>v1[i];
    sort(v.begin(),v.end());// sorting elements

    find_(v, v1,n,m);// fun call

}
