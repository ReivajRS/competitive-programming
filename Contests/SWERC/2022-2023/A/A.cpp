#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {__
int t;
cin >> t;
while(t--){
    int n;
    cin >> n;
    vi a(n+2);
    a[0] = 0;
    FOR(i,0,n){
        cin >> a[i+1];
    }
    a[n+1] = 1440;
    int cont = 0;
    FOR(i,0,n+1){
        if(a[i+1]-a[i] >=120) cont+=(a[i+1]-a[i])/120;
    }
    cout << (cont>=2 ? "YES" : "NO");
    cout << ENDL;
}
    
    return 0;
}