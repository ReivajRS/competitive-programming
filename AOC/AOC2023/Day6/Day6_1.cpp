#include <bits/stdc++.h>
#include </home/javier/Escritorio/CompetitiveProgramming/AOC2023/utility.h>
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
    vi times;
    vi distances;
    string s;
    vector<string> sp;

    getline(cin, s);
    sp = split(s.substr(s.find(":")+1), " ");
    for(auto &x : sp)
        times.push_back(stoi(x));

    getline(cin, s);
    sp = split(s.substr(s.find(":")+1), " ");
    for(auto &x : sp)
        distances.push_back(stoi(x));

    int ans = 1;
    FOR(i, sz(times)) {
        int cnt = 0;
        FORE(j, 0, times[i]) {
            if (j*(times[i]-j) > distances[i]) {
                cnt++;
            }
        }
        ans*=cnt;
    }

    cout<<ans<<ENDL;

    return 0;
}