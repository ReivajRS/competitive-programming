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

int main() {_
    int n, k;
    cin >> n >> k;

    string s;

    unordered_map<string, pi> umap;

    FOR (i, 0, 3*n+1) {
        getline(cin, s);
        umap[s] = {umap[s].first + 1, i};
    }

    vector<tuple<int, int, string>> vec;

    for (auto &[k, v] : umap) {
        vec.pb({-v.first, -v.second, k});
    }

    sort(ALL(vec));

    FOR(i, 0, k){
        if (i == SZ(vec)-1)
            break;
        cout << get<2>(vec[i]) << ENDL;
    }

    return 0;
}