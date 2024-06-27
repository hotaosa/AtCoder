#include <iostream>
#include <map>
#include <vector>
//
#include <atcoder/segtree>

using namespace std;
using ll = long long;

int Operate(int a, int b) { return max(a, b); }
int E() { return 0; }
using Segtree = atcoder::segtree<int, Operate, E>;

template <class T>
int Compression(vector<T> &v) {
  map<T, int> mp;
  int siz = 0;
  for (auto &x : v) mp[x] = 0;
  for (auto &[x, idx] : mp) idx = siz++;
  for (auto &x : v) x = mp[x];
  return siz;
}

int main() {
  int n;
  cin >> n;
  vector<ll> h(n + 1, -1);
  for (int i = 1; i <= n; ++i) cin >> h[i];
  for (auto &e : h) cin >> e;

  auto ch = h;
  const int siz = Compression(ch);

  Segtree seg(siz);
  vector<ll> res(n + 1);
  res[0] = 1;

  for (int i = 1; i <= n; ++i) {
    int idx = seg.prod(ch[i], siz);
    res[i] = res[idx] + (i - idx) * h[i];
    seg.set(ch[i], i);
  }

  for (int i = 1; i <= n; ++i) {
    cout << res[i] << endl;
  }

  return 0;
}
