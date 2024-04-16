#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int a, c;
    cin >> a >> c;
    if (mp.count(c)) {
      mp[c] = min(mp[c], a);
    } else {
      mp[c] = a;
    }
  }

  cout << max_element(
              begin(mp), end(mp),
              [](const auto &x, const auto &y) { return x.second < y.second; })
              ->second
       << endl;

  return 0;
}