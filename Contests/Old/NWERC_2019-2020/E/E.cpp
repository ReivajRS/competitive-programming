#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { __
    vi arr;
    FOR(i,0,4){
        string s;
        cin >> s;
        if(s[1] == '.'){
            s = s.erase(1,1);
        }else{
            s = s.erase(2,1);
        }
        arr.pb(stoi(s));
    }
    string s;
    cin >> s;
        if(s[1] == '.'){
            s = s.erase(1,1);
        }else{
            s = s.erase(2,1);
        }
    int prom = (stoi(s));
    prom*=3;
    int ans = 100;
    int ant = -1;
    while(ans <= 2000){
        vector<int> arr2(arr);
        arr2.pb(ans);
        sort(ALL(arr2));
        int prueba = (arr2[1]+arr2[2]+arr2[3]);
        if(prueba > prom){
            ant =  ans-1;
            if(ant < 100){
                cout << "impossible" << ENDL;
                return 0;
            }
            
            cout << setprecision(2) << fixed;
            cout << ant/100.0 << ENDL;
            return 0;
        }
        ans++;
    }
    cout << "infinite" << ENDL;

    return 0;
}