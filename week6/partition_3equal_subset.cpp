#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void partition_(ll a[], ll n, ll sum)
{
    ll v[n + 1][sum + 1];
    ll i,j;
    if (sum % 3 == 0)
    {
        for (ll i = 0; i <= n; i++)
        {
            ll c = 0;
            for ( j = 0; j <= sum; j++)
            {
                if (j == 0)
                    v[i][j] = 1;
                else if (i == 0 && j != 0)
                    v[i][j] = 0;
                else if (j >= a[i - 1])
                    v[i][j] = (v[i - 1][j] || v[i - 1][j - a[i-1]]);
                    else
                        v[i][j]=v[i-1][j];
                if (v[i][j] == 1)
                    c++;
                   // cout<<v[i][j]<<" ";
            }

                //  cout<<endl;
        }
        //if (sum / 3 == j && c > 1)
        //        cout << "1" << endl;
          //  else if (sum / 3 == j)
            //    cout << "0" << endl;
            if(v[n][2*sum/3])
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
    }
    else
    {
        cout << "0" << endl;
    }
}
int main()
{
    ll n;
    cin >> n;
    ll a[n + 1];
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }
    partition_(a, n + 1, sum);
}

/*

 ll p = sum / 3;
    ll v[n + 1][p + 1][p + 1];
    memset(v, 0, sizeof(v));
    if (sum % 3 == 0)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= p; j++)
            {
                for (ll k = 1; k <= p; k++)
                {
                    v[i][j][k] = v[i - 1][j][k];
                    if (j >= a[i])
                        v[i][j][k] = max(v[i - 1][j - a[i]][k] + a[i], v[i][j][k]);
                    if (k >= a[i])
                        v[i][j][k] = max(v[i - 1][j][k - a[i]] + a[i], v[i][j][k]);
                    cout<<v[i][j][k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl <<endl;
        }
        if (v[n][p][p] == 2 * sum / 3)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    else
        cout<<"0"<<endl;
}*/
