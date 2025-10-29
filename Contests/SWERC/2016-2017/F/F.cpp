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
#define ROF(i, a, b) for (ll i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(nullptr);

constexpr ll MAX = 2e5+5;

ll n,bit[MAX];
ll cnt = 1;

ll query(ll index){
    ll sum = 0;
    while(index > 0){
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}

ll query(ll i,ll j){
    return query(j) - query(i-1);
}

void add (ll index,ll val){
    while(index < MAX){
        bit[index] += val;
        index += index & (-index);
    }
}

vector<vi> g;
vector<pi> euler;

void dfs(ll x){
    euler[x].first = cnt++;
    for(auto v:g[x]){
        dfs(v);
    }
    euler[x].second = cnt++;
}

vi rangos[MAX];

signed main() { __
    
    cin >> n;
    g.assign(n+1,vi());
    euler.resize(n+1);
    vector<pi> datos(n+1);
    ll root;
    FOR(i,1,n+1){
        ll v,r,w;
        cin >> v >> r >> w;
        datos[i] = {r,w};
        if(v != -1){
            g[v].pb(i);
        }else{
            root = i;
        }
        rangos[r].pb(i);
    }
    dfs(root);


    //cout << euler[3].first << " " << euler[3].second << ENDL;
    
    vi ans(n+1,0);
    FOR(i,0,MAX){
        FOR(j,0,SZ(rangos[i])){
            ans[rangos[i][j]] = query(euler[rangos[i][j]].first,euler[rangos[i][j]].second);
        }
        FOR(j,0,SZ(rangos[i])){
            add(euler[rangos[i][j]].first,datos[rangos[i][j]].second);
        }
    }

    FOR(i,1,n+1){
        cout << ans[i] << ENDL;
    }

    return 0;
}