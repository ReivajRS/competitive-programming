#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << max(accumulate(a.begin(), a.end(), 0ll), *max_element(a.begin(), a.end()) * 2ll) << '\n';
}