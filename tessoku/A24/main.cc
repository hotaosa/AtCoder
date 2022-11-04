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
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  cout << lis(a) << endl;  
  return 0;
}
