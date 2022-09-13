#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  double a, b;
  cin >> a >> b;
  double res = a / 100. * b;
  printf("%.10f\n", res);  
  return 0;
}
