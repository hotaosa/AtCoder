#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Job {
  int d, c;
  long long s;
  Job(int d_, int c_, long long s_) : d(d_), c(c_), s(s_) { }
  bool operator<(const Job &other) const {
    if (d != other.d) return d < other.d;
    else return c > other.c;
  }
};

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<Job> vj;
  int siz = 0;
  for (int i = 0; i < n; ++i) {
    int d, c;
    long long s;
    cin >> d >> c >> s;
    chmax(siz, d);
    vj.emplace_back(d, c, s);
  }
  sort(vj.begin(), vj.end());
  
  vector<vector<long long> > dp(n + 1, vector<long long>(++siz, 0));
  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < siz; ++j) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j + vj[i].c <= vj[i].d) {
        chmax(dp[i + 1][j + vj[i].c], dp[i][j] + vj[i].s);
        chmax(res, dp[i + 1][j + vj[i].c]);
      }
    }
  }
  cout << res << endl;  
  return 0;
}
