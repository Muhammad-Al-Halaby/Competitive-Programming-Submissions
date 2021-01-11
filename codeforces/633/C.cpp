#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

ll MOD = (1e9 + 7);
ll BASE = 257;

ll fastPow(ll b, ll e){
    if(e == 0)
        return 1;
    ll partial = fastPow(b,e/2);
    partial = (partial * partial) % MOD;
    if(e & 1)
        partial = (partial * b) % MOD;
    return partial;
}

ll shiftLeft(ll hashCode){
    return ((hashCode % MOD) * (BASE % MOD) % MOD);
}

ll addAt(ll hashCode, int idx, int val){
    return (hashCode % MOD + (fastPow(BASE,idx) * val) % MOD ) % MOD;
}

ll removeAt(ll hashCode, int idx, int val){
    return (hashCode % MOD - (fastPow(BASE,idx) * val) % MOD + MOD) % MOD;
}

int n, m;
string s;
unordered_map<ll, int> mp;
int dp[10005][1005];
string arr[100005];
queue<string> words;

int solve(int idx, int len, int searchCode){
    if(idx == n)
        return 1;

    if(idx + len > n || len > 1000)
        return 0;

    if(dp[idx][len] != -1)
        return dp[idx][len];

    searchCode = shiftLeft(searchCode);
    searchCode = addAt(searchCode, 0, s[idx+len-1]);

    if(mp[searchCode] && solve(idx+len,1,0)){
        words.push(arr[mp[searchCode]-1]);
        return dp[idx][len] = 1;
    }

    return dp[idx][len] = solve(idx,len+1,searchCode);
}

int main(){
    init();

    cin >> n >> s >> m;

    reverse(s.begin(),s.end());

    for(int i = 0;i < m;i++){
        cin >> arr[i];
        ll patCode = 0;
        for(int j = 0;j < arr[i].size();j++){
            patCode = shiftLeft(patCode);
            patCode = addAt(patCode, 0, tolower(arr[i][j]));
        }
        mp[patCode] = i+1;
    }
    memset(dp,-1,sizeof dp);
    solve(0,1,0);

    while(!words.empty()){
        cout << words.front() << " ";
        words.pop();
    }
}
