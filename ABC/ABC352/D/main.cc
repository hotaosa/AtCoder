#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
vector<T> SlideMin(const vector<T> &v, const int &k) {
  vector<T> ret;
  deque<T> dq;
  for (int i = 0; i < (int)v.size(); ++i) {
    while (!dq.empty() && v[dq.back()] >= v[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() == i - k) dq.pop_front();
    if (i >= k - 1) ret.push_back(v[dq.front()]);
  }
  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    p[--x] = i;
  }
  auto mp = p;
  for_each(begin(mp), end(mp), [](auto &x) { x = -x; });

  auto slide_min = SlideMin(p, k);
  auto slide_max = SlideMin(mp, k);
  for_each(begin(slide_max), end(slide_max), [](auto &x) { x = -x; });

  int res = n;
  for (int i = 0; i < (int)size(slide_min); ++i) {
    res = min(res, slide_max[i] - slide_min[i]);
  }

  cout << res << endl;
  return 0;
}