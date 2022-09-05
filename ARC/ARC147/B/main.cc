#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &pp : p) cin >> pp;

  vector<int> vo, ve;
  for (int i = 0; i < n; ++i) (i & 1 ? vo : ve).push_back(--p[i]);

  vector<pair<char, int> > res;
  for (int i = 0; i < (int)vo.size(); ++i) {
    if (!(ve[i] & 1) && vo[i] & 1) continue;
    if (ve[i] & 1 && vo[i] & 1) {
      int j = i + 1;
      while (vo[j] & 1) ++j;
      while (j > i) {
        res.emplace_back('B', j * 2);
        swap(vo[j], vo[j - 1]);
        --j;
      }
    } else if (!(ve[i] & 1) && !(vo[i] & 1)) {
      int j = i + 1;
      while (!(ve[j] & 1)) ++j;
      while (j > i) {
        res.emplace_back('B', j * 2 - 1);
        swap(ve[j], ve[j - 1]);
        --j;
      }
    }
    res.emplace_back('A', i * 2 + 1);
    swap(ve[i], vo[i]);
  }

  for (int i = 0; i < (int)ve.size(); ++i) {
    int j = i;
    while (ve[j] != i * 2) ++j;
    while (j > i) {
      res.emplace_back('B', j * 2 - 1);
      swap(ve[j], ve[j - 1]);
      --j;
    }
  }
  for (int i = 0; i < (int)vo.size(); ++i) {
    int j = i;
    while (vo[j] != i * 2 + 1) ++j;
    while (j > i) {
      res.emplace_back('B', j * 2);
      swap(vo[j], vo[j - 1]);
      --j;
    }
  }

  cout << res.size() << endl;
  for (auto r : res) cout << r.first << " " << r.second << endl;    
  return 0;
}
