#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool Check(vector<int> a, vector<int> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

int Compression(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz= 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

template<class T>
int InversionNumber(const vector<T> &vec, const int &size) {
  const int n = vec.size();
  atcoder::fenwick_tree<T> ft(size);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += ft.sum(vec[i] + 1, size);
    ft.add(vec[i], 1);
  }
  return ret;
}

bool Solve(vector<int> a, vector<int> b) {
  if (!Check(a, b)) return false;

  int n = a.size(), m = Compression(a);
  Compression(b);

  if (m < n) return true;
  auto x = InversionNumber(a, m) + InversionNumber(b, m);
  return !(x & 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;

  cout << (Solve(a, b) ? "Yes" : "No" ) << endl;
  return 0;
}
