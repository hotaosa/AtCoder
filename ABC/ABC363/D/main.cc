#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  --n;

  vector<ll> pow10(19);
  pow10[0] = 1;
  for (int i = 1; i <= 18; ++i) {
    pow10[i] = pow10[i - 1] * 10;
  }

  for (int d = 1;; ++d) {
    int x = (d - 1) / 2;
    if (n <= 9 * pow10[x]) {
      string s = to_string(pow10[x] + n - 1);
      string t = s;
      if (d & 1) t.pop_back();
      reverse(begin(t), end(t));
      cout << s + t << endl;
      return 0;
    } else {
      n -= 9 * pow10[x];
    }
  }
  return 0;
}