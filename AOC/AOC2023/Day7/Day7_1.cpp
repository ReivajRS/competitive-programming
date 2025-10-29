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

unordered_map<char, char> replaces = {{'A', 'Z'}, {'K', 'Y'}, {'Q', 'X'}, {'J', 'W'}, {'T', 'V'}};

int typeOfHand(string &hand) {
    unordered_map<char, int> umap;
    int hightestCount = 0, secondCount = 0;
    for (auto &c : hand) {
        if (replaces.count(c))
            c = replaces[c];
        umap[c]++;
        if (umap[c] > hightestCount) {
            hightestCount = umap[c];
            continue;
        }
        if (umap[c] > secondCount) {
            secondCount = umap[c];
        }
    }

    if (hightestCount == 5)
        return 7;
    if (hightestCount == 4)
        return 6;
    if (hightestCount == 3 && secondCount == 2)
        return 5;
    if (hightestCount == 3)
        return 4;
    if (hightestCount == 2 && secondCount == 2)
        return 3;
    if (hightestCount == 2)
        return 2;
    return 1;

}

int main(){_
    string hand;
    int bid;

    vector<tuple<int, string, int>> hands;

    while (cin>>hand>>bid) {
        hands.push_back({typeOfHand(hand), hand, bid});
        deb(get<0>(hands.back()));
    }

    sort(all(hands));

    ll sum = 0;

    // FOR(i, sz(hands)) {
    //     sum += (sz(hands)-i)*get<2>(hands[i]);
    // }

    FORR(i, sz(hands)-1, 0) {
        sum += (i+1)*get<2>(hands[i]);
    }

    cout<<sum<<ENDL;

    return 0;
}