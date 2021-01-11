#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 1e5+5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int flip[N];
int main(){
    init();

    int n;  cin >> n;
    double a[n];
    ll sum = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += ceil(a[i]);
    }

    for(int i = 0;sum && i < n;i++){
        if(fabs((int)a[i] - a[i]) == 0)    continue;
        flip[i] = 1;
        sum--;
    }

    for(int i = 0;i < n;i++)
        if(flip[i]) cout << (int)floor(a[i]) << '\n';
        else cout << (int)ceil(a[i]) << '\n';
}