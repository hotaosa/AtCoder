#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int> > wall(n);
    for (int i = 0; i < n; ++i) cin >> wall[i].second >> wall[i].first;
    sort(wall.begin(), wall.end());

    int res = 0, cur = -1;
    for (int i = 0; i < n; ++i) {
        if (wall[i].second > cur) {
            ++res;
            cur = wall[i].first + d - 1;
        }
    }

    cout << res << endl;
    return 0;
}
