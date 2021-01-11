#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(a,n) for(int i = a;i<n;i++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int fr[100][26];

int main(){
    init();
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        for(int j = 0;j < m;j++)
            fr[j][s[j]-'A']++;
    }

    ll ans = 1;
    for(int i = 0;i < m;i++){
        int c = 0;
        for(int j = 0;j < 26;j++){
            c += (fr[i][j] != 0);
        }
        ans = (ans * c) % modulo;
    }

    cout << ans;
}