#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  long long a, b;
  cin >> a >> b;
  if (a < b) swap(a, b);

  long long res = 0;
  while (b > 0) {
    res += a / b;
    a %= b;
    swap(a, b);
  }

  cout << --res << endl;
  return 0;
}
