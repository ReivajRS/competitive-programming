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

signed main() { __
    int n;
    cin >> n;

    vector<string> names(n);
    vector<double> a(n), mns(n), mxs(n);

    FOR (i, 0, n) {
        cin >> names[i] >> a[i];
        mns[i] = max(0.0, a[i] - 0.5);
        mxs[i] = min(100.0, a[i] + 0.49);
    }

    double minsum = accumulate(ALL(mns), 0.0);
    double maxsum = accumulate(ALL(mxs), 0.0);

    if (minsum > 100.0 || maxsum < 100.0) {
        cout << "IMPOSSIBLE" << ENDL;
        return 0;
    }

    cout << setprecision(2) << fixed;
    FOR (i, 0, n) {
        cout << names[i] << ' ';
        cout << mns[i] + max(0.0, 100 - (maxsum - mxs[i] + mns[i])) << ' ';
        cout << mxs[i] - max(0.0, (minsum - mns[i] + mxs[i]) - 100);
        cout << ENDL;
    }

    return 0;
}