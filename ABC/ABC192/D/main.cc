#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string x;
  long long M;
  cin >> x >> M;

  if (x.size() == 1 && stoll(x) <= M) {
    cout << "1" << endl;
    return 0;
  }

  __int128_t m(M);

  auto judge = [&](long long k) -> bool {
    __int128_t y = 0;
    for (auto c : x) {
      y *= k;
      y += c - '0';
      if (y > m) return false;
    }
    return true;
  };

  int mx = 0;
  for (auto c : x) mx = max(mx, c - '0');

  long long l = mx, r = m + 1;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (judge(mid)) l = mid;
    else r = mid;
  }

  cout << l - mx << endl;
  return 0;
}
