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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int main(){
    init();

    int n;  cin >> n;
    string s;   cin >> s;
    int parity = 0, moves = 0, ans[n] = {0};
    stack<char> st;
    st.push(s[0]);
    for(int i = 1;i < n;i++){
        if(parity & 1){
            st.push(s[i]);
            parity ^= 1;
        }
        else{
            if(s[i] != st.top()){
                st.pop();
                parity ^= 1;
            }
            else{
                ans[i] = 1;
                moves++;
            }
        }
    }
    if((n - moves) & 1){
        moves++;
        for(int i = n - 1;i >= 0;i--)
            if(!ans[i]){ans[i] = 1; break;}
    }
    cout << moves << '\n';

    for(int i = 0;i < n;i++)
        if(!ans[i])
            cout << s[i];
}