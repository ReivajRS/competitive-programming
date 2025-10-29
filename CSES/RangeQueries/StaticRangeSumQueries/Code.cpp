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

int main() { __
    int n, q;
    cin >> n >> q;
    
    n++;
    vi a(n);
    FOR (i, 1, n) 
        cin >> a[i];
    
    vector<ll> presum(n);
    FOR (i, 1, n)
        presum[i] = a[i] + presum[i - 1];
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << presum[r] - presum[l - 1] << ENDL;
    }

    return 0;
}