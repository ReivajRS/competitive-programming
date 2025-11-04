#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> vis(n, -1);
    vector<int> cnt_comp(n);

    int cnt_dfs = 0;
    auto dfs = [&](auto& dfs, int u) -> void {
        vis[u] = cnt_dfs;
        cnt_comp[cnt_dfs]++;
        for (int v : g[u]) {
            if (vis[v] == -1) {
                dfs(dfs, v);
            }
        }
    };

    for (int u = 0; u < n; u++) {
        if (vis[u] == -1) {
            dfs(dfs, u);
            cnt_dfs++;
        }
    }

    for (int i = 0; i < cnt_dfs; i++) {
        if (cnt_comp[i] < k) {
            cout << "impossible" << '\n';
            return 0;
        }
    }

    vector<int> type_comp(n);
    for (int i = 0; i < n; i++) {
        cout << (type_comp[vis[i]] % k + 1) << ' ';
        type_comp[vis[i]]++;
    }
    cout << '\n';
}
