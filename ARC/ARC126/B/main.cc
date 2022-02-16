#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Pair {
  int a, b;
  Pair(int a_, int b_) : a(a_), b(b_) { }
  bool operator<(const Pair &other) {
    if (a != other.a) return a < other.a;
    else return b > other.b;
  }
};

template<class T> int lis(vector<T> vec) {
  vector<T> dp;
  for (auto x : vec) {
    auto itr = lower_bound(dp.begin(), dp.end(), x);
    if (itr == dp.end()) dp.push_back(x);
    else *itr = x;
  }
  return dp.size();
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Pair> vp;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    vp.emplace_back(a, b);
  }
  sort(vp.begin(), vp.end());

  vector<int> v(m);
  for (int i = 0; i < m; ++i) v[i] = vp[i].b;
  cout << lis<int>(v) << endl;
  return 0;
}
