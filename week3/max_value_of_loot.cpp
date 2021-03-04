#include<bits/stdc++.h>

using namespace std;
int get_maxi(vector<double>&v,vector<double>&w)//it return index of max v/i...
{
    int max_i;
    double max=0;
    for(int i=0; i<v.size(); i++)
    {
        if(w[i]!=0 && v[i]/w[i]>max)
        {
            max=(double)v[i]/w[i];
            max_i=i;
        }
    }
    return max_i;
}

double max_value(vector<double>&v,vector<double>&w,double cap)//fun to calculate value
{
    double V=0;
    double a;
    for(int i=0; i<v.size(); i++)
    {
        if(cap==0)
            return V;
        int j=get_maxi(v,w);
        a=min(w[j],cap);//finding min from them
        V+=(a*(v[j]/w[j]));
        cap=cap-a;
        w[j]=w[j]-a;

    }
    return V;
}
int main()
{
    int n;
    double capacity;
    cin>>n;
    cin>>capacity;//taking no. of inputs n &bag capacity
    vector<double>v(n);
    vector<double>w(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i]>>w[i];//taking values corresponding to weight of item
    }
    double x=max_value(v,w,capacity);
    cout<<fixed<<setprecision(5)<<x<<endl;
}
