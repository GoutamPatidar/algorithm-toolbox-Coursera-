#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll arr[3] = {10, 5, 1};
    ll n, j=0;
    cin >> n;//taking input
    while (n != 0)//checking possible conditions
    {
        if (n >= arr[0])
        {
            j++;
            n = n - arr[0];
        }
        else
        {
            if (n >= arr[1])
            {
                j++;
                n = n - arr[1];
            }
            else
            {
                j++;
                n = n - arr[2];
            }
        }
    }
    cout<<j<<endl;
}