#include <bits/stdc++.h>
#include <atcoder/all>

struct Point {
    int id_, x_, y_;    
    Point(int id, int x, int y) : id_(id), x_(x), y_(y) { }
};

bool comp_x(const Point lh, const Point rh) { return lh.x_ < rh.x_; }
bool comp_y(const Point lh, const Point rh) { return lh.y_ < rh.y_; }


int main() {
    int n;
    std::cin >> n;

    std::vector<Point> vp;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        vp.push_back(Point(i, x, y));
    }

    std::vector<Point> vp_copy = vp;
    std::set<int> candidates;
    std::sort(vp_copy.begin(), vp_copy.end(), comp_x);
    candidates.insert(vp_copy[0].id_);
    candidates.insert(vp_copy[1].id_);
    candidates.insert(vp_copy[vp_copy.size() - 1].id_);
    candidates.insert(vp_copy[vp_copy.size() - 2].id_);
    std::sort(vp_copy.begin(), vp_copy.end(), comp_y);
    candidates.insert(vp_copy[0].id_);
    candidates.insert(vp_copy[1].id_);
    candidates.insert(vp_copy[vp_copy.size() - 1].id_);
    candidates.insert(vp_copy[vp_copy.size() - 2].id_);

    std::vector<int> res;
    for (auto iter = candidates.begin(); iter != candidates.end(); ++iter) {
        for (auto iter2 = iter; iter2 != candidates.end(); ++iter2) {
            if (iter2 == iter) continue;
            res.push_back(std::max(std::abs(vp[*iter].x_ - vp[*iter2].x_), std::abs(vp[*iter].y_ - vp[*iter2].y_)));
        }
    }
    std::sort(res.begin(), res.end(), std::greater<>());
    std::cout << res[1] << std::endl;
    return 0;
}
