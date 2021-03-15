#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll optimal_edit_distance(string a, string b)
{
    ll v[a.size()+1][b.size()+1];
    v[0][0] = 0;

    ll i, j;

    for (i = 0; i < a.size()+1; i++)
    {
        v[i][0] = i;
    }
    for (i = 0; i < b.size()+1; i++)
    {
        v[0][i] = i;
    }
    for (i = 1; i <= a.size(); i++)
    {
        for (j = 1; j <= b.size(); j++)
        {
            if (a[i-1] == b[j-1])
            {
                v[i][j] = v[i - 1][j - 1];
            }
            else
            {
                v[i][j] = 1+min(v[i][j - 1], min(v[i - 1][j - 1], v[i - 1][j]));
            }
        }
    }
    return v[a.size()][b.size()];
}

int main()
{
    string a;
    string b;
    cin >> a;
    cin >> b;
    cout << optimal_edit_distance(a, b) << endl;
}