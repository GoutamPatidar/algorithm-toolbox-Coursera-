#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> calculate(ll n)
{
    vector<ll> v1;
    ll a[n + 1];
    ll i = 0;
    a[0]=0;
    for (i = i; i < n + 1; i++){
        a[i] = a[i - 1] + 1;
    if (i % 2 == 0)
        a[i] = min(a[i / 2] + 1, a[i]);
    if (i % 3 == 0)
        a[i] = min(a[i / 3] + 1, a[i]);
    }
    i = n;

    while (i != 1)
    {
        v1.push_back(i);
        if (a[i - 1] == a[i] - 1)
            i = i - 1;
        else if (i % 2 == 0 && a[i / 2] == a[i] - 1)
            i = i / 2;
        else if (i % 3 == 0 && a[i / 3] == a[i] - 1)
            i = i / 3;
    }
    v1.push_back(1);
    return v1;
}

int main()
{
    ll n;
    cin >> n;//enter the no...
    vector<ll> v;
    v = calculate(n);// calling funtion
    cout << v.size() - 1 << endl;//
    for (auto i = v.rbegin(); i != v.rend(); i++)
        cout << *i << " ";
}
