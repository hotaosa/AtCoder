#include <iostream>

using namespace std;

struct Cuboid {
  int x1, x2, y1, y2, z1, z2;
  Cuboid(int x1, int x2, int y1, int y2, int z1, int z2)
      : x1(x1), x2(x2), y1(y1), y2(y2), z1(z1), z2(z2) {}
};

Cuboid Overlap(Cuboid a, Cuboid b) {
  int x1 = max(a.x1, b.x1), x2 = min(a.x2, b.x2);
  int y1 = max(a.y1, b.y1), y2 = min(a.y2, b.y2);
  int z1 = max(a.z1, b.z1), z2 = min(a.z2, b.z2);
  return Cuboid(x1, x2, y1, y2, z1, z2);
}

int Volume(Cuboid c) {
  int dx = max(0, c.x2 - c.x1);
  int dy = max(0, c.y2 - c.y1);
  int dz = max(0, c.z2 - c.z1);
  return dx * dy * dz;
}

int main() {
  int v1, v2, v3;
  cin >> v1 >> v2 >> v3;

  Cuboid c1(0, 7, 0, 7, 0, 7);
  for (int x2 = -7; x2 <= 7; ++x2) {
    for (int y2 = -7; y2 <= 7; ++y2) {
      for (int z2 = -7; z2 <= 7; ++z2) {
        Cuboid c2(x2, x2 + 7, y2, y2 + 7, z2, z2 + 7);
        for (int x3 = -7; x3 <= 7; ++x3) {
          for (int y3 = -7; y3 <= 7; ++y3) {
            for (int z3 = -7; z3 <= 7; ++z3) {
              Cuboid c3(x3, x3 + 7, y3, y3 + 7, z3, z3 + 7);
              int o3 = Volume(Overlap(c3, Overlap(c1, c2)));
              int o2 = Volume(Overlap(c1, c2)) + Volume(Overlap(c2, c3)) +
                       Volume(Overlap(c1, c3)) - o3 * 3;
              int o1 = 7 * 7 * 7 * 3 - o2 * 2 - o3 * 3;
              if (o1 == v1 && o2 == v2 && o3 == v3) {
                printf("Yes\n%d %d %d %d %d %d %d %d %d\n", 0, 0, 0, x2, y2, z2,
                       x3, y3, z3);
                return 0;
              }
            }
          }
        }
      }
    }
  }

  cout << "No\n";
  return 0;
}