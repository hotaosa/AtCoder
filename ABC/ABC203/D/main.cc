#include <iostream>
#include <vector>

bool judge(const std::vector<std::vector<int> > &b, int k) {
  int n = (int)b.size();
  std::vector<std::vector<int> > tot1(n, std::vector<int>(n, 0));
  std::vector<std::vector<int> > tot2(n, std::vector<int>(n, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j > 0) tot1[i][j] = tot1[i][j - 1];
      tot1[i][j] += b[i][j];
    }
  }

  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      if (i > 0) tot2[i][j] = tot2[i - 1][j];
      tot2[i][j] += tot1[i][j];
    }
  }

  for (int i = k - 1; i < n; ++i) {
    for (int j = k - 1; j < n; ++j) {
      int cnt = tot2[i][j];
      if (i > k - 1) {
        if (j > k - 1) {
          cnt -= tot2[i - k][j];
          cnt -= tot2[i][j - k];
          cnt += tot2[i - k][j - k];
        } else {
          cnt -= tot2[i - k][j];
        }
      } else if (j > k - 1) {
        cnt -= tot2[i][j - k];        
      }
      if (cnt < k * k / 2 + 1) return true;
    }
  }
  return false;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int> > a(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) std::cin >> a[i][j];

  int left = -1, right = 1000000001;
  while (right - left > 1) {
    int mid = (right + left) / 2;
    std::vector<std::vector<int> > b(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        b[i][j] = (a[i][j] >= mid ? 1 : 0);
      }
    }
    if (judge(b, k)) right = mid;
    else left = mid;
  }

  std::cout << left << std::endl;
  return 0;
}
