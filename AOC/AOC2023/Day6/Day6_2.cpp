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
    ll time, dist;
    string s;
    vector<string> sp;

    getline(cin, s);
    sp = split(s.substr(s.find(":")+1), " ");
    string w = "";
    for (auto &x : sp)
        w+=x;
    time = stoll(w);

    getline(cin, s);
    sp = split(s.substr(s.find(":")+1), " ");
    w = "";
    for(auto &x : sp)
        w+=x;
            
    dist = stoll(w);
    
    int cnt = 0;
    FOR(i, time+1) {
        if (i*(time-i) > dist)
            cnt++;
    }

    cout<<cnt<<ENDL;

    return 0;
}