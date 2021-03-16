#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

/*vector<ll> longest_subseq(ll str1[], ll str2[], ll m, ll n)
{
    vector<ll>v;
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
            {
                temp[i][j] = 1 + temp[i - 1][j - 1];// taking diagonal +1 elements
                v.push_back(str2[i-1]);
            }
            else
                temp[i][j] = max(temp[i-1][j-1],max(temp[i - 1][j], temp[i][j - 1]));// taking maximum of three

        }
    }
      for(ll i=0;i<=m;i++)
      {
          for(ll j=0;j<=n;j++)
          {
              cout<<temp[i][j]<<" "; // this is only for checking purpose
          }
          cout<<endl;
      }
    return (v);// returning the index of last elemnt of temp
}

ll longest(ll str1[], vector<ll>str2, ll m, ll n)
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
            {
                temp[i][j] = 1 + temp[i - 1][j - 1];// taking diagonal +1 elements

            }
            else
                temp[i][j] = max(temp[i-1][j-1],max(temp[i - 1][j], temp[i][j - 1]));// taking maximum of three

        }
    }
     for(ll i=0;i<=m;i++)
      {
          for(ll j=0;j<=n;j++)
          {
              cout<<temp[i][j]<<" "; // this is only for checking purpose
          }
          cout<<endl;
      }
    return (temp[m][n]);// returning the index of last elemnt of temp
}
*/


ll lcs(ll s1[],ll s2[],ll s3[],ll p,ll q,ll r)
{
	ll dp[p+1][q+1][r+1]={0};
	
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=p;i++)
	{
		for(ll j=1;j<=q;j++)
		{
			for(ll k=1;k<=r;k++)
			{
				if((s1[i-1]==s2[j-1])&&(s2[j-1]==s3[k-1])&&(s1[i-1]==s3[k-1]))
				{
					dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
				}
				else if(s1[i-1]==s2[j-1])
				{
					dp[i][j][k] = max( dp[i-1][j-1][k-1] , max(dp[i-1][j-1][k],dp[i][j][k-1]));
				}
				else if(s2[j-1]==s3[k-1])
				{
					dp[i][j][k] = max( dp[i-1][j-1][k-1] , max(dp[i][j-1][k-1],dp[i-1][j][k]));
				}
				else if(s1[i-1]==s3[k-1])
				{
					dp[i][j][k] = max( dp[i-1][j-1][k-1] , max(dp[i-1][j][k-1],dp[i][j-1][k]));
				}
				else
				{
					dp[i][j][k] = max(max(dp[i-1][j-1][k-1],
								max(dp[i-1][j-1][k],dp[i][j][k-1])),
								max(max(dp[i][j-1][k-1],dp[i-1][j][k]),
								 max(dp[i-1][j][k-1],dp[i][j-1][k])));
				}
			}
		}
	}
	
	return dp[p][q][r];
}

int main()
{
    ll n, m,p;
    cin >> n;// size of string 1
    ll str1[n];
    for (ll i = 0; i < n; i++)
        cin >> str1[i];  // taking input of string 1

    cin >> m;// size of string 2

    ll str2[m];
    for (ll i = 0; i < m; i++)
        cin >> str2[i];// size of input of string 2

    cin>>p;

    ll str3[p];
    for(ll i=0; i<p; i++)
        cin>>str3[i];
   // vector<ll>v= longest_subseq(str1, str2, m, n);// calling function which returns the no. of longest common sub sequence
   // cout<<longest(str3,v,v.size(),p)<<endl;
    
    cout<<lcs(str1,str2,str3,n,m,p)<<endl;
}

