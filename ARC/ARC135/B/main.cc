#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> s(n);
  for (auto &p : s) cin >> p;

  long long min_a = 0, min_b = 0, min_c = 0;
  long long sum_a = 0, sum_b = 0, sum_c = 0;

  for (int i = 0; i < n - 1; i += 3) {
    sum_a += s[i + 1] - s[i];
    min_a = max(min_a, -sum_a);
  }
  for (int i = 1; i < n - 1; i += 3) {
    sum_b += s[i + 1] - s[i];
    min_b = max(min_b, -sum_b);
  }
  for (int i = 2; i < n - 1; i += 3) {
    sum_c += s[i + 1] - s[i];
    min_c = max(min_c, -sum_c);
  }
  if (min_a + min_b + min_c > s[0]) {
    cout << "No" << endl;
    return 0;
  }
  min_c = s[0] - min_a - min_b;
  vector<long long> a(n + 2);
  a[0] = min_a;
  a[1] = min_b;
  a[2] = min_c;
  for (int i = 3; i < n + 2; ++i) {
    a[i] = s[i - 2] - a[i - 1] - a[i - 2];
  }
  cout << "Yes" << endl;
  for (auto &p : a) cout << p << " ";  
  cout << endl;
  return 0;
}
