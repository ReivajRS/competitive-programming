#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    ll k;
    string s;
    cin >> s >> k;
    
    ll sz = SZ(s);
    k--, s += ' ';
    
    stack<char> st;
    for (auto &c : s) {
        while (k >= sz && !st.empty() && st.top() > c) {
            st.pop();
            k -= sz;
            sz--;
        }
        st.push(c);
    }

    string s2 = "";
    while (!st.empty()) {
        if (st.top() != ' ')
            s2 += st.top();
        st.pop();
    }
    reverse(ALL(s2));

    cout << s2[k];
}

signed main() { __
    ll tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}