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

    int neg = 0;
    bool zero = 0;
    vi a(n);

    FOR (i, 0, n) {
        cin >> a[i];
        if (a[i] < 0)
            neg++;
        else if (a[i] == 0)
            zero = 1;
    }

    if (zero == 0 && neg % 2 == 0) {
        cout << 1 << ENDL;
        cout << 1 << " " << 0 << ENDL;
    }
    else {
        cout << 0 << ENDL;
    }


}

int main() {_
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}