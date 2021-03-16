#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dpchange(ll value, ll coin[], ll n)
{
     ll min[value];
     min[0]=0;// putting value at 0 index as 0
     for (ll i = 1; i < value; i++)
      min[i]=INT_MAX;// putting value int max at other
    for (ll i = 0; i < n; i++)
    {
        for (ll j = coin[i]; j <= value; j++)// checking from coin postion in array
        {
            if (j >= coin[i])
            {
                  if (min[j] > (min[j - coin[i]] + 1) && min[j-coin[i]]!= INT_MAX)
                    min[j] = min[j - coin[i]]+1;// going coin[i] back in array and adding 1 in that 
            }
        }
    }
    return (min[value]);// returning value position
}

int main()
{
    ll money;
    cin >> money;
    ll coin[3] = {1, 3, 4};// giving coins
    ll c = dpchange(money, coin, 3);//calling function
    cout << c << endl;
}
