#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long p, q, r;
  cin >> n >> p >> q >> r;
  long long sum = 0;
  set<long long> se = {0};
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    sum += a;
    se.insert(sum);
  }

  bool exist = false;
  for (auto iter = se.begin(); iter != se.end(); ++iter) {
    bool exist_cur = true;
    exist_cur &= se.count(*iter + p);
    exist_cur &= se.count(*iter + p + q);
    exist_cur &= se.count(*iter + p + q + r);
    exist |= exist_cur;
  }
  cout << (exist ? "Yes" : "No" ) << endl;
  return 0;
}
