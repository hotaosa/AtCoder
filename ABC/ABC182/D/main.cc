#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

void print(vector<long long> v) {
  for (auto a : v) cout << a << " ";
  cout << endl;  
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  auto sum = a;
  for (int i = 1; i < n; ++i) sum[i] += sum[i - 1];
  auto mx = sum;
  for (int i = 1; i < n; ++i) mx[i] = max(mx[i], mx[i - 1]);  

  long long cur = a[0], res = max(0LL, a[0]);
  for (int i = 1; i < n; ++i) {
    res = max(res, cur + mx[i]);
    cur += sum[i];    
  }
  cout << res << endl;  
  return 0;
}
