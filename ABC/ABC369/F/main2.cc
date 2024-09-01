#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
  return a.first <= b.first && a.second <= b.second;
}

template <class T>
T LIS(const T &container) {
  T result{};
  vector<int> pos(size(container));
  vector<int> prev(size(container), -1);
  vector<int> lis_indices;

  for (size_t i = 0; i < size(container); ++i) {
    const auto it =
        lower_bound(begin(result), end(result), container[i], Compare);

    const int idx = distance(begin(result), it);
    if (it == end(result)) {
      result.emplace_back(container[i]);
      lis_indices.emplace_back(i);
    } else {
      *it = container[i];
      lis_indices[idx] = i;
    }
    pos[i] = (idx > 0) ? lis_indices[idx - 1] : -1;
  }

  T lis{};
  for (int i = lis_indices.back(); i >= 0; i = pos[i]) {
    lis.emplace_back(container[i]);
  }
  reverse(begin(lis), end(lis));
  return lis;
}

string PathString(pair<int, int> pv, pair<int, int> nx) {
  int dr = nx.first - pv.first, dc = nx.second - pv.second;
  return string(dr, 'D') + string(dc, 'R');
}

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  vector<pair<int, int>> vp = {{1, 1}, {h, w}};
  for (int i = 0; i < n; ++i) {
    int r, c;
    cin >> r >> c;
    vp.emplace_back(r, c);
  }
  sort(begin(vp), end(vp));

  auto lis = LIS(vp);
  string path_string = "";
  for (size_t i = 1; i < size(lis); ++i) {
    path_string += PathString(lis[i - 1], lis[i]);
  }

  cout << size(lis) - 2 << endl << path_string << endl;
  return 0;
}