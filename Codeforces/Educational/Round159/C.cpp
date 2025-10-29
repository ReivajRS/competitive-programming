#include <bits/stdc++.h>
// Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x)   (int) x.size()
#define FOR(x, b)     for(int x = 0; x < b; x++)
#define FORE(x, a, b) for(int x = a; x <= b; x++)
#define FORR(x, a, b) for(int x = a; x >= b; x--)
#define deb(x)      cerr << #x << " = " << x << '\n';
#define deb2(x, y)  cerr << #x << " = " << x << ", " << #y << " = " << y << '\n';
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ll MOD = 1e9+7, INF = 1e18;

void solve(){
    ll n, tGCD;
    cin>>n;

    vector<ll> arr(n);
    FOR(i, n)
        cin>>arr[i];

    if (n == 1) {
        cout<<1<<ENDL;
        return;
    }

    vector<ll> diffArr;
    FOR(i, n)
        if (i+1 < n)
            diffArr.push_back(abs(arr[i]-arr[i+1]));

    tGCD = diffArr[0];
    FOR(i, sz(diffArr))
        tGCD = gcd(tGCD, diffArr[i]);

    sort(rall(arr));
    diffArr.clear();

    FOR(i, n) {
        if (i+1 < n) {
            diffArr.push_back(abs(arr[i]-arr[i+1]));
        }
    }

    ll nElement = -2e9;

    FOR(i, sz(diffArr)) {
        if (diffArr[i] > tGCD) {
            nElement = arr[i] - tGCD;
            break;
        }
    }

    nElement = nElement == -2e9 ? arr[0] + tGCD : nElement;
    arr.push_back(nElement);

    ll ans = 0, maxi = max(arr[0], nElement);
    
    FOR(i, n+1) {
        ans += abs(maxi - arr[i])/tGCD;
    }

    cout<<ans<<ENDL;
}

int main(){_
    int tc;
    cin>>tc;
    while(tc--)
        solve();
    return 0;
}