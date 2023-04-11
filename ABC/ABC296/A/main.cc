#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool IncludeString(const string &s, const string &t) {
  const int n = s.size(), m = t.size();
  auto z = atcoder::z_algorithm(t + "$" + s);
  for (int i = m; i < n + m; ++i) {
    if (z[i] == m) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n;
  string s;
  cin >> n >> s;
  cout << (IncludeString(s, "MM") || IncludeString(s, "FF") ? "No" : "Yes" ) << endl;
  return 0;
}
