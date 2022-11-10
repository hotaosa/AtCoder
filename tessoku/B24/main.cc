#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> int lis(vector<T> vec) {
  vector<T> dp;
  for (auto x : vec) {
    auto itr = lower_bound(dp.begin(), dp.end(), x);
    if (itr == dp.end()) dp.push_back(x);
    else *itr = x;
  }
  return dp.size();
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (x[i] != x[j]) return x[i] < x[j];
    return y[i] > y[j];
  });

  vector<int> v;
  for (auto i : order) v.push_back(y[i]);
  cout << lis(v) << endl;


  return 0;
}