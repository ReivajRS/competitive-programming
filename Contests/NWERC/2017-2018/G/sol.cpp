#include <bits/stdc++.h>
using namespace std;
// BRO... CSMS
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef double T;
int sgn(T x){return (T(0) < x)- (x<T(0));}
struct Point{
    T x,y;
    Point operator-(Point p) const { return {x-p.x,y-p.y};}

    T dot(Point p){return x*p.x+y*p.y;}
    T cross(Point p) const {return x*p.y-y*p.x;}
    T cross(Point a,Point b)const {return (a-*this).cross(b-*this);}
};
T orient(Point a,Point b,Point c){return a.cross(b,c);}

bool inDisk(Point a,Point b,Point p){return (a-p).dot(b-p) <= EPS;}

bool onSegment(Point a,Point b,Point p){
    return (abs(a.cross(b,p)) <= EPS && inDisk(a,b,p));
}

Point circlePoint(Point c,double r,double ang){
    return Point{c.x+cos(ang)*r,c.y+sin(ang)*r};
}

bool inPolygonCH(vector<Point> &l,Point p,bool strict = true){
    int a = 1,b = SZ(l)-1,r = !strict;
    if(SZ(l)<3)return r && onSegment(l[0],l.back(),p);
    if(orient(l[0],l[a],l[b]) > 0) swap(a,b);
    if(orient(l[0],l[a],p) >= r || orient(l[0],l[b],p)<=-r)
        return false;
    while(abs(a-b)>1){
        int c = (a+b)/2;
        (orient(l[0],l[c],p)> 0 ? b : a) = c;
    }
    return sgn(l[a].cross(l[b],p)) < r;
}

vector<Point> pts;
int n;

bool can(int k,double r){
    vector<Point> poly(k);
    double ang = 2*PI/k;
    FOR(i,0,k){
        poly[i] = (circlePoint({0,0},r,ang*i));
        //cout << poly[i].x << " " << poly[i].y << ENDL;
    }
    bool dentro = false;
    FOR(i,0,n){
        dentro |= inPolygonCH(poly,pts[i],true);
    }
    return !dentro;
}

bool can2(int k,double r){
    vector<Point> poly(k);
    double ang = 2*PI/k;
    FOR(i,0,k){
        poly[i] = (circlePoint({0,0},r,ang*i));
    }
    bool dentro = true;
    FOR(i,0,n){
        dentro &= (inPolygonCH(poly,pts[i],true));
    }
    return dentro;
}

double areaPolygon(int k,double r){
    vector<Point> poly(k);
    double ang = 2*PI/k;
    FOR(i,0,k){
        poly[i] = (circlePoint({0,0},r,ang*i));
    }
    double area = 0.0;
    FOR(i,0,k){
        area+= poly[i].cross(poly[(i+1)%k]);
    }
    return abs(area)/2;
}

double solve(int k){
    // buscar inner
    double l = 0.1,r = 1e7; 
    FOR(i,0,200){
        double mid = (l+r)/2;
        if(can(k,mid)){
            l = mid;
        }else{
            r = mid;
        }
    }

    cout << "in " << l << ENDL;

    double areainner = areaPolygon(k,l);

    // buscar outer
    l = 0,r = 1e7; 
    FOR(i,0,200){
        double mid = (l+r)/2;
        if(can2(k,mid)){
            r = mid;
        }else{
            l = mid;
        }
    }

    cout << "out " << l << ENDL;

    double areaouter = areaPolygon(k,r);
    //cout << areainner << " " << areaouter << ENDL;
    return areainner/areaouter;
}

signed main() {
    
    
    cin >> n;
    pts.resize(n);
    FOR(i,0,n){
        cin >> pts[i].x >> pts[i].y;
    }

    //cout << can(4,1);

    int ansK;
    double ans = 0;
    FOR(i,3,9){
        double curr = solve(i);
        if(curr > ans){
            ans = curr;
            ansK = i;
        }
    }
    cout << setprecision(10) << fixed;
    cout << ansK << " " << ans << ENDL;

    return 0;
}