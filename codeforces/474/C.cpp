#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
//const double EPS = 1E-7, PI = acos(-1);


typedef complex<double> point;
#define EPS 1e-8
#define PI acos(-1)
#define X real()
#define Y imag()
#define vec(a,b) 	((b) - (a))
#define polar(r,t) 	((r) * exp(point(0, (t))))
#define angle(v) 	(atan2((v).Y, (v).X))
#define length(v) 	((double)hypot((v).Y, (v).X))
#define lengthSqr(v) 	(dot(v, v))
#define dot(a,b) 	((conj(a) * (b)).real())
#define cross(a,b) 	((conj(a) * (b)).imag())
#define rotate(v,t) 	(polar(v, t))
#define rotateabout(v,t,a)  (rotate(vec(a, v), t) + (a))

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int dcmp(double x, double y){
    return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int n;
vector<pair<point, point>> v;

struct cmp {
	bool operator ()(double a, double b) {
		if (dcmp(a, b) == -1)
			return 1;
		return 0;
	}
};

bool check(){
    set<double, cmp> s;
    for(int i = 0;i < 4;i++){
        for(int j = i + 1;j < 4;j++){
            s.insert(length(vec(v[i].F, v[j].F)));
        }
    }

    if(s.size() != 2)   return 0;
    return !dcmp(hypot(*s.begin(), *s.begin()), *s.rbegin());
}

int solve(int i){
    if(i == 4)
        return (check() ? 0 : OO);

    int ret = OO;
    for(int j = 0;j < 4;j++){
        ret = min(ret, j + solve(i + 1));
        v[i].F = rotateabout(v[i].F, PI / 2.0, v[i].S);
    }

    return ret;
}

int main(){
    init();

    cin >> n;
    for(int i = 0;i < 4 * n;i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        v.push_back({{a, b}, {c, d}});
        if(v.size() == 4){
            int ans = solve(0);
            cout << (ans == OO ? -1 : ans) << '\n';
            v.clear();
        }
    }
}