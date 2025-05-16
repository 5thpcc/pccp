/*
  1967/트리의 지름/BOJ
  실행 시간: 4ms
  해결하는데 걸린 시간: 1hours
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> adj[10001];
int max_dist = 0;
int max_node;

void dfs(int cur, int par, int d) {
    for (auto nxt : adj[cur]) {
        if (nxt.first == par) continue;
        if (d + nxt.second > max_dist) {
            max_dist = d + nxt.second;
            max_node = nxt.first;
        }
        dfs(nxt.first, cur, d + nxt.second);
    }
}

int main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        adj[x].emplace_back(y, d);
        adj[y].emplace_back(x, d);
    }
    dfs(1, 0, 0);
    dfs(max_node, 0, 0);
    cout << max_dist;
}
