#include <iostream>

int main() {
  int s;
  std::cin >> s;

  bool yymm = true, mmyy = true;
  if (s / 100 < 1) mmyy = false;
  if (s / 100 > 12) mmyy = false;
  if (s % 100 < 1) yymm = false;
  if (s % 100 > 12) yymm = false;
  

  if (yymm && mmyy) std::cout << "AMBIGUOUS" << std::endl;
  else if (yymm) std::cout << "YYMM" << std::endl;
  else if (mmyy) std::cout << "MMYY" << std::endl;
  else std::cout << "NA" << std::endl;
  return 0;
}
