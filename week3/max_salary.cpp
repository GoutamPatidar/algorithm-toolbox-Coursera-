#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool find_m(string &a, string &b)
{
    if (b + a > a + b)
        return 1;
    else
        return 0;
}

void max_salary(vector<string> &v, ll n)
{
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < n - i; j++)
        {
            if (find_m(v[j], v[j + 1]))
                swap(v[j], v[j + 1]);
        }
    }
    for(ll i=0;i<v.size();i++)
    cout<<v[i];
}
int main()
{
    ll n;
    cin >> n;
    vector<string> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    max_salary(v, n);

}
