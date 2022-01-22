#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

void prime_factorization(vector<int> &prime_factor, int num) {
  for (int i = 2; i * i <= num; ++i) {
    while (num % i == 0) { ++prime_factor[i]; num /= i; }
  }
  if (num > 1) ++prime_factor[num];
}

int main() {
  int n;
  cin >> n;

vector<int> prime_factor(n + 1, 0);
  for (int i = 2; i <= n; ++i) prime_factorization(prime_factor, i);

  int res = 0;
  for (int i = 2; i <= n; ++i) if (prime_factor[i] >= 74) ++res;
  for (int i = 2; i <= n; ++i) for (int j = 2; j <= n; ++j) if (i != j && prime_factor[i] >= 14 && prime_factor[j] >= 4) ++res;
  for (int i = 2; i <= n; ++i) for (int j = 2; j <= n; ++j) if (i != j && prime_factor[i] >= 2 && prime_factor[j] >= 24) ++res;
  for (int i = 2; i <= n; ++i) for (int j = 2; j < n; ++j) for (int k = j + 1; k <= n; ++k) if (i != j && i != k && prime_factor[i] >= 2 && prime_factor[j] >= 4 && prime_factor[k] >= 4) ++res;
  cout << res << endl;  
  return 0;
}