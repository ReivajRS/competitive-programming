#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end();
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

struct DSU {
    vi e;
    DSU(int n) : e(n, -1) {}
    int size(int x) { return -e[get(x)]; }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool join(int a, int b) {
        a = get(a), b = get(b);
        if (a == b)
            return false;
        if (e[a] > e[b])
            swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

int main() { __
    int n;
    cin >> n;
    DSU UF(200005);
    unordered_map<int, int> rep;
    vector<tuple<int, int, int>> unions;

    FOR (i, 0, n) {
        int m;
        cin >> m;
        FOR (j, 0, m) {
            int d;
            cin >> d;
            if (!rep.count(d)) {
                rep[d] = i;
                continue;
            }
            if (UF.join(rep[d], i))
                unions.push_back({rep[d]+1, i+1, d});
        }
    }

    if (SZ(unions) != n-1) {
        cout << "impossible" << ENDL;
        return 0;
    }

    for (auto &[a, b, c] : unions)
        cout << a << ' ' << b << ' ' << c << ENDL;

    return 0;
}