#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using ld = long double;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

constexpr ld EPS = 1e-12;

typedef ld T;
struct Point{
    T x,y;

    Point operator+(Point p) const { return {x + p.x, y + p.y}; }
    Point operator-(Point p) const { return {x - p.x, y - p.y}; }
    Point operator*(T d) const { return {x * d, y * d}; }
    
    bool operator<(Point other) const {
        if(fabs(x-other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator==(Point other) const {return fabs(x - other.x) <= EPS && fabs(y - other.y) <= EPS;}
    bool operator!=(Point other) const {return !(*this == other);}
};

T sq(Point p){return p.x*p.x+p.y*p.y;}
Point toVector(Point p1,Point p2) {return p2-p1;}
T dot(Point v,Point w){return v.x*w.x+v.y*w.y;}
Point translate(Point v,Point p){return p+v;}
Point scale(const Point& v, ld s) { return Point{v.x * s, v.y * s}; }

T dist(Point p1,Point p2){return hypot(p1.x-p2.x,p1.y-p2.y);}

T nose(Point a,Point b,Point x){
    return max(dist(a,x),dist(b,x));
}

ld distToLine(Point a,Point b,Point p){
    Point ap = toVector(a,p),ab = toVector(a,b);
    ld u = dot(ap,ab) / sq(ab);
    Point c = translate(a,scale(ab,u));
    return dist(p,c);
}

ld distToLineSegment(Point a,Point b,Point p){
    Point ap = toVector(a,p),ab = toVector(a,b);
    ld u = dot(ap,ab)/sq(ab);
    if(u < 0.0) return dist(p,a);
    if(u > 1.0) return dist(p,b);
    return distToLine(a,b,p);
}

ll orientation(Point a,Point b,Point c){
    ld v = a.x * (b.y-c.y) + b.x * (c.y-a.y) + c.x * (a.y-b.y);
    if(v < 0 ) return -1;
    if(v > 0 ) return 1;
    return 0;
}

bool cw(Point a,Point b,Point c,bool include_collinear){
    ll o = orientation(a,b,c);
    return o < 0  || (include_collinear && o == 0);
}
bool ccw(Point a,Point b,Point c, bool include_collinear){
    ll o = orientation(a,b,c);
    return o > 0  || (include_collinear && o == 0);
}

vector<Point> convex_hull(vector<Point>& a,bool include_collinear = false){
    if(SZ(a) == 1) return a;
    sort(ALL(a));
    Point p1 = a[0],p2 = a.back();
    vector<Point> up,down;
    up.pb(p1);
    down.pb(p1);
    FOR(i,1,SZ(a)){
        if(i == SZ(a) -1 || cw(p1,a[i],p2,include_collinear)){
            while(SZ(up)>=2 && !cw(up[SZ(up)-2],up[SZ(up)-1],a[i],include_collinear))
                up.pop_back();
            up.pb(a[i]);
        }
        if(i == SZ(a)-1 || ccw(p1,a[i],p2,include_collinear)){
            while(SZ(down) >= 2 && !ccw(down[SZ(down)-2],down[SZ(down)-1],a[i],include_collinear))
                down.pop_back();
            down.pb(a[i]);
        }
    }

    if(include_collinear && SZ(up) == SZ(a)){
        reverse(ALL(a));
        return a;
    }
    vector<Point> ans;
    FOR(i,0,SZ(up))
        ans.pb(up[i]);
    for(ll i=SZ(down)-2;i>0;i--)
        ans.pb(down[i]);

    return ans;
}
T cross(Point v,Point w) {return v.x * w.y - v.y * w.x;}
ld area(Point p1,Point p2,Point p3){
    return cross(p2-p1,p3-p1)/2;
}



signed main() {__
    ll n;
    ld R;
    cin >> n >> R;
    vector<Point> pts(n);
    FOR(i,0,n){
        ld x,y;
        cin >> x >> y;
        pts[i] = {x,y};
    }
    vector<Point> convex = convex_hull(pts,true);
    ld ans = R *2;
    ll j = 2;
    ll n2 = SZ(convex);

    if(n2 <= 2){
        cout << 0 << ENDL;
        return 0;
    }
    
    FOR(i,0,n2){
        while (distToLineSegment(convex[i],convex[(i+1)%n2],convex[j]) < distToLineSegment(convex[i],convex[(i+1)%n2],convex[(j+1)%n2]))
            j = (j + 1) % n2;

        ld res = distToLineSegment(convex[i],convex[(i+1)%n2],convex[j]);
        ans = min(ans,res);
    }
    cout << setprecision(15) << fixed;
    cout << ans << ENDL;

    return 0;
}