#include <bits/stdc++.h>
// Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x)   (int) x.size()
#define FOR(x, b)     for(int x = 0; x < b; x++)
#define FORE(x, a, b) for(int x = a; x <= b; x++)
#define FORR(x, a, b) for(int x = a; x >= b; x--)
#define deb(x)      cerr << #x << " = " << x << '\n';
#define deb2(x, y)  cerr << #x << " = " << x << ", " << #y << " = " << y << '\n';
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ll MOD = 1e9+7, INF = 1e18;

unordered_map<char, vii> moves;

vector<string> mat;
int n, m, maxd = 0;
vector<vector<int>> dist;
vector<vector<bool>> vis;

void dfs(int i, int j) {
    maxd = max(maxd, dist[i][j]);
    for (auto &[y, x] : moves[mat[i][j]]) {
        if (i + y >= n || i + y < 0 || j + x >= m || j + x < 0 || mat[i+y][j+x] == '.' || dist[i+y][j+x] != -1)
            continue;
        dist[i+y][j+x] = dist[i][j] + 1;
        dfs(i+y, j+x);
    }
}

int insideCount() {
    int cnt = 0;
    FOR(i, n) {
        FOR(j, m) {
            if (dist[i][j] != -1)
                continue;
            int crosses = 0, x = j, y = i;
            while (x < m && y < n) {
                if (dist[y][x] != -1 && mat[y][x] != 'L' && mat[y][x] != '7')
                    crosses++;
                x++, y++;
            }
            if (crosses%2 != 0)
                cnt++;
        }
    }
    return cnt;
}

int main(){_
    moves['|'] = {{1, 0}, {-1, 0}};
    moves['-'] = {{0, 1}, {0, -1}};
    moves['L'] = {{-1, 0}, {0, 1}};
    moves['J'] = {{-1, 0}, {0, -1}};
    moves['7'] = {{1, 0}, {0, -1}};
    moves['F'] = {{1, 0}, {0, 1}};
    moves['S'] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    string s;
    ii start;

    while (cin>>s) {
        mat.push_back(s);
        FOR(i, s.length())
            if (s[i] == 'S')
                start = {sz(mat)-1, i};
    }

    n = sz(mat), m = sz(s);
    dist.assign(n, vector<int>(m, -1));

    dist[start.first][start.second] = 0;
    dfs(start.first, start.second);

    cout<<insideCount()<<ENDL;

    return 0;
}