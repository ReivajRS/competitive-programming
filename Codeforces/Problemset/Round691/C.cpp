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
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);

    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    if (n == 1) {
        for (auto &x : b)
            cout << a[0] + x << ' ';
        cout << ENDL;
        return 0;
    }

    ll g = a[1] - a[0];
    FOR (i, 2, n)
        g = gcd(g, a[i] - a[0]);

    for (auto &x : b)
        cout << gcd(a[0] + x, g) << ' ';
    cout << ENDL;

    return 0;
}