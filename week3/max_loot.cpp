#include <bits/stdc++.h>

using namespace std;

int get_optimum_index(vector<int> weights, vector<int> values) 
{
    int max_index = 0;
    double max = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] != 0 && (double) values[i] / weights[i] > max) {
            max = (double) values[i] / weights[i];
            max_index = i;
        }
    }
    return max_index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
  double value = 0.0;

  while(capacity > 0){
  
    int optimum_index = get_optimum_index(weights, values);
    double val_per_wt = (double)values[optimum_index]/weights[optimum_index];
    
    if (val_per_wt < 0) break;

    if(weights[optimum_index] <= capacity)
    {
      value += (double)values[optimum_index];
      capacity -= weights[optimum_index];
    }
    else 
    {
      value += (double)(capacity) * val_per_wt;
      capacity -= weights[optimum_index];
    }

    values[optimum_index] = -1;
  }

  return value;
}

int main() 
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
     cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, n);

  cout << std::setprecision(4) << std::fixed;
  cout << optimal_value << std::endl;
  return 0;
}