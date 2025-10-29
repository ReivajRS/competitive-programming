#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

void solve() {
    int n;
    cin >> n;

    int firstPerson = -1, idx = -1;
    FOR(i, 0, n) {
        int p;
        cin >> p;
        if (firstPerson == -1)
            firstPerson = p, idx = i;
    }

    int idx2;
    FOR (i, 0, n) {
        int p;
        cin >> p;
        if (p == firstPerson)
            idx2 = i;
    }

    cout << idx2 << ENDL;
}

int main() {__
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    
    return 0;
}