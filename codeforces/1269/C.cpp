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
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2005, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();

    int n, k;   cin >> n >> k;
    string a, b;    cin >> a;

    b = a;

    for(int i = 0;i < n;i++)    b[i] = ((i - k >= 0) ? b[i - k] : b[i]);

    auto ok = [&](){
        for(int i = 0;i < n;i++)
            if(b[i] > a[i]) return 1;
            else if(b[i] < a[i])  return 0;
        return 1;
    };



    while(!ok()){
        int pos = k - 1;
        while(b[pos] == '9'){
            for(int i = pos;i < n;i += k)   b[i] = '0';
            pos--;
        }
        for(int i = pos;i < n;i+=k) b[i] += 1;
    }

    cout << n << '\n' << b;
}