#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll refill(ll a[], ll len, ll n)
{
    ll ref = 0;
    ll last = 0;
    ll curr = 0;
    while (curr <= n)
    {
        last = curr;
        while (curr <= n && a[curr + 1] - a[last] <= len)//finding last posible refill station
            curr++;
        if (curr == last)// checking its is same as prev station or not
            return -1;//impossible complte journey
        if (curr <= n)
            ref++;//increment refilling value
    }
    return ref;
}
int main()
{
    ll max_travel, len, n;

    cin >> max_travel; //distance to be travel..
    cin >> len;        //distance that can be travel by refuiling once..
    cin >> n;
    ll a[n];
    a[0]=0;//for compareing purpose
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
        a[n+1]=max_travel; //for compareing purpose
    ll x = refill(a, len, n);
    cout<<x<<endl;
}
