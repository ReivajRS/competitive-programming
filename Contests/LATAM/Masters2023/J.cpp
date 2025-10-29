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

#pragma GCC target ("sse4.2")   // Acelara la funcion popcount
#define ones(x) __builtin_popcount(x)

int n,k,f;
int i_f[51];
int dp[51][51];

int solve(int ing, int count){
    if(count==k)            return 0;
    if(ing==n)              return -1;
    if(dp[ing][count]!=-1)  return dp[ing][count];

    int ans=0;
    int tomar=(solve(ing+1, count+1)|i_f[ing]);
    int noTomar=solve(ing+1, count);

    if((f-ones(tomar))>=(f-ones(noTomar)))
        ans=tomar;
    else
        ans=noTomar;

    return dp[ing][count]=ans;
}

//El bit i representa si ese ingrediente le gusta al i amigo
//1 significa que no le gusta, 0 significa que si
int main(){_
    memset(dp,-1,sizeof dp);
    int d,num;
    cin>>n>>k>>f;
    FOR(i,f){
        cin>>d;
        FOR(j,d){
            cin>>num;
            i_f[num-1]|=(1<<i);
        }
    }
    cout<<f-ones(solve(0,0))<<ENDL;
    return 0;
}