#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
   ll a, b;
   cin >> a >> b;

   int ans = 0;
   for (int i = 1; i < 61; i++) {
        ll x = (1ll << i) - 1;
        for (int j = 0; j < i - 1; j++) {
            ll y = x ^ (1ll << j);
            if (a <= y && y <= b) {
                ans++;
            }
        }
   }

   cout << ans << '\n';
}