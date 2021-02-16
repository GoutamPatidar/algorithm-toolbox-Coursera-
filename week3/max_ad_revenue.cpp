#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll max_index(ll arr[], ll n)//funtion for finding max value index...
{
    ll m_i = 0;
    ll m = INT_MIN;
    for (ll i = 0; i < n; i++)
    {
        if (m < arr[i])
        {
            m = arr[i];
            m_i = i;
        }
    }
    return m_i;
}

ll max_rev(ll a[], ll b[], ll n)//finding max revenue by multiplying max value and sum
{
    ll sum = 0;
    while (n!= 0)
    {
        ll x = max_index(a, n);//finding index for max value in array
        ll y = max_index(b, n);//finding index for max value in array
        sum = sum + (a[x]*b[y]);
        swap(a[x], a[n - 1]);// swaping and delting the counted postion from array
        swap(b[y], b[n - 1]);// swaping and delting the counted postion from array
        n--;
    }
    return sum;
}

int main()
{
    ll n;
    cin >> n;//no.of element in each array
    ll a[n], b[n];

    for (ll i = 0; i < n; i++)//taking input in both array 
        cin >> a[i];
    for (ll i = 0; i < n; i++)//taking input in both array 
        cin >> b[i];
    ll x = max_rev(a, b, n);
    cout << x << endl;
}
