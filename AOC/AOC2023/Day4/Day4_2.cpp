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
    string s;

    ll ans = 0;

    unordered_map<int, int> mapaCnt;

    int i = 1;

    mapaCnt[1] = 1;

    while (getline(cin, s)) {
        ll sC = s.find(':'), bar = s.find('|');
        stringstream ss1(s.substr(sC+1, bar-sC-1)), ss2(s.substr(bar+1));
        string w;
        unordered_set<int> s1, s2;

        while(ss1>>w)
            s1.insert(stoi(w));
        while(ss2>>w)
            s2.insert(stoi(w));
        
        ll cnt = 0;
        for (int u : s2)
            cnt += s1.count(u);

        if (mapaCnt[i] == 0)
                mapaCnt[i] = 1;

        FORE(j, i+1, i+cnt){
            if (mapaCnt[j] == 0)
                mapaCnt[j] = 1;
            mapaCnt[j] += mapaCnt[i];
        }
        
        i++;
    }

    for(auto &[x, y] : mapaCnt) {
        if (x > i)
            break;
        ans += y;
    }

    cout<<ans<<ENDL;
    
    return 0;
}