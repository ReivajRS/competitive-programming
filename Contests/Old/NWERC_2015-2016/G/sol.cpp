#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

struct node{
    int x,y,z;
};

vector<node> nodos;

signed main () { __
    
    ll n;
    cin >> n;
    vi a(n),b(n),c(n);
    vi idxA(n+1),idxB(n+1),idxC(n+1);
    FOR(i,0,n){
        cin >> a[i];
        idxA[a[i]] = i+1;
    }

    FOR(i,0,n){
        cin >> b[i];
        idxB[b[i]] = i+1;
    }

    FOR(i,0,n){
        cin >> c[i];
        idxC[c[i]] = i+1;
    }
    nodos.resize(n+1);
    FOR(i,1,n+1){
        nodos[i].x = idxA[i];
        nodos[i].y = idxB[i];
        nodos[i].z = idxC[i];
    }

    FOR(i,1,n+1){
        cout << nodos[i].x <<" " << nodos[i].y << " " << nodos[i].z << ENDL;
    }

    return 0;
}