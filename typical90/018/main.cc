#include <iostream>
#include <cmath>

double t, l, x, y;

struct Point {
  double x, y, z;
  Point(double x_, double y_, double z_) : x(x_), y(y_), z(z_) { }
};

Point get_position(double time) {
  double theta = time / t * 2 * M_PI;
  double yy = l / 2.0 * (0.0 - std::sin(theta));
  double zz = l / 2.0 * (1.0 - std::cos(theta));
  return Point(0.0, yy, zz);
}

double get_length(Point p) {
  double dx = std::abs(p.x - x);
  double dy = std::abs(p.y - y);
  double dz = p.z;
  return std::sqrt(dx * dx + dy * dy + dz * dz);
}

double angle(double e) {
  Point pos = get_position(e);
  double hypo = get_length(pos);
  return std::asin(pos.z / hypo) / M_PI * 180.0;
}

int main() {
  int q;
  std::cin >> t >> l >> x >> y >> q;

  while (q--) {
    double e;
    std::cin >> e;
    printf("%.10f\n", angle(e));
  }
  return 0;  
}
