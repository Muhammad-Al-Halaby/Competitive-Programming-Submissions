#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef pair<ll,ll> pll;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

const int N = 1e3 + 5, M = 600, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int main(){
    init();

    string s;   cin >> s;
    int q;  cin >> q;
    set<int> alpha[26];

    for(int i = 0;i < s.size();i++)
        alpha[s[i] - 'a'].insert(i);

    while(q--){
        int type;   cin >> type;
        if(type == 1){
            int pos;    cin >> pos; --pos;
            char c = s[pos];
            auto it = alpha[c - 'a'].find(pos);
            alpha[c - 'a'].erase(it);
            cin >> c;
            s[pos] = c;
            alpha[c - 'a'].insert(pos);
        }
        else{
            int l, r;   cin >> l >> r;  --l, --r;
            int ans = 0;
            for(int i = 0;i < 26;i++){
                auto it = alpha[i].lower_bound(l);
                if(it == alpha[i].end())    continue;
                ans += (*it <= r);
            }
            cout << ans << '\n';
        }
    }
}