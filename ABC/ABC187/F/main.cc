#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool> > exist_edge(n, vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    exist_edge[a][b] = true;
  }
  
  vector<int> bits(1 << n), order(1 << n);
  for (int i = 0; i < (1 << n); ++i) bits[i] = order[i] = i;
  sort(order.begin(), order.end(), [&](int i, int j) {
    return __builtin_popcount(bits[i]) > __builtin_popcount(bits[j]);
  });

  auto constractable = [&](int bit) -> bool {    
    vector<int> v_list;
    for (int i = 0; i < n; ++i) if (bit & (1 << i)) v_list.push_back(i);
    for (int i = 0; i < (int)v_list.size() - 1; ++i) {
      for (int j = i + 1; j < (int)v_list.size(); ++j) {
        if (!exist_edge[v_list[i]][v_list[j]]) return false;
      }
    }    
    return true;
  };

  auto include = [&](int a, int b) -> bool {
    for (int i = 0; i < n; ++i) {
      if (!(a & (1 << i)) && b & (1 << i)) return false;
    }
    return true;
  };  
      
  vector<int> vec;
  for (int i : order) {
    int bit = bits[i];
    bool uni = true;
    for (int v : vec) if (include(v, bit)) uni = false;
    if (uni && constractable(bit)) vec.push_back(bit);
  }
  
  vector<vector<int> > dp(vec.size() + 1, vector<int>(1 << n, n));
  dp[0][0] = 0;

  for (int i = 0; i < (int)vec.size(); ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      chmin(dp[i + 1][j], dp[i][j]);
      chmin(dp[i + 1][j | vec[i]], dp[i][j] + 1);
    }
  }

  cout << dp.back().back() << endl;
  return 0;
}
