#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Int {
public:
  bool operator<(const Int& other) const {
    if (abs(data) != abs(other.data)) {
      return abs(data) > abs(other.data);
    } else {
      return data > other.data;
    }
  }

  int data;
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  priority_queue<Int> pq;
  int N; cin >> N;
  while (N--) {
    int qry; cin >> qry;
    if (!qry) {
      if (pq.empty()) {
        cout << 0 << '\n';
      } else {
        cout << pq.top().data << '\n';
        pq.pop();
      }
    } else { // insert
      pq.push({qry});
    }
  }
}
