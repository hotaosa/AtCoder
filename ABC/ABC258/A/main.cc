#include <iostream>

using namespace std;

int main() {
  int k;
  cin >> k;
  printf("%d:%02d\n", 21 + k / 60, k % 60);
  return 0;
}