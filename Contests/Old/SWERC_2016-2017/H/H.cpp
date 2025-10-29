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

ll comb[33][33];
set<ll> nums;

void dfs(int dim, int ht, int mini, ll val) {
    if (dim == 0) {
        if (ht == 0)
            nums.insert(val);
        return;
    }
    FOR (i, mini, ht + 1)
        dfs(dim - 1, ht - i, i, val * comb[ht][i]);
}

signed main() { __
    int d, h;
    cin >> d >> h;
    
    FOR (i, 0, 33) {
        comb[i][0] = comb[i][i] = 1;
        FOR (j, 1, i)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }

    dfs(d, h - 1, 0, 1);

    for (auto &x : nums)
        cout << x << ENDL;

    return 0;
}