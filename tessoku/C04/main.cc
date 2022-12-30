#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<long long> div;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i > 0) continue;
    div.push_back(i);
    if (i * i < n) div.push_back(n / i);
  }

  sort(div.begin(), div.end());
  for (auto res : div) cout << res << endl;  
  return 0;
}
