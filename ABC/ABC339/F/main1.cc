// boost::multiprecision

#include <iostream>
#include <map>
#include <vector>
//
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using cpp_int = boost::multiprecision::cpp_int;

int main() {
  int n;
  cin >> n;
  map<cpp_int, int> mp;
  vector<cpp_int> a(n);
  for (auto &e : a) {
    cin >> e;
    ++mp[e];
  }

  sort(a.begin(), a.end());
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      auto mul = a[i] * a[j];
      if (mul > a.back()) {
        break;
      }
      if (mp.count(mul)) {
        res += mp[mul] * (i == j ? 1 : 2);
      }
    }
  }

  cout << res << endl;
  return 0;
}