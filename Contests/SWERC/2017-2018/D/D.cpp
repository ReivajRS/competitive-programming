#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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

struct vertex{
    map<char,ll> next,go;
    ll p,link;
    char pch;
    vi leaf;
    vertex(ll p=-1,char pch=-1): p(p),pch(pch),link(-1){}
};
vector<vertex> t;
void aho_init(){
    t.clear();t.pb(vertex());
}
void add_string(string s,ll id){
    ll v = 0;
    for(char c:s){
        if(!t[v].next.count(c)){
            t[v].next[c]=SZ(t);
            t.pb(vertex(v,c));
        }
        v = t[v].next[c];
    }
    t[v].leaf.pb(id);
}
ll go(ll v,char c);
ll get_link(ll v){
    if(t[v].link<0)
        if(!v||!t[v].p)t[v].link=0;
        else t[v].link=go(get_link(t[v].p),t[v].pch);
    return t[v].link;
}
ll go(ll v,char c){
    if(!t[v].go.count(c))
        if(t[v].next.count(c)) t[v].go[c]=t[v].next[c];
        else t[v].go[c]=v==0?0:go(get_link(v),c);
    return t[v].go[c];
}

vi buscar(ll estado){
    if(estado == 0) return {};
    vi res(t[estado].leaf);
    vi aux = buscar(get_link(estado));
    res.insert(res.end(), ALL(aux));
    return res;
}

ll dp[10005][55];
ll n,m;
vi est,p;
string s;
vector<string> pat;

ll solve(ll estado,ll i){
    if(i == n) return 0;
    ll &ans = dp[estado][i];
    if(ans != -1) return ans;
    ans = solve(go(estado,s[i]),i+1);
    vi aaa = buscar(estado);
    for(auto x:aaa){
        x%=m;
        cout << p[x] << ENDL;
        ans = max(ans,solve(go(est[i-SZ(pat[x])],s[i]),i+1) + p[x]);
    }
    return ans;
}

signed main() {__
    aho_init();
    memset(dp,-1,sizeof(dp));

    cin >> s;
    cin >> m;
    n = SZ(s);
    est.resize(n+1);
    p.resize(m);
    pat.resize(m);
    FOR(i,0,m){
        string s2;
        ll x;
        cin >> s2 >> x;
        pat[i] = s2;
        p[i] = x;
        add_string(s2,i);
        reverse(ALL(s2));
        add_string(s2,i+m);
    }

    ll e = 0;
    est[0] = 0;
    FOR(i,0,n){
        e = go(e,s[i]);
        est[i+1] = e;
    }
    /*FOR(i,0,n+1){
        vi aaa = buscar(est[i]);
        cout << i << "---" << ENDL;
        for(auto aa:aaa){
            cout << aa << " ";
        }
        cout << ENDL;
    }*/

    cout << solve(0,0) << ENDL;

    return 0;
}