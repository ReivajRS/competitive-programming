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

constexpr int MAXN = 3e5+5;

int main() {_
    int n, w, k, x;
    cin >> n >> w;

    vector<ll> pts(MAXN, 0), sumRnk(MAXN, 0), valAtLastChange(MAXN, 0), rnk(MAXN, 0), preSumRnk(MAXN, 0), lastChangeOfScore(MAXN, 0);

    rnk[0] = 1, preSumRnk[0] = 0;

    FOR (i, 0, w) {
        cin >> k;
        while (k--) {
            cin >> x;
            x--;
            int p = pts[x];
            preSumRnk[p+1] += (i - lastChangeOfScore[p+1]) * (rnk[p+1]);
            preSumRnk[p] += (i - lastChangeOfScore[p]) * (rnk[p]);
            lastChangeOfScore[p+1] = lastChangeOfScore[p] = i;
            rnk[p+1] = rnk[p+1] > 0 ? rnk[p+1] : rnk[p];
            rnk[p]++;
            pts[x]++;
            sumRnk[x] += preSumRnk[p] - valAtLastChange[x];
            valAtLastChange[x] = preSumRnk[p+1];
        }
    }

    FOR (i, 0, MAXN)
        preSumRnk[i] += (w - lastChangeOfScore[i]) * rnk[i];

    FOR (i, 0, n)
        sumRnk[i] += preSumRnk[pts[i]] - valAtLastChange[i];

    cout << setprecision(8) << fixed;
    FOR (i, 0, n)
        cout << sumRnk[i]*1.0/w << ENDL;

    return 0;
}