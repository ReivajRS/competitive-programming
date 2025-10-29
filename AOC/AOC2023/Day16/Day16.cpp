#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

vector<string> mat;
vi visited;
int n, m;

inline int id(int i, int j) { return i*m + j; }

// dir  0 = N, 1 = R, 2 = S, 3 = W
pi moves[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

map<pair<char, int>, int> dirChanges = {{{'/', 0}, 1}, {{'/', 1}, 0}, {{'/', 2}, 3}, {{'/', 3}, 2},
                                        {{'\\', 0}, 3}, {{'\\', 1}, 2}, {{'\\', 2}, 1}, {{'\\', 3}, 0}};

void dfs(int i, int j, int dir) {
    if (visited[id(i, j)] & (1 << dir))
        return;
    visited[id(i, j)] |= (1 << dir);

    int y = i + moves[dir].first, x = j + moves[dir].second;

    if (y < 0 || y >= n || x < 0 || x >= m)
        return;
    
    if (mat[y][x] == '-' && (dir == 0 || dir == 2)) {
        dfs(y, x, 1);
        dfs(y, x, 3);
    }
    else if (mat[y][x] == '|' && (dir == 1 || dir == 3)) {
        dfs(y, x, 0);
        dfs(y, x, 2);
    }
    else if (mat[y][x] == '/' || mat[y][x] == '\\')
        dfs(y, x, dirChanges[{mat[y][x], dir}]);
    else
        dfs(y, x, dir);
}

ll getEnergy() {
    ll energy = 0;
    
    FOR (i, 1, n-1) {
        FOR (j, 1, m-1) {
            energy += (visited[id(i, j)] != 0);
        }
    }

    return energy;
}

void printEnergy() {
    FOR (i, 0, n) {
        FOR (j, 0, m) {
            cout << (visited[id(i, j)] != 0 ? '#' : '.');
        }
        cout << ENDL;
    }
}

void printMat() {
    for (string &s : mat)
        cout<<s<<ENDL;
}

string part1() {
    ll ans = 0;

    visited.assign(n * m, 0);

    dfs(1, 0, 1);

    ans = getEnergy();

    return to_string(ans);
}

string part2() {
    ll mx = -1;

    FOR (i, 1, n-1) {
        visited.assign(n * m, 0);
        dfs(i, 0, 1);
        mx = max(mx, getEnergy());
    }

    FOR (i, 1, n-1) {
        visited.assign(n * m, 0);
        dfs(i, m-2, 3);
        mx = max(mx, getEnergy());
    }

    FOR (i, 1, m-1) {
        visited.assign(n * m, 0);
        dfs(0, i, 2);
        mx = max(mx, getEnergy());
    }

    FOR (i, 1, m-1) {
        visited.assign(n * m, 0);
        dfs(n-2, i, 0);
        mx = max(mx, getEnergy());
    }

    return to_string(mx);
}

int main() {_
    string s;
    
    while (cin>>s) {
        mat.pb('.' + s + '.');
    }

    mat.insert(mat.begin(), string(SZ(mat[0]), '.'));
    mat.pb(mat[0]);

    n = SZ(mat), m = SZ(mat[0]);

    cout << "Part 1: " << part1() << ENDL;
    cout << "Part 2: " << part2() << ENDL;

    return 0;
}