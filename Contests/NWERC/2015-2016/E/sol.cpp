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

bool dfs(ll a, ll L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (ll b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B)) return btoa[b] = a, 1;
	}
	return 0;
}

pair<ll,vi> hopcroftKarp(vector<vi>& g,ll m){
    ll res = 0;
    vi btoa(m,-1),A(SZ(g)),B(m),cur,next;
    while(1){
        fill(ALL(A),0);
        fill(ALL(B),0);
        cur.clear();
        for(ll a:btoa) if(a!=-1) A[a] = -1;
        FOR(a,0,SZ(g)) if(A[a] == 0) cur.pb(a);
        for(ll lay=1;;lay++){
            bool islast = 0;
            next.clear();
            for(ll a:cur) for(ll b:g[a]){
                if(btoa[b] == -1){
                    B[b] = lay;
                    islast = 1;
                }else if(btoa[b] != a && !B[b]){
                    B[b] = lay;
                    next.pb(btoa[b]);
                }
            }
            if(islast) break;
            if(next.empty()) return {res,btoa};
            for(ll a:next)A[a] = lay;
            cur.swap(next);
        }
        FOR(a,0,SZ(g))res+=dfs(a,0,g,btoa,A,B);
    }
    return {res,btoa};
}

signed main () { __
    
    map<ll,ll> mapa;
    map<pi,string> mapa2;
    ll n;
    cin >> n;
    vector<vi> g(n,vi());
    FOR(i,0,n){
        ll x,y;
        cin >> x >> y;
        ll res = x+y;
        if(!mapa.count(res)){
            mapa[res] = SZ(mapa);
        }
        mapa2[{i,mapa[res]}] = to_string(x) + " + " + to_string(y) + " = " + to_string(res);
        g[i].pb(mapa[res]);
        res = x-y;
        if(!mapa.count(res)){
            mapa[res] = SZ(mapa);
        }
        mapa2[{i,mapa[res]}] = to_string(x) + " - " + to_string(y) + " = " + to_string(res);
        g[i].pb(mapa[res]);
        res = x*y;
        if(!mapa.count(res)){
            mapa[res] = SZ(mapa);
        }
        mapa2[{i,mapa[res]}] = to_string(x) + " * " + to_string(y) + " = " + to_string(res);
        g[i].pb(mapa[res]);
    }

    pair<ll,vi> ans = hopcroftKarp(g,SZ(mapa));
    if(ans.first != n){
        cout << "impossible" << ENDL;
        return 0;
    }
    vi ans2 = ans.second;
    FOR(i,0,n){
        for(auto v:g[i]){
            if(ans2[v] == i){
                cout << mapa2[{i,v}] << ENDL;
                break;
            }
        }
    }


    return 0;
}