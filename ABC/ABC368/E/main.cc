#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Train {
  int from, to;
  ll depart, arrive;
  Train(int from, int to, ll depart, ll arrive)
      : from(from), to(to), depart(depart), arrive(arrive) {}
};

struct Event {
  int type, train;
  ll time;
  Event(int type, int train, ll time) : type(type), train(train), time(time) {}
  bool operator<(const Event other) const {
    return make_pair(time, -type) < make_pair(other.time, -other.type);
  }
};

template <class T>
inline void ChangeMax(T &a, T b) {
  a = max(a, b);
}

int main() {
  int n, m, x0;
  cin >> n >> m >> x0;

  vector<Train> trains;
  for (int i = 0; i < m; ++i) {
    int a, b;
    ll s, t;
    cin >> a >> b >> s >> t;
    trains.emplace_back(--a, --b, s, t);
  }

  vector<Event> events;
  for (int i = 0; i < m; ++i) {
    events.emplace_back(0, i, trains[i].depart);
    events.emplace_back(1, i, trains[i].arrive);
  }
  sort(begin(events), end(events));

  vector<ll> x(m);
  x[0] = x0;

  vector<ll> arrive(n, 0);
  for (const auto event : events) {
    if (event.type == 0) {
      if (event.train > 0) {
        x[event.train] = max(
            0LL, arrive[trains[event.train].from] - trains[event.train].depart);
      }
    } else {
      ChangeMax(arrive[trains[event.train].to],
                trains[event.train].arrive + x[event.train]);
    }
  }

  for (int i = 1; i < m; ++i) {
    cout << x[i] << " ";
  }
  cout << endl;

  return 0;
}