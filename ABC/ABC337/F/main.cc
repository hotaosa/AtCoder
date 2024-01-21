#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  long long k;
  cin >> n >> m >> k;

  vector<int> color(n);
  vector<long long> cnt_sum(n, 0);
  for (auto &e : color) {
    cin >> e;
    ++cnt_sum[--e];
  }

  vector<long long> cnt_ball(n, 0);
  int cnt_used_box = 0;
  long long res = 0;

  auto Count = [&](int c) -> long long {
    return min((cnt_ball[c] + k - 1) / k * k, cnt_sum[c]);
  };
  auto Add = [&](int c) {
    res -= Count(c);
    if (++cnt_ball[c] % k == 1 || k == 1) {
      ++cnt_used_box;
    }
    res += Count(c);
  };
  auto Remove = [&](int c) {
    res -= Count(c);
    if (--cnt_ball[c] % k == 0) {
      --cnt_used_box;
    }
    res += Count(c);
  };

  int ridx = 0;
  while (cnt_used_box < m && ridx < n) {
    Add(color[ridx++]);
  }

  if (ridx == n) {
    for (int i = 0; i < n; ++i) {
      cout << n << endl;
    }
    return 0;
  }

  cout << res << endl;
  for (int i = 0; i < n - 1; ++i) {
    Remove(color[i]);
    while (cnt_used_box < m) {
      Add(color[ridx++ % n]);
    }
    cout << res << endl;
  }

  return 0;
}