#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int cnt_one_sum = 0;
    for (auto c : s) if (c == '1') ++cnt_one_sum;

    int cnt_one = 0, cnt_free = 0;
    for (int i = 0; i < k; ++i) {
      if (s[i] == '1') ++cnt_one;
      else if (s[i] == '?') ++cnt_free;
    }

    int res = 0;
    if (cnt_one + cnt_free == k && cnt_one == cnt_one_sum) ++res;

    for (int i = k; i < n; ++i) {
      if (s[i] == '1') ++cnt_one;
      if (s[i] == '?') ++cnt_free;
      if (s[i - k] == '1') --cnt_one;
      if (s[i - k] == '?') --cnt_free;
      if (cnt_one + cnt_free == k && cnt_one == cnt_one_sum) ++res;
    }

    cout << (res == 1 ? "Yes" : "No" ) << endl;
  }
  
  return 0;
}
