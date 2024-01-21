#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template<class T>
vector<vector<T> > Transpose(const vector<vector<T> > &v) {
  int h = v.size(), w = v[0].size();
  vector ret(w, vector<T>(h));
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      ret[c][r] = v[r][c];
    }
  }
  return ret;
}

template<class T>
vector<T> SlideSum(const vector<T> &v, int k) {
  vector<T> ret;
  if ((int)v.size() >= k) {
    T cur = accumulate(v.begin(), v.begin() + k, T{0});
    ret.emplace_back(cur);
    for (int i = k; i < (int)v.size(); ++i) {
      cur += v[i] - v[i - k];
      ret.emplace_back(cur);
    }
  }
  return ret;
}

template<class T>
T Solve(const vector<vector<T> > &vv, int k) {
  T ret = numeric_limits<T>::max();
  for (const auto &v : vv) {
    auto ss = SlideSum(v, k);
    if (!ss.empty()) {
      ret = min(ret, *min_element(ss.begin(), ss.end()));
    }
  }
  return ret;
}

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  const long long INF = k + 1;

  vector s(h, vector<long long>(w, 0));
  for (int i = 0; i < h; ++i) {
    string str;
    cin >> str;
    for (int j = 0; j < w; ++j) {
      if (str[j] == 'x') {
        s[i][j] = INF;
      } else if (str[j] == '.') {
        s[i][j] = 1;
      }
    }
  }

  long long res = min(Solve(s, k), Solve(Transpose(s), k));
  cout << (res < INF ? res : -1) << endl;

  return 0;
}