#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { __
    ll n;
    cin >> n;

    vector<pi> ranges(n);
    FOR (i, 0, n) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    sort(ALL(ranges));

    ll P;
    cin >> P;
    vector<ll> p;
    FOR (i, 0, P) {
        ll x;
        cin >> x;
        p.pb(x);
    }
    sort(ALL(p));

    vector<ll> pegs(n, 0);
    FOR (i, 0, n) {
        auto [l, r] = ranges[i];
        auto it = lower_bound(ALL(p), l);
        while (it != p.end() && *it <= r) {
            pegs[i]++;
            if (pegs[i] == 3) {
                cout << "impossible" << ENDL;
                return 0;
            }
            it++;
        }
    }

    vector<ll> added;
    FOR (i, 0, n - 1) {
        if (pegs[i] == 2)
            continue;
        auto [l, r] = ranges[i];
        bool shared = (r == ranges[i + 1].first);
        if (pegs[i] == 0) {
            added.pb(l + 1);
            if (shared && pegs[i + 1] < 2) {
                added.pb(r);
                pegs[i + 1]++;
            }
            else
                added.pb(l + 2);
            continue;
        }
        if (pegs[i] == 1) { 
            if (shared && pegs[i + 1] < 2 && !binary_search(ALL(p), r)) {
                added.pb(r);
                pegs[i + 1]++;
            }
            else {
                if (binary_search(ALL(p), l + 2))
                    added.pb(l + 3);
                else
                    added.pb(l + 2);
            }
        }
    }

    auto [l, r] = ranges.back();
    if (pegs.back() == 0)
        added.pb(l + 1);
    if (pegs.back() <= 1) {
        if (binary_search(ALL(p), l + 2))
            added.pb(l + 3);
        else
            added.pb(l + 2);
    }

    cout << SZ(added) << ENDL;
    for (auto &x : added)
        cout << x << ' ';
    cout << ENDL;

    return 0;
}