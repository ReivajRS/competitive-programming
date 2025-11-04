#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies[i] = {b, a};
    }

    sort(movies.begin(), movies.end());

    map<int, int> mp = {{0, k}};

    int ans = 0;
    for (auto [b, a] : movies) {
        auto it = mp.upper_bound(a);
        if (it == mp.end() && !mp.empty()) {
            it--;
        }
        while (it != mp.begin() && it->first > a) {
            it--;
        }
        if (it->first <= a) {
            ans++;
            mp[b]++;
            it->second--;
            if (it->second == 0) {
                mp.erase(it);
            }
        }
    }

    cout << ans << '\n';
}