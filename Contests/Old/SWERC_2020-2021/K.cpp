#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define SZ(x) (int)(x.size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MX = 3e5+2;

inline int add(int a, int b, const int &mod){return a + b >= mod ? a+b-mod:a+b;}
inline int sbt(int a,int b, const int &mod){return a-b < 0 ? a-b+mod:a-b;}
inline int mul(int a,int b,const int &mod){return 1ll * a * b % mod;}

const int X[] = {257,359};
const int MOD[]={(int)1e9+7,(int)1e9+9};
vector<int> xpow[2];

struct hashing{
    vi h[2];

    hashing() {

    }
    void init(string &s){
        int n = SZ(s);
        FOR(j,0,2){
            h[j].resize(n+1);
            FOR(i,1,n+1){
                h[j][i] = add(mul(h[j][i-1],X[j],MOD[j]),s[i-1],MOD[j]);
            }
        }
    }
    ll value(int l,int r){
        int a = sbt(h[0][r],mul(h[0][l],xpow[0][r-l],MOD[0]),MOD[0]);
        int b = sbt(h[1][r],mul(h[1][l],xpow[1][r-l],MOD[1]),MOD[1]);
        return (ll(a) << 32) +b;
    }
};

void calc_xpow(int mxlen = MX){
    FOR(j,0,2){
        xpow[j].resize(mxlen+1,1);
        FOR(i,1,mxlen+1){
            xpow[j][i] = mul(xpow[j][i-1],X[j],MOD[j]);
        }
    }
}
hashing h;
string s;

bool check(int x){
    unordered_map<ll,int> mapa;
    FOR(i,0,SZ(s)-x+1){
        ll val = h.value(i,i+x);
        mapa[val]++;
    }
    for(auto x:mapa){
        if(x.second == 1) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    calc_xpow();
    
    cin >> s;
    h.init(s);

    int low = 1,high=SZ(s);
    while(low<high){
        int mid = (high+low)/2;
        if(check(mid)){
            high = mid;
        }else{
            low = mid+1;
        }
    }

    unordered_map<ll,pi> mapa;
    FOR(i,0,SZ(s)-low+1){
        ll val = h.value(i,i+low);
        if(mapa.count(val)){
            mapa[val] = {mapa[val].first+1,mapa[val].second};
        }else{
            mapa[val] = {1,i};
        }
    }
    int ans = SZ(s)+100;
    for(auto x:mapa){
        if(x.second.first == 1){
            ans = min(ans,x.second.second);
        }
    }
    cout << s.substr(ans,low) << ENDL;

    return 0;
}