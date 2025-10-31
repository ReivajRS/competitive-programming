#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) -> bool {
        return a[i] < a[j];
    });

    for (int i = 1; i < n - 1; i++) {
        int l = 0, r = n - 1;
        while (l < i && i < r) {
            int sum = a[p[l]] + a[p[i]] + a[p[r]];
            if (sum == x) {
                cout << p[l] + 1 << ' ' << p[i] + 1 << ' ' << p[r] + 1 << '\n';
                return 0;
            }
            if (sum < x) {
                l++;
            }
            else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}