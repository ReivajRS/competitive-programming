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

ll f(string& s, int n, bool last) {
    if (n == 0)
        return 0;
    ll pos = 0;
    char c = s[s.length() - n];
    if (!last)
        pos = f(s, n - 1, c == '0' ? 0 : 1) + (c == '1') * (1ll << (n - 1));
    else
        pos = f(s, n - 1, c == '1' ? 0 : 1) + (c == '0') * (1ll << (n - 1));
    return pos;
}

signed main() { __
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    cout << f(s2, n, 0) - f(s1, n, 0) - 1 << ENDL;

    return 0;
}