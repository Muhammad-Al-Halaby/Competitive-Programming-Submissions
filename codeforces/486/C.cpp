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

const int N = 100, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int freq[10] = {0};

vector<int> x[3];


void print(){
    int s = accumulate(freq, freq + 10, 0);
    if(!s || !freq[0])  cout << -1;
    else if(s == freq[0]) cout << 0;
    else for(int i = 9;~i;i--)  for(int j = 0;j < freq[i];j++)  cout << i;
    exit(0);
}

int n;
int mid(){
    return n / 2 - (n % 2 == 0);
}

int main(){
    init();

    int p;   cin >> n >> p;  p--;
    string s;   cin >> s;


    ll ans = 0;
    for(int i = 0;i * 2 < n;i++){
        int d = abs(s[i] - s[n - i - 1]);
        ans += min(d, 26 - d);
    }

    int i = p+1, j = p, k = p;
    while(i < n){
        if(s[i] != s[n - i - 1])    j = i;
        if(i == mid())  break;
        i++;
    }

    i = p-1;
    while(~i){
        if(s[i] != s[n - i - 1])    k = i;
        if(i == n - mid() - 1)  break;
        i--;
    }

    if(p == mid() || p == n - mid() - 1)  ans += min(abs(p - j), abs(p - k));
    else ans += max(abs(p - j), abs(p - k)) + 2 * min(abs(p - j), abs(p - k));

    cout << ans;
}