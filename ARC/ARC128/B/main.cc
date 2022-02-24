#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr int INF = 1 << 30;

int func(int a, int b) {
  if (a % 3 != b % 3) return INF;
  return max(a, b);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> ball(3);
    for (auto &p : ball) cin >> p;
    int res = INF;
    res = min(res, func(ball[0], ball[1]));
    res = min(res, func(ball[1], ball[2]));
    res = min(res, func(ball[2], ball[0]));
    cout << (res < INF ? res : -1) << endl;
  }
  return 0;
}
