#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;

  vector<int> dp_l(n, 0), dp_r(n, 0);
  if (s[0] == 'o') dp_l[0] = 1;
  for (int i = 1; i < n; ++i) {
    dp_l[i] = dp_l[i - 1];
    if (i > c && s[i] == 'o') chmax(dp_l[i], dp_l[i - c - 1] + 1);
  }
  if (s[n - 1] == 'o') dp_r[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    dp_r[i] = dp_r[i + 1];
    if (i + c + 1 < n && s[i] == 'o') chmax(dp_r[i], dp_r[i + c + 1] + 1);
  }
  if (dp_r[0] > k) return 0;

  vector<int> vec_l, vec_r;
  if (dp_l[0] == 1) vec_l.push_back(0);
  if (dp_r[n - 1] == 1) vec_r.push_back(n - 1);

  for (int i = 1; i < n; ++i) if (dp_l[i] > dp_l[i - 1]) vec_l.push_back(i);
  for (int i = n - 2; i >= 0; --i) if (dp_r[i] > dp_r[i + 1]) vec_r.push_back(i);
  reverse(vec_r.begin(), vec_r.end());
  for (int i = 0; i < k; ++i) if (vec_l[i] == vec_r[i]) cout << vec_l[i] + 1 << endl;
  return 0;
}
