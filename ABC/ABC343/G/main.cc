#include <algorithm>
#include <iostream>
#include <vector>
//
#include <atcoder/string>

using namespace std;

template <class T>
inline bool ChangeMin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

bool Contain(const string &s, const string &t) {
  // return t is contained in s
  const int m = size(t);
  const auto z = atcoder::z_algorithm(t + s);
  return *max_element(begin(z) + m, end(z)) >= m;
}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto &e : s) cin >> e;
  sort(begin(s), end(s), [](string a, string b) { return size(a) < size(b); });

  vector<string> t;
  for (int i = 0; i < n; ++i) {
    bool is_unique = true;
    for (int j = i + 1; j < n && is_unique; ++j) {
      is_unique &= !Contain(s[j], s[i]);
    }
    if (is_unique) {
      t.emplace_back(s[i]);
    }
  }

  n = size(t);
  vector gain(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      auto z = atcoder::z_algorithm(t[j] + t[i]);
      for (int k = size(t[j]); k < (int)size(z); ++k) {
        if (k + z[k] == (int)size(z)) {
          gain[i][j] = z[k];
          break;
        }
      }
    }
  }

  vector dp(1 << n, vector<int>(n, 1 << 30));
  for (int i = 0; i < n; ++i) dp[1 << i][i] = size(t[i]);

  for (int b = 1; b < (1 << n); ++b) {
    for (int i = 0; i < n; ++i) {
      if (!(b >> i) & 1) continue;
      for (int j = 0; j < n; ++j) {
        if ((b >> j) & 1) continue;
        int nb = b | (1 << j);
        ChangeMin(dp[nb][j], dp[b][i] + (int)size(t[j]) - gain[i][j]);
      }
    }
  }

  cout << *min_element(begin(dp.back()), end(dp.back())) << endl;
  return 0;
}