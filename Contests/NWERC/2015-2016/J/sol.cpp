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
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main () { __
    vector<int> ans(256);
    FOR (i, 0, 256) {
        int x = (i ^ (i << 1)) & ((1 << 8) - 1) ;
        ans[x] = i;
    }
    int n;
    cin >> n;
    
    FOR (i, 0, n) {
        int x;
        cin >> x;
        cout << ans[x] << " ";
    }
    cout << ENDL;

    return 0;
}