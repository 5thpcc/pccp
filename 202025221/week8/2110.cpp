/*
  2110/공유기 설치/BOJ
  실행 시간: 36ms
  해결하는데 걸린 시간: 41min
*/

#include <bits/stdc++.h>
using namespace std;

int n, c;
int a[200000];

int check(int x) { // x간격 이상으로 설치한 공유기 개수 반환
    int j = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[j] >= x) {
            cnt++;
            j = i;
        }
    }
    return cnt;
}
int main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    // 가장 인접한 두 공유기 사이의 최대 거리 x
    // x가 가능한지 확인 N * 이분탐색 logN = O(NlogN)이면 가능할듯?
  
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int st = 0;
    int en = 1e9 + 1;
    int ans = 0;
    while (st < en) {
        int mid = (st + en)/2;
        if (check(mid) >= c) { // 답의 후보
            if (mid > ans)
                ans = mid;
            st = mid + 1;
        }
        else {
            en = mid;
        }
    }
    cout << ans;
}

