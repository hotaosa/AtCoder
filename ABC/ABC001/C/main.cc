#include <iostream>
#include <string>

int main() {
  int deg;
  double dis;
  std::cin >> deg >> dis;

  std::string dir;
  if (deg < 113 || deg > 3487) dir = "N";
  else if (deg < 338) dir = "NNE";
  else if (deg < 563) dir = "NE";
  else if (deg < 788) dir = "ENE";
  else if (deg < 1013) dir = "E";
  else if (deg < 1238) dir = "ESE";
  else if (deg < 1463) dir = "SE";
  else if (deg < 1688) dir = "SSE";
  else if (deg < 1913) dir = "S";
  else if (deg < 2138) dir = "SSW";
  else if (deg < 2363) dir = "SW";
  else if (deg < 2588) dir = "WSW";
  else if (deg < 2813) dir = "W";
  else if (deg < 3038) dir = "WNW";
  else if (deg < 3263) dir = "NW";
  else dir = "NNW";

  dis /= 60.0;
  int w;
  if (dis < 0.25) w = 0;
  else if (dis < 1.55) w = 1;
  else if (dis < 3.35) w = 2;
  else if (dis < 5.45) w = 3;
  else if (dis < 7.95) w = 4;
  else if (dis < 10.75) w = 5;
  else if (dis < 13.85) w = 6;
  else if (dis < 17.15) w = 7;
  else if (dis < 20.75) w = 8;
  else if (dis < 24.45) w = 9;
  else if (dis < 28.45) w = 10;
  else if (dis < 32.65) w = 11;
  else w = 12;

  if (w == 0) dir = "C";
  std::cout << dir << " " << w << std::endl;
  return 0;
}
