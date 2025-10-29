#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    int total0 = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        total0 += (a[i] == 0);
    }
    set<pair<int, int>> st;
    vector<int> pos(n + 1, -1);
    vector<int> ans(total0);
    int cnt0 = 0;
    for (int i = 0; i < m; i++) {
        int x = a[i];
        if (x == 0) {
            st.insert({i, cnt0++});
        }
        else {
            auto it = st.upper_bound({pos[x], -1});
            if (it == st.end()) {
                cout << "NO" << '\n';
                return;
            }
            pos[x] = i;
            ans[it->second] = x;
            st.erase(it);
        }
    }
    cout << "YES" << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

/*
    2
    2 8
    0 0 2 0 1 0 1 2
    2 8
    0 0 2 1 0 1 0 2
*/

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}