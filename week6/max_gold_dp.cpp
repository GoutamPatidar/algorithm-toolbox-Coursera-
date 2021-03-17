/*#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll optimal_max(ll v[], ll n, ll s)
{
    ll temp[n + 1][s + 1];
    memset(temp, 0, sizeof(temp));
    for (ll i = 1; i < n + 1; i++)
    {
        for (ll j = 1; j < s + 1; j++)
        {
            if (j >= v[i])
             temp[i][j]= max(temp[i - 1][j - v[i]] + v[i], temp[i - 1][j]);
            else
                temp[i][j] = temp[i - 1][j];
        }
    }

    
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= s; j++)
        {
            cout << temp[j][i] << " ";
        }
        cout << endl;
    }
    return temp[n][s];
}

int main()
{
    ll s, n;
    cin >> s;
    cin >> n;
    ll v[n + 1];
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    cout << optimal_max(v, n, s);
}


 ll temp[s + 1][n + 1];
    memset(temp, 0, sizeof(temp));
    ll tem = 0;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= s; j++)
        {
           if(i==0 || j==0)
           temp[j][i]=0;
           else if(v[i-1]<=j)
           temp[j][i]= max(v[i-1]+temp[j-v[i-1]][i-1],temp[j][i-1]);
           else
           temp[j][i]=temp[j][i-1];
          // cout<<temp[j][i]<<" ";
        }
       // cout << endl;
    }*/

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

bool greater(int a, int b)
{
    return a > b;
}

int optimal_weight(int W, vector<int> &w)
{
    vector<vector<int>> K(w.size() + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= w.size(); ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            if (i == 0 || j == 0)
                K.at(i).at(j) = 0;
            else if (w[i - 1] <= j)
                K.at(i).at(j) = std::max(K.at(i - 1).at(j), w[i - 1] + K.at(i - 1).at(j - w[i - 1]));
            else
                K.at(i).at(j) = K.at(i - 1).at(j);
        }
    }
    return K.at(w.size()).at(W);
}

int main()
{
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> w[i];
    }
    std::sort(w.begin(), w.end(), greater);
    std::cout << optimal_weight(W, w) <<"\n";
}
