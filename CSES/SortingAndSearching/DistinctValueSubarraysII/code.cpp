#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    int l = 0;
    int64_t ans = 0;
    map<int, int> cnt;

    for (int r = 0; r < n; r++) {
        cnt[a[r]]++;
        while (l < r && int(cnt.size()) > k) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) {
                cnt.erase(a[l]);
            }
            l++;
        }
        ans += r - l + 1;
    }
    
    cout << ans << '\n';
}