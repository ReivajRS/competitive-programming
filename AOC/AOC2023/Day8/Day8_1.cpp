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
    string moves, line;
    cin>>moves;

    unordered_map<string, pair<string, string>> umap;

    while (getline(cin, line)) {
        if (line.length() == 0)
            continue;

        string src = line.substr(0, 3), l = line.substr(7, 3), r = line.substr(12, 3);
        umap[src] = {l, r};
    }

    int cnt = 0, pos = 0;
    string act = "AAA";

    while (act != "ZZZ") {
        FOR(pos, moves.length()) {
            act = moves[pos] == 'L' ? umap[act].first : umap[act].second;
            cnt++;
        }
    }

    cout<<cnt<<ENDL;

    return 0;
}