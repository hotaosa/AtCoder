#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  const vector<long long> v = {4, 5, 7, 9, 11, 13, 17, 19, 23};
  vector<long long> sum = {0};
  for (auto x : v) {
    sum.push_back(sum.back() + x);
  }

  const long long m = accumulate(v.begin(), v.end(), 0);
  cout << m << endl;

  vector<long long> a(m);
  int l = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    for (int j = 0; j < v[i]; ++j) {
      a[l + j] = l + (j + 1) % v[i];
    }
    l += v[i];
  }
  for (auto ai : a) cout << ai + 1 << " ";
  cout << endl;

  vector<long long> b(m);
  for (auto &p : b) {
    cin >> p;
    assert(p != -1);
    --p;
  }

  vector<long long> mod(v.size());
  for (int i = 0; i < (int)v.size(); ++i) {
    mod[i] = b[sum[i]] - sum[i];
    assert(mod[i] < v[i]);
  }  

  auto c = atcoder::crt(mod, v);
  cout << c.first << endl;  
  return 0;
}
