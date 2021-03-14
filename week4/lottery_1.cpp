#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
void find_(vector<pair<ll,ll>> &v, vector<ll> &v1, ll n, ll m)
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
}*/

int main()
{
    ll n;
    ll m;
    ll a,b;
    cin >> n;// size of set (v);
    cin >> m;//size of set (v2) of which elements to check
    vector<pair<ll,ll>> v(n);	//iska mtlab h wo n size ka v vector bana dega jisme default values hogi 
				// aur agar fir aur usme tu push_back karga toh naya element insert kar raha h tu toh size toh badega hi
				// nahi toh eaisa kar v[i] = {a,b};
					    
    // yha me jb size k sath likh rha to extra space generate ho rhi ex- vector<pair<ll,ll>> v(n);?
    vector<ll> v1(m);
	cout<<v.size()<<" "<<v1.size()<<endl;
    for (ll i = 0; i < n; i++)
    { cin>>a>>b;
     // v.push_back(make_pair(a,b));
     v[i] = {a,b};
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> v1[i];
    }
     for(ll i=0;i<v.size();i++)
     	cout<<v[i].first<<" "<<v[i].second<<endl;

    /*sort(v.begin(),v.end());
   
    find_(v, v1,n,m);*/
}



/*
input
2 3 // size of both vector v & v1 respectively
0 5   // element of v vector 
7 10  // element of v vector   
1 6 11  // elemnt of v1 vector

output 
printing vector 
0 0   this is extra
0 0   this is also extra
0 5
7 10
*/
