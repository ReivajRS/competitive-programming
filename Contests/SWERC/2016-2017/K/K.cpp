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
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(nullptr);

vector<set<int>> g1, g2;
vector<bool> vis1, vis2;

bool dfs1(int u, int p = -1) {
    vis1[u] = 1;
    for (auto v : g1[u]) {
        if (v == p || v == u)
            continue;
        if (vis1[v] || dfs1(v, u))
            return true;
    }
    return false;
}

bool dfs2(int u, int p = -1) {
    vis2[u] = 1;
    for (auto v : g2[u]) {
        if (v == p || v == u)
            continue;
        if (vis2[v] || dfs2(v, u))
            return true;
    }
    return false;
}

signed main() { __
    int n;
    cin >> n;

    map<tuple<int, int, int>, int> n1;
    map<pair<int, int>, int> n2;
    int c1 = 0, c2 = 0;

    FOR (i, 0, n) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        if (!n1.count({x1, y1, z1})) {
            g1.push_back(set<int>());
            n1[{x1, y1, z1}] = c1++;
        }
        if (!n1.count({x2, y2, z2})) {
            g1.push_back(set<int>());
            n1[{x2, y2, z2}] = c1++;
        }
        g1[n1[{x1, y1, z1}]].insert(n1[{x2, y2, z2}]);
        g1[n1[{x2, y2, z2}]].insert(n1[{x1, y1, z1}]);

        if (!n2.count({x1, y1})) {
            g2.push_back(set<int>());
            n2[{x1, y1}] = c2++;
        }
        if (!n2.count({x2, y2})) {
            g2.push_back(set<int>());
            n2[{x2, y2}] = c2++;
        }
        g2[n2[{x1, y1}]].insert(n2[{x2, y2}]);
        g2[n2[{x2, y2}]].insert(n2[{x1, y1}]);
    }

    vis1.assign(c1, 0);
    vis2.assign(c2, 0);

    bool b1 = 0, b2 = 0;
    FOR (i, 0, c1)
        if (!vis1[i])
            b1 |= dfs1(i, -1);
    FOR (i, 0, c2)
        if (!vis2[i])
            b2 |= dfs2(i, -1);
    if (b1)
        cout << "True closed chains" << ENDL;
    else
        cout << "No true closed chains" << ENDL;
    
    if (b2)
        cout << "Floor closed chains" << ENDL;
    else
        cout << "No floor closed chains" << ENDL;

    return 0;
}