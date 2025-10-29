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
    string s, sa = "", sb = "";
    ll a, b;

    cin>>s;

    bool flag = false;

    FOR(i, sz(s)) {
        if (i > 0 && s[i] != '0')
            flag = true;
        if (!flag)
            sa += s[i];
        else
            sb += s[i];
    }

    if (sb.empty())
        sb = "0";

    a = stoll(sa), b = stoll(sb);

    if (b > a)
        cout<<a<<' '<<b<<ENDL;
    else
        cout<<-1<<ENDL;
}

int main(){_
    int tc;
    cin>>tc;
    while(tc--)
        solve();
    return 0;
}