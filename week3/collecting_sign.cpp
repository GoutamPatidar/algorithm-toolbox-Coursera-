#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef struct p
{
    ll a;
    ll b;
}p;
void qsort(vector<p>&v)//issuee....
{
vector<p> x;
ll z=0;
for(ll j=0;j<x.size();j++)
{
for(ll i=0;i<x.size();i++)
{
    double max=0;
if(v[i].b>max)
{
max=v[i].b;
z=i;
}
}x[j]=v[z];
}
v=x;

}
vector<ll> collect(vector<p> &v)
{
    vector<ll> t;
    ll l = 0;
    ll h = v.size()-1;
    qsort(v);//sorting issue.....
    ll point = v[0].b;
    t.push_back(point);
    for (ll i = 1; i < v.size(); i++)
    {
        if (point < v[i].a || point > v[i].b)
        {
            point = v[i].b;
            t.push_back(point);
        }
    }
    return t;
}
int main()
{
    ll n;
    cin >> n;
    vector<p> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].a;
        cin >> v[i].b;
    }

    vector<ll> l = collect(v);
    cout << l.size() << endl;
    for (ll i = 0; i < l.size(); i++)
        cout << l[i] << endl;
}
