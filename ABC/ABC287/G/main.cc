#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long op(long long a, long long b) {
  return a + b;
}
long long e() {
  return 0;
}

using segtree = atcoder::segtree<long long, op, e>;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n), v;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    v.push_back(a[i]);
  }

  int q;
  cin >> q;
  vector<int> t(q);
  vector<long long> x(q), y(q, -1);
  for (int i = 0; i < q; ++i) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> x[i] >> y[i];
      --x[i];
      v.push_back(y[i]);
    } else if (t[i] == 2) {
      cin >> x[i] >> y[i];
      --x[i];
    } else {
      cin >> x[i];
    }
  }

  sort(v.rbegin(), v.rend());
  v.erase(unique(v.begin(), v.end()), v.end());

  map<long long, long long> mp;
  int siz = v.size();
  for (int i = 0; i < siz; ++i) mp[v[i]] = i;

  segtree sum(siz), cnt(siz);
  for (int i = 0; i < n; ++i) {
    sum.set(mp[a[i]], sum.get(mp[a[i]]) + a[i] * b[i]);
    cnt.set(mp[a[i]], cnt.get(mp[a[i]]) + b[i]);
  }

  auto Solve = [&](long long k) -> long long {
    if (cnt.all_prod() < k) return -1;
    if (cnt.all_prod() == k) return sum.all_prod();
    if (cnt.get(0) >= k) return sum.get(0) / cnt.get(0) * k;
    int l = 1, r = siz;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (cnt.prod(0, m) > k) r = m;
      else l = m;
    }
    long long ret = sum.prod(0, l);
    ret += sum.get(l) / cnt.get(l) * (k - cnt.prod(0, l));
    return ret;
  };

  for (int i = 0; i < q; ++i) {
    if (t[i] == 1) {
      sum.set(mp[a[x[i]]], sum.get(mp[a[x[i]]]) - a[x[i]] * b[x[i]]);
      cnt.set(mp[a[x[i]]], cnt.get(mp[a[x[i]]]) - b[x[i]]);
      a[x[i]] = y[i];
      sum.set(mp[a[x[i]]], sum.get(mp[a[x[i]]]) + a[x[i]] * b[x[i]]);
      cnt.set(mp[a[x[i]]], cnt.get(mp[a[x[i]]]) + b[x[i]]);
    } else if (t[i] == 2) {
      sum.set(mp[a[x[i]]], sum.get(mp[a[x[i]]]) - a[x[i]] * b[x[i]]);
      cnt.set(mp[a[x[i]]], cnt.get(mp[a[x[i]]]) - b[x[i]]);
      b[x[i]] = y[i];
      sum.set(mp[a[x[i]]], sum.get(mp[a[x[i]]]) + a[x[i]] * b[x[i]]);
      cnt.set(mp[a[x[i]]], cnt.get(mp[a[x[i]]]) + b[x[i]]);
    } else {
      cout << Solve(x[i]) << endl;
    }
  }
  
  return 0;
}
