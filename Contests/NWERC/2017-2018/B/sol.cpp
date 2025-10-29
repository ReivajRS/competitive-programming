#include <bits/stdc++.h>
using namespace std;
// BRO... CSMS
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() {

    int n;
    cin >> n;
    if(n<=3){
        cout << 1 << ENDL;
        return 0;
    }
    cout << n-2 << ENDL;

    return 0;
}