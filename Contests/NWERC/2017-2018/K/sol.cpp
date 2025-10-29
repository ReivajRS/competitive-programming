#include <bits/stdc++.h>
using namespace std;
// BRO... CSMS
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

ll l(ll p) {return (p<<1)+1;}
ll r(ll p){return (p<<1)+2;}

vector<ll> rating;

struct Node{
    map<ll,double> par;
    bool vacio;
    Node(){vacio=false;}
    Node(ll id){
        if (rating[id] == 0){
            vacio = true;
            return;
        }
        vacio = false;
        par[id] = 1.0;
    }
};

vector<Node> st(20000);

Node unir(Node a,Node b){
    if(b.vacio) return a;
    if(a.vacio) return b;
    Node res;
    for(auto[ai,ap]:a.par){
        for(auto[bi,bp]:b.par){
                double ganar = (double)rating[ai]/(rating[ai]+rating[bi]);
                res.par[ai] += (ganar*ap*bp);
 
                ganar = (double)rating[bi]/(rating[ai]+rating[bi]);
                res.par[bi] += (ganar*ap*bp);
        }
    }
    return res;
}

void build(ll index,ll start,ll end){
    if(start == end)
        st[index] = Node(start);
    else{
        ll mid = (start+end)/2;
        build(l(index),start,mid);
        build(r(index),mid+1,end);

        st[index] = unir(st[l(index)],st[r(index)]);
    }
}

signed main() {

    ll n;
    cin >> n;
    rating.resize(n);
    FOR(i,0,n){
        cin >> rating[i];
    }
    
    ll cnt = 0;
    while (__builtin_popcount(n) != 1) {
        n++;
        cnt++;
    }
    sort(1 + ALL(rating));
    
    for (ll i = cnt - 1; i >= 0; i--) {
        rating.insert(rating.begin() + i + 1, 0);
    }
    build(0,0,n-1);
    cout << setprecision(9) << fixed << st[0].par[0] << ENDL;

    return 0;
}