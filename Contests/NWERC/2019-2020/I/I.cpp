#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end();
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { __
    int n;
    cin >> n;
    int a[n + 2];
    a[0] = 0;
    a[n + 1] = 1e9 + 5;
    FOR (i, 0, n)
        cin >> a[i + 1];
    
    pair<int, int> ans = {1, 1};
    int mxi = 0;
    bool b = 0, used = 0;
    FOR (i, 1, n + 2) {
        if (a[i] < a[i - 1]) {
            if (!b && used) {
                cout << "impossible" << ENDL;
                return 0;
            }
            b = 1;
        }
        else if (a[i] > a[i - 1]) {
            if (b && (a[mxi] > a[i] || a[i - 1] < a[mxi - 1])) {
                cout << "impossible" << ENDL;
                return 0;
            }
            if (b) {
                b = 0;
                used = 1;
                ans = {mxi, i - 1};
            }
            mxi = i;
        }
    }
    cout << ans.first << ' ' << ans.second << ENDL;

    return 0;
}