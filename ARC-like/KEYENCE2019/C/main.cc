#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;

  long long res = 0, less = 0;
  vector<long long> vec_stock;
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      vec_stock.push_back(a[i] - b[i]);
    } else if (a[i] < b[i]) {
      ++res;
      less += b[i] - a[i];
    }
  }

  sort(vec_stock.begin(), vec_stock.end());
  while (less > 0) {
    if (vec_stock.empty()) { cout << "-1" << endl; return 0; }
    less -= vec_stock.back();
    ++res;
    vec_stock.pop_back();
  }
  cout << res << endl;
  return 0;  
}