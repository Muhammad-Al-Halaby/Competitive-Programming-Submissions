#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int fr[N];

bool sieve(){
    vector<int> prime(N, 1);
    for(int i = 2;i < N;i++){
        if(prime[i]){
            int setwise = 0;
            for(int j = i;j < N;j += i){
                setwise += fr[j];
                prime[j] = 0;
            }
            if(setwise > 1) return 0;
        }
    }
    return 1;
}

void go(int tc = 0){
    int n;  cin >> n;

    int g = 0;
    for(int i = 0, x;i < n;i++)    cin >> x, g = __gcd(g, x), fr[x]++;

    if(sieve())
        cout << "pairwise coprime";
    else if(g == 1)
        cout << "setwise coprime";
    else
        cout << "not coprime";
}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
//   cin >> t;
    while(t--)
        go(tc++);
}