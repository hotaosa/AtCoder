#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  if (n % 2 == 0) {
    int nn = n / 2;
    vector<long long> a_even(nn), a_odd(nn);
    for (int i = 0; i < n; ++i) {
      if (i & 1) a_odd[i / 2] = a[i];
      else a_even[i / 2] = a[i];
    }
    vector<long long> sum_l(nn + 1, 0), sum_r(nn + 1, 0);
    for (int i = 0; i < nn; ++i) sum_l[i + 1] = sum_l[i] + a_even[i];
    for (int i = nn - 1; i >= 0; --i) sum_r[i] = sum_r[i + 1] + a_odd[i];    

    long long res = -(1LL << 60);
    for (int i = 0; i <= nn; ++i) {
      res = max(res, sum_l[i] + sum_r[i]);
    }
    cout << res << endl;   
  } else {
    int n_even = n / 2 + 1, n_odd = n / 2;
    vector<long long> a_even(n_even), a_odd(n_odd);
    for (int i = 0; i < n; ++i) {
      if (i & 1) a_odd[i / 2] = a[i];
      else a_even[i / 2] = a[i];
    }
    vector<long long> sum_l(n_even + 1, 0), sum_r(n_odd + 1, 0);
    for (int i = 0; i < n_even; ++i) sum_l[i + 1] = sum_l[i] + a_even[i];
    for (int i = n_odd - 1; i >= 0; --i) sum_r[i] = sum_r[i + 1] + a_odd[i];
    
    long long res = sum_r[0];
    for (int i = 0; i < n_even; ++i) res = max(res, sum_l.back() - a_even[i]);
        
    long long mx_r = a_odd.back();    
    for (int i = n_even - 3; i >= 0; --i) {
      mx_r = max(mx_r + a_odd[i], a_odd[i] + sum_l.back() - sum_l[i + 2]);
      res = max(res, sum_l[i] + mx_r);
    }
    cout << res << endl;
  }
  return 0;
}
