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
    string s;
    cin >> s;
    stack<int> sorted, unsorted;
    int sz = 0;
    FOR(i, 0, SZ(s)) {
        if (s[i] == '+') {
            sz++;
            continue;
        }
        if (s[i] == '-') {
            sz--;
            while (!sorted.empty() && sorted.top() > sz)
                sorted.pop();
            while (!unsorted.empty() && unsorted.top() > sz)
                unsorted.pop();
            continue;
        }
        if (s[i] == '1') {
            while (!unsorted.empty() && unsorted.top() > sz)
                unsorted.pop();
            if (!unsorted.empty()) {
                cout << "NO" << ENDL;
                return;
            }
            if (sorted.empty() || sorted.top() != sz)
                sorted.push(sz);
        }
        else {
            if (sz <= 1) {
                cout << "NO" << ENDL;
                return;
            }
            while (!sorted.empty() && sorted.top() > sz)
                sorted.pop();
            if (!sorted.empty() && sorted.top() == sz) {
                cout << "NO" << ENDL;
                return;
            }
            if (unsorted.empty() || unsorted.top() != sz)
                unsorted.push(sz);
        }
    }

    cout << "YES" << ENDL;
}

signed main() { __
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}