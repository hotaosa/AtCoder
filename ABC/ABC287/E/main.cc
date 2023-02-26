#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int Count(const string &s, const string &t) {
  int ls = s.size(), lt = t.size();
  int cnt = 0;
  for (int i = 0; i < min(ls, lt); ++i) {
    if (s[i] == t[i]) ++cnt;
    else break;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<pair<string, int> > vs;
  for (int i = 0; i < n; ++i) {
    string t;
    cin >> t;
    vs.emplace_back(t, i);
  }
  sort(vs.begin(), vs.end());

  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    if (i > 0) cnt = max(cnt, Count(vs[i].first, vs[i - 1].first));
    if (i < n - 1) cnt = max(cnt, Count(vs[i].first, vs[i + 1].first));
    res[vs[i].second] = cnt;
  }

  for (auto r : res) cout << r << endl;  
  return 0;
}
