#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll n, e;
    cin >> n >> e;

    ll pos = 0;
    while (e > 0) {
        pos += e;
        if (pos % n == 0) {
            e++;
        }
        else {
            e--;
        }
        if (pos > ll(1e10)) {
            cout << "impossible" << '\n';
            return 0;
        }
    }
    
    cout << pos << '\n';
}