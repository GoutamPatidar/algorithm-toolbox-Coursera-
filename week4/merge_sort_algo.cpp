#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void merge(vector<ll> &v, ll l, ll mid, ll h)//merging two sorted array
{
  ll n1 = mid - l + 1;
  ll n2 = h - mid;
  ll ar[n1], arr[n2];
  ll i=0;
  ll j=0;
  for ( i = 0; i < n1; i++)
    ar[i] = v[l + i];
  for (j = 0; j < n2; j++)
    arr[j] = v[mid + 1 + j];
  ll k = l;
  i=0;
  j=0;
  while (i < n1 && j < n2)
  {
    if (ar[i] <= arr[j])//comparing elements in both array and updating in main array
    {
      v[k] = ar[i];
      i++;
    }
    else
    {
      v[k] = arr[j];
      j++;
    }
    k++;
  }
  while(i<n1)//coping remaining element
  {
    v[k]=ar[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    v[k]=arr[j];
    j++;
    k++;
  }
}

void mergesort(vector<ll> &v, ll l, ll h)// mergesort function with recurssive call

{
  if (l < h)
  {
    ll mid = l + (h - l) / 2;
    mergesort(v, l, mid);
    mergesort(v, mid + 1, h);

    merge(v, l, mid, h);
  }
}
int main()
{
  ll n;
  cin >> n;//size of array
  vector<ll> v(n);
  for (ll i = 0; i < n; i++)
    cin >> v[i];// elements in array
  mergesort(v, 0, (v.size()-1));// calling merge sort
  for (ll i = 0; i < n; i++)
    cout << v[i] << " ";//printing sorted array
}
