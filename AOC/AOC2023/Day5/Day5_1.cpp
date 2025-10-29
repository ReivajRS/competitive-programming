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

#include </home/javier/Escritorio/CompetitiveProgramming/AOC2023/utility.h>

int main(){_
    string s;

    vector<ll> seeds;
    getline(cin, s);

    vector<string> sp = split(s.substr(s.find(":")+1), " ");
    for(auto u : sp)
        seeds.push_back(stoll(u));
    
    vector<tuple<ll, ll, ll>> ranges;

    bool flag = false;
    while (getline(cin, s)) {
        if (!isdigit(s[0]) || s.length() == 0) {
            if (!flag)
                continue;

            for (auto &v : seeds) {
                for(auto &[a, b, c] : ranges) {
                    if (v >= b && v < b+c){
                        v += (a-b);
                        break;
                    }
                }
            }

            // for (auto u : seeds) {
            //     deb(u);
            // }

            flag = false;
            ranges.clear();
            continue;
        }

        flag = true;
        sp = split(s, " ");
        FOR(i, 3)
            ranges.push_back({stoll(sp[0]), stoll(sp[1]), stoll(sp[2])});
    }

    if (flag)
        for (auto &v : seeds) {
            for(auto &[a, b, c] : ranges) {
                if (v >= b && v < b+c){
                    v += (a-b);
                    break;
                }
            }
        }

    // for (auto u : seeds) {
    //     deb(u);
    // }
    cout<<*min_element(all(seeds))<<ENDL;

    return 0;
}