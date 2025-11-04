#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, set<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        vector<tuple<int, int, int>> sums;
        for (int j = i + 1; j < n; j++) {
            int v1 = a[i] + a[j];
            int v2 = x - v1;
            if (!mp[v2].empty()) {
                auto it = mp[v2].lower_bound({i + 2, 0});
                if (it != mp[v2].end()) {
                    cout << i + 1 << ' ' << j + 1 << ' ' << it->first + 1 << ' ' << it->second + 1 << '\n';
                    return 0;
                }
                it = mp[v2].begin();
                if (it->first != i && it->first != j && it->second != i && it->second != j) {
                    cout << i + 1 << ' ' << j + 1 << ' ' << it->first + 1 << ' ' << it->second + 1 << '\n';
                    return 0;
                }
            }
            sums.push_back({v1, i, j});
        }
        for (auto [sum, j, k] : sums) {
            mp[sum].insert({k, j});
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}