#include <iostream>

using namespace std;

int cost (int left, int right, int base) {
  left -= base;
  right -= base;
  if (left >= 0 || right <= 0) {
    return abs((left + right) * (right - left + 1) / 2);
  } else {
    left = abs(left);
    right = abs(right);
    return (left + 1) * left / 2 + (right + 1) * right / 2;
  }
}

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  
  int res = 1 << 30;  
  for (int red_right = -300 - r; red_right <= -100 + r; ++red_right) {
    int red_left = red_right - r + 1;
    for (int blue_left = 300 + b; blue_left >= 100 - b && blue_left - red_right - 1 >= g; --blue_left) {      
      int blue_right = blue_left + b - 1;
      for (int green_left = red_right + 1; green_left <= blue_left - g; ++green_left) {   
        int green_right = green_left + g - 1;
        int cur = 0;
        cur += cost(red_left, red_right, -100);
        cur += cost(blue_left, blue_right, 100);
        cur += cost(green_left, green_right, 0);
        res = min(res, cur);
      }
    }
  }  
  cout << res << endl;
  return 0;
}