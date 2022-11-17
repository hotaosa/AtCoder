#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> cnt(100, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++cnt[a % 100];
  }

  long long res = cnt[0] * (cnt[0] - 1) / 2;
  for (int i = 1; i < 50; ++i) res += cnt[i] * cnt[100 - i];
  res += cnt[50] * (cnt[50] - 1) / 2;

  cout << res << endl;  
  return 0;
}
