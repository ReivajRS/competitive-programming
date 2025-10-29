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

void solve() {
    int h, w, x1, x2, y1, y2;
    cin >> h >> w >> y1 >> x1 >> y2 >> x2;

    int moves = y2 - y1;
    if (moves < 0) {
        cout << "Draw" << ENDL;
        return;
    }
    if (x1 == x2) {
        cout << (moves & 1 ? "Alice" : "Bob") << ENDL;
        return;
    }

    if (moves & 1) {
        if (x1 <= x2) {
            x1 = min(w, x1 + (moves + 1) / 2);
            y1 = min(h, y1 + (moves + 1) / 2);
            x2 = min(w, x2 + moves / 2);
            y2 = max(1, y2 - moves / 2);
        }
        else {
            x1 = max(1, x1 - (moves + 1) / 2);
            y1 = min(h, y1 + (moves + 1) / 2);
            x2 = max(1, x2 - moves / 2);
            y2 = max(1, y2 - moves / 2);
        }
        cout << (x1 == x2 && y1 == y2 ? "Alice" : "Draw") << ENDL;
    }
    else {
        if (x1 >= x2) {
            x1 = min(w, x1 + moves / 2);
            y1 = min(h, y1 + moves / 2);
            x2 = min(w, x2 + moves / 2);
            y2 = max(1, y2 - moves / 2);
        }
        else {
            x1 = max(1, x1 - moves / 2);
            y1 = min(h, y1 + moves / 2);
            x2 = max(1, x2 - moves / 2);
            y2 = max(1, y2 - moves / 2);
        }
        cout << (x1 == x2 && y1 == y2 ? "Bob" : "Draw") << ENDL;
    }
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}