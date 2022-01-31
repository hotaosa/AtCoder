#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int func(vector<int> v) {  
  int n = v.size();
  sort(v.begin(), v.end());
  if (n & 1)  return v[(n - 1) / 2];
  else return v[(n / 2) - 1] + v[n / 2];  
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

  cout << func(b) - func(a) + 1 << endl;
  return 0;  
}
