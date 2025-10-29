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

ll n, p, l, t;

inline bool check(ll pwk) {
    return pwk*(2*t+l) >= p;
}

void solve(){
    cin>>n>>p>>l>>t;

    int wk = ceil(1.0*n / 7);
    int pwk = wk/2;

    // puntos que puede conseguir trabajando en inicio de semana
    ll lw = 0, r = pwk, mid;
    while(lw < r) {
        mid = lw + (r - lw)/2;
        if (check(mid))
            r = mid;
        else
            lw = mid + 1;
    }

    ll ans = lw;

    p -= (ans*(2*t+l));

    // Si n es impar, habra una tarea no considerada aun
    if (p > 0 && wk & 1)
        p -= (l+t), ans++;
    
    if (p > 0) {
        ans += ceil(1.0*p/l);
    }

    cout<<n-ans<<ENDL;
}

int main(){_
    int tc;
    cin>>tc;
    while(tc--)
        solve();
    return 0;
}