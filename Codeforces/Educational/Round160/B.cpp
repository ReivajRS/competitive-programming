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

void solve() {
    string s;
    cin>>s;

    int zeros = count(s.begin(), s.end(), '0'), ones = sz(s) - zeros;
    
    FOR(i, sz(s)) {
        if (s[i] == '1') {
            if (zeros == 0) {
                cout<<sz(s)-i<<ENDL;
                return;
            }
            else
                zeros--;
        }
        else {
            if (ones == 0) {
                cout<<sz(s)-i<<ENDL;
                return;
            }
            else
                ones--;
        }
    }
 
    cout<<0<<ENDL;
}

int main(){_
    int tc;
    cin>>tc;
    while(tc--)
        solve();
    return 0;
}