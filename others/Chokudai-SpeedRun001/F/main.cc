#include <iostream>

bool chmax(int &a, int b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  std::cin >> n;
  int ma = -1;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    if (chmax(ma, a)) ++res;    
  }
  std::cout << res << std::endl;
  return 0;  
}
