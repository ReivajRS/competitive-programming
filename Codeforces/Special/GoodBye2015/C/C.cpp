#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    int q;
    cin >> q;

    vector<vector<int>> row(n + 1, vector<int>(m + 1)), col(n + 1, vector<int>(m + 1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && g[i][j] == '.' && g[i + 1][j] == '.') {
                col[i + 1][j + 1] = 1;
            }
            if (j + 1 < m && g[i][j] == '.' && g[i][j + 1] == '.') {
                row[i + 1][j + 1] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            col[i + 1][j + 1] += col[i + 1][j] + col[i][j + 1] - col[i][j];
            row[i + 1][j + 1] += row[i + 1][j] + row[i][j + 1] - row[i][j];
        }
    }

    while (q--) {
        vector<int> r(2), c(2);
        cin >> r[0] >> c[0] >> r[1] >> c[1];
        int ans = col[r[1] - 1][c[1]] - col[r[1] - 1][c[0] - 1] - col[r[0] - 1][c[1]] + col[r[0] - 1][c[0] - 1];
        ans += row[r[1]][c[1] - 1] - row[r[1]][c[0] - 1] - row[r[0] - 1][c[1] - 1] + row[r[0] - 1][c[0] - 1];
        cout << ans << '\n';
    }
}