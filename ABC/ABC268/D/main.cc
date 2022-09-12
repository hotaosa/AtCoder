#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool func(const vector<string> &vs, const set<string> &se, vector<string> &us, int remain, int s) {
  int n = vs.size();
  if (!remain) {
    string str = vs[0];
    for (int i = 0; i < n - 1; ++i) str += us[i] + vs[i + 1];
    if (!se.count(str)) {
      cout << str << endl;
      return true;
    }
    return false;
  }
  for (int i = s; i < n; ++i) {
    if (i < n - 1) us[i] += '_';
    if (func(vs, se, us, remain - 1, i)) return true;
    if (i < n - 1) us[i].pop_back();
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> vs(n);
  for (auto &p : vs) cin >> p;

  set<string> se;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    se.insert(s);
  }

  if (n == 1) {
    if (vs[0].size() >= 3 && !se.count(vs[0])) cout << vs[0] << endl;
    else cout << "-1" << endl;
    return 0;
  }

  int additional_us = 16 - n + 1;
  for (auto s : vs) additional_us -= s.size();

  sort(vs.begin(), vs.end());
  do {
    vector<string> us(n - 1, "_");
    if (func(vs, se, us, additional_us, 0)) return 0;
  } while (next_permutation(vs.begin(), vs.end()));

  cout << "-1" << endl;
  return 0;
}
