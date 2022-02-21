#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  const int SIZ = b + d + 1;

  vector<bool> is_prime(SIZ, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= SIZ; ++i) {
    if (!is_prime[i]) continue;
    for (int j = i * 2; j < SIZ; j += i) is_prime[j] = false;
  }

  for (int i = a; i <= b; ++i) {
    bool found = false;
    for (int j = c; j <= d; ++j) {
      if (is_prime[i + j]) found = true;
    }
    if (!found) { cout << "Takahashi" << endl; return 0; }
  }
  cout << "Aoki" << endl;
  return 0;
}
