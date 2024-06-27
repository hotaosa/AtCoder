#include <iostream>
#include <stack>
#include <tuple>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  stack<tuple<ll, int, ll>> st;
  st.emplace(1LL << 60, -1, 1LL);
  for (int i = 0; i < n; ++i) {
    ll h;
    cin >> h;
    while (get<0>(st.top()) <= h) st.pop();
    auto [prev_h, idx, prev_res] = st.top();
    ll res = prev_res + h * (i - idx);
    cout << res << " ";
    st.emplace(h, i, res);
  }
  cout << endl;

  return 0;
}