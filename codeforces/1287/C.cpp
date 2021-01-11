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

const int N = 105, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int n, dp[N][N][N][3];
int arr[N], pt[N];
int solve(int i, int evenlft, int oddleft, int prevParity){
    if(i == n)  return 0;
    int &ret = dp[i][evenlft][oddleft][prevParity];
    if(~ret)    return ret;

    ret = 1e9;
    if(arr[i] != 0)
        return ret = (pt[i] != prevParity) + solve(i + 1, evenlft, oddleft, pt[i]);

    if(oddleft)
        ret = (prevParity != 1) + solve(i + 1, evenlft, oddleft - 1, 1);

    if(evenlft)
        ret = min(ret, (prevParity != 0) + solve(i + 1, evenlft - 1, oddleft, 0));

    return ret;
}

int main(){
    init();

    cin >> n;
    int e = n / 2, o = n / 2 + (n & 1);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        int p = (arr[i] & 1);
        pt[i] = p;
        if(arr[i] == 0) continue;
        e -= !p;
        o -= p;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, e, o, 2) - 1;
}