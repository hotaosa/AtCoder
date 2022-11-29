#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &p : a) cin >> p;

  int g = 0;
  for (auto ai : a) g = __gcd(g, ai);
  
  int res = 0;
  for (auto &ai : a) {
    ai /= g;
    while (ai % 2 == 0) {
      ++res;
      ai /= 2;
    }
    while (ai % 3 == 0) {
      ++res;
      ai /= 3;
    }
    if (ai > 1) {
      cout << "-1" << endl;
      return 0;
    }
  }

  cout << res << endl;  
  return 0;
}
