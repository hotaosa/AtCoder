#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  const int sq = max(1, int(n / sqrt(q)));
  vector<int> c(n);
  for (auto &p : c) { cin >> p; --p; }
  vector<int> l(q), r(q);
  for (int i = 0; i < q; ++i) { cin >> l[i] >> r[i]; --l[i]; }
  vector<int> qi(q);
  for (int i = 0; i < q; ++i) qi[i] = i;
  sort(qi.begin(), qi.end(), [&](int i, int j) {
    if (l[i] / sq != l[j] / sq) return l[i] < l[j];
    else if (l[i] / sq & 1) return r[i] > r[j];
    else return r[i] < r[j];
  });
  vector<int> cnt(n, 0), res(q);
  int cur = 0, nl = 0, nr = 0;

  auto add = [&](int id) -> void { if (++cnt[c[id]] == 1) ++cur; };
  auto del = [&](int id) -> void { if (--cnt[c[id]] == 0) --cur; };

  for (int i : qi) {
    while (nl > l[i]) add(--nl);
    while (nr < r[i]) add(nr++);
    while (nl < l[i]) del(nl++);
    while (nr > r[i]) del(--nr);
    res[i] = cur;
  }
  for (auto &p : res) cout << p << endl;
  return 0;
}
