#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

void solve(){
    int n,m;
    cin >> n >> m;
    vi grado(n,0);
    vector<pi> calles(m);
    FOR(i,0,m){
        int x,y;
        cin >> x >> y;
        x--;y--;
        grado[x]++;
        grado[y]++;
        calles[i] = {x,y};
    }

    int nodo = -1;
    FOR(i,0,n){
        if(grado[i] != n-1){
            nodo = i;
            break;
        } 
    }
    if(nodo == -1){
        cout << 3 << ENDL;
        FOR(i,0,m){
            if(calles[i].first == 0 || calles[i].second == 0){
                if(calles[i].first == 1 || calles[i].second == 1) cout << 1 << " ";
                else cout << 2 << " ";
            }else{
                cout << 3 << " ";
            }
        }
    }else{
        cout << 2 << ENDL;
        FOR(i,0,m){
            if(calles[i].first == nodo || calles[i].second == nodo){
                cout << 1 << " ";
            }else{
                cout << 2 << " ";
            }
        }
    }
    cout << ENDL;
}

int main() {__
    int t;
    cin >> t;
    while(t--) solve();
}