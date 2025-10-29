#include <bits/stdc++.h>
using namespace std;
// BRO... CSMS
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() {
    int n;
    cin >> n;
    
    vector<string> vs(n);
    FOR (i, 0, n) {
        cin >> vs[i];
    }
    
    int m;
    cin >> m;
    
    map<string, pair<ll, ll>> translations;
    map<string, string> mapa;
    FOR (i, 0, m) {
        string s, s2, s3;
        cin >> s >> s2 >> s3;
        mapa[s] = s2;
        if (s3 == "correct")
            translations[s].first++;
        else
            translations[s].second++;
    }
    
    ll correct = 1, total = 1;
    FOR (i, 0, n) {
        correct *= translations[vs[i]].first;
        total *= translations[vs[i]].first + translations[vs[i]].second;
    }

    if (total == 1) {
        for (auto &x : vs)
            cout << mapa[x] << ' ';
        cout << ENDL;
        if (correct == 1)
            cout << "correct" << ENDL;
        else
            cout << "incorrect" << ENDL;
        return 0;
    }

    cout << correct << " correct" << ENDL;
    cout << total - correct << " incorrect" << ENDL;
    return 0;
}