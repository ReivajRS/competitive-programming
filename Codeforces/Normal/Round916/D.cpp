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

void solve() {
    int n;
    cin >> n;
    vector<vector<pi>> friends(3, vector<pi>(n));

    FOR (i, 0, 3) {
        FOR (j, 0, n) {
            int v;
            cin >> v;
            friends[i][j] = {v, j};
        }
    }

    sort(ALL(friends[0]));
    sort(ALL(friends[1]));
    sort(ALL(friends[2]));

    int mx = -1;
    unordered_set<int> days;

    ROF (i, n, n-3) {
        days.clear();
        int val[3];
        val[0] = friends[0][i].first;
        days.insert(friends[0][i].second);

        bool flag = false;

        ROF (j, n, n-3) {
            if (days.count(friends[1][j].second))
                continue;
            val[1] = friends[1][j].first;
            int inserted = friends[1][j].second;;
            days.insert(friends[1][j].second);

            ROF (k, n, n-3) {
                if (days.count(friends[2][k].second))
                    continue;
                val[2] = friends[2][k].first;

                mx = max(mx, accumulate(val, val + 3, 0));
            }

            days.erase(inserted);
        }
    }

    cout << mx << ENDL;
}

int main() {_
    int tc;
    cin>>tc;
    while (tc--) {
        solve();
    }
    return 0;
}