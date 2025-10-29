#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;

    if (z > x + y) {
        cout << "No" << '\n';
        return;
    }

    if (z > x) {
        cout << "No" << '\n';
        return;
    }

    if (2 * x < y) {
        cout << "No" << '\n';
        return;
    }

    if ((y & 1) && z == 0) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}