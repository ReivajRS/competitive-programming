#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define all(s) begin(s), end(s)
#define rall(n) n.rbegin(), n.rend()
#define FOR(x, b) for(int x = 0; x <b; x++)
#define FORE(x, a, b) for(int x = a; x <= b; x++)
#define FORR(x, a, b) for(int x = a; x >= b; x--)
#define deb(x)      cerr << #x << " = " << x << '\n';
#define deb2(x, y)  cerr << #x << " = " << x << ", " << #y << " = " << y << '\n';
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ll MOD = 1e9+7, INF=1e18;
const int MAXN=1e5+1;
 
int main(){_
    int x;
    cin>>x;
    vector<ll> posibles;
    unordered_set<ll> cuadrados;
    FORE(i,1,MAXN)
        cuadrados.insert(1LL*i*i);
    for(auto c:cuadrados){
        if(cuadrados.count(c+x))
            posibles.push_back((ll)sqrt(c+x));
    }
    sort(all(posibles));
    cout<<posibles.size()<<ENDL;
    FOR(i,posibles.size()){
        if(i==posibles.size()-1)
            cout<<posibles[i];
        else
            cout<<posibles[i]<<" ";
    }
    return 0;
}