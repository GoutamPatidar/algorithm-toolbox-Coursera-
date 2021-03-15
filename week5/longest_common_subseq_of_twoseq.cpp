#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll longest_subseq(ll str1[], ll str2[], ll m, ll n)
{
    ll temp[m + 1][n + 1]; // creating  a determinant or matrix i.e. a 2d array

    for (ll i = 0; i < m + 1; i++)
        temp[i][0] = 0; // putting 0 at temp[i][0] postition
    for (ll i = 0; i < n + 1; i++)
        temp[0][i] = 0; // putting 0 at temp[0][i] postition

    for (ll i = 1; i <= m; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (str1[j - 1] == str2[i- 1])// checking the string matching with each other or not (-1 is because our str[] is starts from 0 index)
                temp[i][j] = 1 + temp[i - 1][j - 1];// taking diagonal +1 elements
            else
                temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);// taking maximum of three

        }
    }
 /*  for(ll i=0;i<=m;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            cout<<temp[i][j]<<" "; // this is only for checking purpose
        }
        cout<<endl;
    }*/
    return (temp[m][n]);// returning the index of last elemnt of temp
}

int main()
{
    ll n, m;
    cin >> n;// size of string 1
    ll str1[n];
    for (ll i = 0; i < n; i++)
        cin >> str1[i];  // taking input of string 1

        cin >> m;// size of string 2
    ll str2[m];
    for (ll i = 0; i < m; i++)
        cin >> str2[i];// size of input of string 2
    cout << longest_subseq(str1, str2, m, n);// calling function which returns the no. of longest common sub sequence
}
