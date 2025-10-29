#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;

    if (n <= 3) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }

    cout << n / 2 << '\n';
    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }
    cout << '\n';
}