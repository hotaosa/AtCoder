#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long LCM(long long a, long long b) {
  return a / __gcd(a, b) * b;
}

long long Solve() {
  long long n, d, k;
  cin >> n >> d >> k;
  --k;
  long long c = LCM(n, d) / d;
  return k / c + k % c * d % n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int t;
  cin >> t;
  while (t--) {
    cout << Solve() << endl;
  }
  
  return 0;
}
