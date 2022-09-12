#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() < 5) {
    sort(s.begin(), s.end());
    do {
      if (stoi(s) % 8 == 0) {
        cout << "Yes" << endl;
        return 0;
      }
    } while (next_permutation(s.begin(), s.end()));
    cout << "No" << endl;
    return 0;
  }

  vector<int> cnt(10, 0);
  for (auto c : s) ++cnt[c - '0'];
  for (int i = 104; i < 1000; i += 8) {
    vector<int> need(10, 0);
    string str = to_string(i);
    for (auto c : str) ++need[c - '0'];
    bool ok = true;
    for (int i = 0; i < 10; ++i) ok &= cnt[i] >= need[i];
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;  
  return 0;
}
