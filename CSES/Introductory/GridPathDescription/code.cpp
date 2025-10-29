#include <bits/stdc++.h>
using namespace std;

string s, dir = "URDL";
int cnt = 0, len = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
constexpr int n = 7, total = n * n - 1;
bool vis[n][n];

bool trapped(int i, int j) {
    if(i > 0 && j > 0 && vis[i - 1][j] && vis[i][j - 1] && !vis[i - 1][j - 1]) {
      return true;
    }
    if(i > 0 && j < n - 1 && vis[i - 1][j] && vis[i][j + 1] && !vis[i - 1][j + 1]){
      return true;
    }
    if(i < n - 1 && j > 0 && vis[i + 1][j] && vis[i][j-1] && !vis[i + 1][j-1]){
      return true;
    }
    if(i < n - 1 && j < n - 1 && vis[i + 1][j] && vis[i][j + 1] && !vis[i + 1][j + 1]){
      return true;
    }
    return false;
}

void dfs(int i, int j) {
    if (i == n - 1 && j == 0) {
        if (len == total) {
          cnt++;
        }
        return;
    }

    bool blocked[4];

    for (int k = 0; k < 4; k++) {
        int ii = i + dy[k], jj = j + dx[k];
        blocked[k] = (ii < 0 || ii >= n || jj < 0 || jj >= n || vis[ii][jj]);
    }

    if (blocked[0] && blocked[2] && !blocked[1] && !blocked[3]) {
      return;
    }

    if (!blocked[0] && !blocked[2] && blocked[1] && blocked[3]) {
      return;
    }

    for (int k = 0; k < 4; k++) {
        if (blocked[k] || (s[len] != '?' && s[len] != dir[k])) {
          continue;
        }
        int ii = i + dy[k], jj = j + dx[k];
        vis[ii][jj] = true;
        len++;
        if (!trapped(ii, jj)) {
          dfs(ii, jj);
        }
        vis[ii][jj] = false;
        len--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    vis[0][0] = true;
    dfs(0, 0);
    vis[0][0] = false;

    cout << cnt << '\n';
}
