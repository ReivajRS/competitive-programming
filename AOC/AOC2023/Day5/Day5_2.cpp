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

typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> range;

vector<ll> seeds;
vector<pll> pairs;
vector<range> ranges;
map<pll, ll> diff;
vector<pll> convertRanges;

void convert() {
    vector<pll> nextPairs;
    sort(all(convertRanges));
    pll bck = convertRanges.back();
    convertRanges.push_back({convertRanges[0].second-1, -INF});
    diff[convertRanges.back()] = 0;
    convertRanges.push_back({INF, bck.first+1});
    diff[convertRanges.back()] = 0;
    sort(all(convertRanges));

    for (auto p : pairs) {
        int pos = lower_bound(all(convertRanges), p) - convertRanges.begin();
        ll delta = diff[convertRanges[pos]];
        if (p.second >= convertRanges[pos].second) {
            nextPairs.push_back({p.first + delta, p.second + delta});
        }
        else {
            nextPairs.push_back({p.first + delta, convertRanges[pos].second + delta});
            bool contained = false;

            while (!contained) {
                pll rp = {convertRanges[pos].second-1, p.second};
                pos--;
                delta = diff[convertRanges[pos]];
                if (rp.second >= convertRanges[pos].second) {
                    nextPairs.push_back({rp.first + delta, rp.second + delta});
                    contained = true;
                }
                else {
                    nextPairs.push_back({rp.first + delta, convertRanges[pos].second + delta});
                }
            }
        }
    }

    pairs = nextPairs;
}

int main(){_
    string s;

    getline(cin, s);

    vector<string> sp = split(s.substr(s.find(":")+1), " ");
    for(auto u : sp)
        seeds.push_back(stoll(u));

    pairs.resize(sz(seeds)/2);
    FOR(i, sz(pairs)) {
        ll a = stoll(sp[i*2+1]), b = stoll(sp[i*2]);
        pairs[i] = {b+a-1, b};
    }

    bool flag = false;
    while (getline(cin, s)) {
        if (!isdigit(s[0]) || s.length() == 0) {
            if (!flag)
                continue;

            convert();
            
            flag = false;
            convertRanges.clear();
            continue;
        }

        flag = true;
        sp = split(s, " ");
        ll a = stoll(sp[0]), b = stoll(sp[1]), c = stoll(sp[2]);
        convertRanges.push_back({b+c-1, b});
        diff[convertRanges.back()] = a-b;
    }

    convert();

    ll mini = INF;
    for (auto &[a, b] : pairs){
        mini = min(mini, b);
    }

    cout<<mini<<ENDL;

    return 0;
}