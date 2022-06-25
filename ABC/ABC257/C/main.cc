#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> child, adult;
  for (int i = 0; i < n; ++i) {
    int w;
    cin >> w;
    if (s[i] == '0') child.push_back(w);
    else adult.push_back(w);
  }
  sort(child.begin(), child.end());
  sort(adult.begin(), adult.end());

  auto calc = [&](int k) -> int {
    int ret = lower_bound(child.begin(), child.end(), k) - child.begin();
    ret += adult.end() - lower_bound(adult.begin(), adult.end(), k);
    return ret;
  };

  int res = max(calc(0), calc(1000000001));
  for (auto w : child) res = max(res, calc(w + 1));
  for (auto w : adult) res = max(res, calc(w));
  cout << res << endl;  
  return 0;
}