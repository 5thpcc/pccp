#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<int> v(N);
  for (auto& it : v) cin >> it;
  sort(v.begin(), v.end());

  int fr = 0, rr = N-1;
  int smallest = 2e9;
  int val1, val2;

  while (fr < rr) {
    int a = v[fr], b = v[rr];
    int sum = a+b;

    if (abs(sum) < smallest) {
      val1 = a, val2 = b;
      smallest = abs(sum);
    }

    if (sum == 0) break;

    if (sum > 0) rr--;
    else fr++;
  }

  cout << val1 << ' ' << val2;
}
