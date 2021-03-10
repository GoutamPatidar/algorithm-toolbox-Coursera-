#include <bits/stdc++.h>
typedef unsigned long long ll;

using namespace std;

ll majore(vector<ll> &v, ll n)// finding majority elements
{
    ll a = v[0];
    ll count = 1;
    for (ll i = 1; i < n; i++)
    {
        if (v[i] == a)
            count++;
        else
            count--;
        if (count == 0)
        {
            a = v[i];
            count = 1;
        }
    }
    return a;//returns the element which is in majority
}
ll confirm(vector<ll> &v, ll n, ll maj)
{                                     // confirming majority element
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] == maj)
            count++;
    }
    if (count > n / 2)
        return 1;
    else
        return 0;
}
void findmajority(vector<ll> &v, ll n)
{
    ll maj = majore(v, n);
    cout << confirm(v, n, maj) << endl;
}

int main()
{
    ll n;
    cin >> n;// size of array
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];// elements in array

    //quick_sort(a,0, a.size());       sorting in incresing order using quick sort
    findmajority(a, n); //finding majority elements...
}
