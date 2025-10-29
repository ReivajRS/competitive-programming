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

void solve() {
    int n;
    cin >> n;
    
    int s1 = 1e9, s2 = 1e9, cnt = 0;

    FOR (i, 0, n) {
        int x;
        cin >> x;
        if (s1 > s2) swap(s1, s2);
        if (x <= s1)
            s1 = x;
        else if (x <= s2)
            s2 = x;
        else
            s1 = x, cnt++;
    }

    cout << cnt << ENDL;
}

int main() {_
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}