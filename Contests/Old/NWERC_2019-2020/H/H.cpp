#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
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
    int n, k;
    cin >> n >> k;
    n++;

    vi h(n);

    FOR (i, 0, n)
        cin >> h[i];
   
    while (k--) {
        double g;
        cin >> g;
        g *= 10;

        vi h2(n);
        FOR (i, 0, n)
            h2[i] = h[i] - g*i;
        
        vector<pi> staircase;

        int mn = h2[0];

        staircase.pb({-h2[0], 0});

        FOR (i, 0, n) {
            if (h2[i] < mn)
                staircase.pb({-h2[i], i}), mn = h2[i];
        }

        if (SZ(staircase) == n) {
            cout << -1 << ENDL;
            continue;
        }

        sort(ALL(staircase));

        double mx = 0;

        FOR (b, 0, n) {
            int a = lower_bound(ALL(staircase), pi(-h2[b], 0))->second;
            double dist = b - a, distLeft = 0, distRight = 0;

            if (b < n-1 && h2[b] > h2[b+1] && h2[a] != h2[b]) {
                double m = h2[b+1] - h2[b];
                double x = abs((-b * m + h2[b] - h2[a]) / m);
                distRight= (x - ll(x));
            }

            if (a > 0 && h2[a-1] > h2[a] && h2[a] != h2[b]) {
                double m = h2[a] - h2[a-1];
                double x = abs((-a * m + h2[a] - h2[b]) / m);
                distLeft = 1 - (x - ll(x));
            }

            mx = max(mx, dist + max(distLeft, distRight));
        }

        cout << setprecision(8) << fixed << mx << ENDL;
    }
}