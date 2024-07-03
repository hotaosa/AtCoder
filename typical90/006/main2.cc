#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  set<pair<char, int>> se;
  for (int i = 0; i < n - k; ++i) se.emplace(s[i], i);

  int prev_idx = -1;
  string res = "";
  for (int i = n - k; i < n; ++i) {
    se.emplace(s[i], i);
    auto it = begin(se);
    while (it->second < prev_idx) ++it;
    res += it->first;
    prev_idx = it->second;
    se.erase(begin(se), next(it));
  }

  cout << res << endl;
  return 0;
}