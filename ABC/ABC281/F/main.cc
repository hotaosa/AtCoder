#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int func(vector<int> vec, int shift) {
  if (shift < 0) return 0;
  vector<int> v0, v1;
  for (auto a : vec) {
    if (a & (1 << shift)) v1.push_back(a);
    else v0.push_back(a);
  }
  if (v0.empty()) {
    return func(v1, shift - 1);
  }
  if (v1.empty()) {
    return func(v0, shift - 1);
  }
  return min(func(v1, shift - 1), func(v0, shift - 1)) + (1 << shift);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  cout << func(a, 30) << endl;  
  return 0;
}
