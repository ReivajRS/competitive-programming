#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<string> mat;
vector<vector<bool>> vis;
int w, h;

pi moves[] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void dfs(int i, int j) {
    vis[i][j] = 1;
    for (auto &[dy, dx] : moves) {
        int y = i + dy, x = j + dx;
        if (y < 0 || y >= h || x < 0 || x >= w)
            continue;
        if (vis[y][x] || mat[y][x] == '.')
            continue;
        dfs(y, x);
    }
}

int check(int i, int j) {
    vis[i][j] = 1;
    
    int y = i, x = j + 1;
    int widthU = 1;
    while (mat[y][x] == '#')
        widthU++, x++;

    y = i + 1, x = j;
    int heightL = 1;
    while (mat[y][x] == '#')
        heightL++, y++;

    if (widthU == 1 && heightL == 1)
        return -1;

    y = i + heightL - 1, x = j + 1;
    int widthD = 1;
    FOR (k, 0, widthU)
        widthD += mat[y][x + k] == '#';

    y = i + 1, x = j + widthU - 1;
    int heightR = 1;
    FOR (k, 0, heightL)
        heightR += mat[y + k][x] == '#';

    dfs(i, j);

    if (widthU == widthD && heightL == heightR)
        return 1;
    if (heightL == heightR)
        return 0;
    return 2;
}

signed main() { __
    cin >> w >> h;

    mat.resize(h), vis.assign(h, vector<bool>(w, 0));

    FOR (i, 0, h)
        cin >> mat[i];

    dfs(0, 0);

    vi ans(3, 0);

    FOR (i, 0, h) {
        FOR (j, 0, w) {
            if (vis[i][j])
                continue;
            if (mat[i][j] == '.') {
                vis[i][j] = 1;
                continue;
            }
            int ret = check(i, j);
            if (ret == -1)
                continue;
            ans[ret]++;
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ENDL;

    return 0;
}