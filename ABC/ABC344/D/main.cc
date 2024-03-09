#include <iostream>
#include <vector>

using namespace std;
constexpr int INF = 1 << 30;

template <class T>
inline bool ChangeMin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  string t;
  int n;
  cin >> t >> n;

  vector<int> dp(t.size() + 1, INF);
  dp[0] = 0;

  while (n--) {
    auto d = dp;
    int a;
    cin >> a;
    while (a--) {
      string s;
      cin >> s;
      for (int i = 0; i <= int(t.size() - s.size()); ++i) {
        if (t.substr(i, s.size()) == s) {
          ChangeMin(dp[i + s.size()], d[i] + 1);
        }
      }
    }
  }

  cout << (dp.back() < INF ? dp.back() : -1) << endl;
  return 0;
}