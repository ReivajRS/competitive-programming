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

int main(){_
    int n, m;
    vector<string> mat;
    string s;

    while (cin>>s) {
        mat.push_back(s);
    }

    n = sz(mat), m = mat[0].length();

    vii galaxies;

    FOR(i, n) {
        FOR(j, m) {
            if (mat[i][j] == '#')
                galaxies.push_back({i, j});
        }
    }

    unordered_set<int> doubJ, doubI;

    FOR(i, m) {
        bool flag = false;
        FOR(j, n) {
            flag |= (mat[j][i] == '#');
        }
        if (!flag)
            doubJ.insert(i);
    }

    FOR(i, n) {
        bool flag = false;
        FOR(j, m) {
            flag |= (mat[i][j] == '#');
        }
        if (!flag)
            doubI.insert(i);
    }

    vi swI(n, 0), swJ(m, 0);

    FOR(i, n) {
        swI[i] += (doubI.count(i));
        if (i > 0)
            swI[i] += swI[i-1];
    }

    FOR(j, m) {
        swJ[j] += (doubJ.count(j));
        if (j > 0)
            swJ[j] += swJ[j-1];
    }

    ll factor = 1000000, ans = 0;

    FOR(i, sz(galaxies)) {
        FORE(j, i+1, sz(galaxies)-1) {
            ll dx = abs(galaxies[i].second - galaxies[j].second) + (factor-1)*(swJ[max(galaxies[i].second, galaxies[j].second)] - swJ[min(galaxies[i].second, galaxies[j].second)]);
            ll dy = abs(galaxies[i].first - galaxies[j].first) + (factor-1)*(swI[max(galaxies[i].first, galaxies[j].first)] - swI[min(galaxies[i].first, galaxies[j].first)]);
            ans += (dx+dy);
        }
    }

    cout<<ans<<ENDL;
    
    return 0;
}