#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int m = 0;
  while (1 << m < n) ++m;

  cout << m << endl;
  for (int i = 0; i < m; ++i) {
    vector<int> v;
    for (int j = 0; j < n; ++j) {
      if (j >> i & 1) v.emplace_back(j);
    }
    cout << v.size() << " ";
    for (auto vi : v) cout << vi + 1 << " ";
    cout << endl;
  }

  int res = 0;
  string s;
  cin >> s;
  for (int i = 0; i < m; ++i) {
    if (s[i] == '1') res |= 1 << i;
  }

  cout << res + 1 << endl;
  return 0;
}
