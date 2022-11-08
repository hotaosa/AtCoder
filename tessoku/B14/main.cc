#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int n1 = n / 2;
  int n2 = (n + 1) / 2;

  vector<int> a1(n1), a2(n2);
  for (auto &p : a1) cin >> p;
  for (auto &p : a2) cin >> p;

  set<int> se;  
  for (int bit = 0; bit < (1 << n1); ++bit) {
    int sum = 0;
    for (int i = 0; i < n1; ++i) if (bit & (1 << i)) sum += a1[i];
    se.insert(sum);
  }

  bool exist = false;
  for (int bit = 0; bit < (1 << n2); ++bit) {
    int sum = 0;
    for (int i = 0; i < n2; ++i) if (bit & (1 << i)) sum += a2[i];
    exist |= se.count(k - sum);
  }

  cout << (exist ? "Yes" : "No") << endl;
  return 0;
}
