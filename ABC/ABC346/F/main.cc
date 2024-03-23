#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n;
  string s, t;
  cin >> n >> s >> t;

  int ls = size(s);
  vector<vector<int>> pos(26);
  for (int i = 0; i < ls; ++i) {
    pos[s[i] - 'a'].emplace_back(i);
  }

  auto NextPos = [&](ll prev_pos, int c, ll k) -> ll {
    if (k == 0) return prev_pos;
    if (pos[c].empty()) return 1LL << 60;

    ll buff = prev_pos / ls * ls;
    auto p = lower_bound(begin(pos[c]), end(pos[c]), prev_pos % ls);
    ll cnt = end(pos[c]) - p;
    if (cnt >= k) {
      return buff + *(p + k - 1) + 1;
    }

    k -= cnt + 1;
    prev_pos = buff + (1 + k / size(pos[c])) * ls;
    return prev_pos + pos[c][k % size(pos[c])] + 1;
  };

  auto Judge = [&](ll k) -> bool {
    ll cur_pos = 0;
    for (auto c : t) {
      cur_pos = NextPos(cur_pos, c - 'a', k);
      if (cur_pos > n * ls) return false;
    }
    return true;
  };

  ll l = 0, r = 1LL << 60;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    (Judge(m) ? l : r) = m;
  }

  cout << l << endl;
  return 0;
}