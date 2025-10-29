#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(nullptr);

signed main() { __
    vector<ull> nums;
    nums.pb(ULLONG_MAX);
    nums.pb(ULLONG_MAX >> 1);
    nums.pb(ULLONG_MAX >> 2);

    FOR (i, 1, 64) {
        ull x = (1ULL << i) - 1;
        nums.pb(x);
        FOR (j, i + 1, 64 - i) {
            x <<= 1ULL;
            assert(x >= 0);

            nums.pb(x);
        }
    }

    FOR (i, 1, 64) {
        ull x = (1ULL << i) - 1;
        FOR (j, 1, 64 - i) {
            ull y = x, s = i + j;
            for (int k = 1; k * s + i <= 63; k++) {
                y <<= s;
                y |= x;
                assert(y >= 0);

                nums.pb(y);
            }
            y = (x << j);
            nums.pb(y);
            for (int k = 1; k * s <= 63; k++) {
                assert(y >= 0);
                y <<= i;
                y |= x;
                y <<= j;
                assert(y >= 0);
                nums.pb(y);
            }            
        }
    }

    cout << SZ(nums) << ENDL;
    sort(ALL(nums));
    nums.erase(unique(ALL(nums)), nums.end());
    cout << SZ(nums) << ENDL;

    ull x, y;
    cin >> x >> y;

    for (auto &x : nums) {
        cout << x << ' ';
    }
    cout << ENDL;

    // x =   18437772058826899200ULL;
    // while (x) {
    //     cout << x % 2;
    //     x /= 2;
    // }


    return 0;
}