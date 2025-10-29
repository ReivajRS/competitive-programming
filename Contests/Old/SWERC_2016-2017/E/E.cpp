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

struct vertex {
	map<char,ll> next,go;
	ll p,link;
	char pch;
	vector<ll> leaf;
	vertex(ll p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.push_back(vertex());
}
void add_string(string s, ll id){
	ll v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.push_back(vertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.push_back(id);
}
ll go(ll v, char c);
ll get_link(ll v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
ll go(ll v, char c){
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}

bool buscar(ll estado){
    if(estado == 0) return true;
    if(SZ(t[estado].leaf) != 0) return false;
    return buscar(get_link(estado));
}

ll l,r;
ll dp[25][10005][8];
constexpr ll MOD = 1000003;

ll solve(ll i,ll estado,ll mask){
    if(i>r) return 0;
    ll &ans = dp[i][estado][mask];
    if(ans != -1) return ans;

    ans = (i >= l && mask == 7);

    for(char c = 'a'; c <= 'z';c++){
        ll next = go(estado,c);
        if(buscar(next)){
            ans += solve(i+1,next,mask|1);
            ans%=MOD;
            ans += solve(i+1,next,mask|2);
            ans%=MOD;
        }
    }

    for(char c = '0';c<='9';c++){
        ll next = 0;
        if(c == '0') next = go(estado,'o'); 
        else if(c == '1') next = go(estado,'i');
        else if(c == '3') next = go(estado,'e');
        else if(c == '5') next = go(estado,'s');
        else if(c == '7') next = go(estado,'t');

        if(buscar(next)){
            ans += solve(i+1,next,mask|4);
            ans%=MOD;
        }
    }
    ans%=MOD;

    return ans;
}

signed main() { __
    memset(dp,-1,sizeof(dp));

    aho_init();
    cin >> l >> r;
    ll n;
    cin >> n;
    FOR(i,0,n){
        string s;
        cin >> s;
        add_string(s,i+1);
    }

    cout << solve(0,0,0) << ENDL;
    
    return 0;
}