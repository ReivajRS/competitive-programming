#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define SZ(x) (int)(x.size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;
    string s;
    map<string, pair<int, int>> mapa;
    getline(cin,s);
    FOR(i,0,3*n){
        getline(cin,s);
        mapa[s].first++;
        mapa[s].second = i + 1;
    }

    set<tuple<int, int, string>> st;

    for(auto x:mapa){
        st.insert({-x.second.first, -x.second.second, x.first});
    }

    for (auto [a, b, c] : st) {
        if (k-- == 0)
            break;
        cout << c << ENDL;
    }

    return 0;
}