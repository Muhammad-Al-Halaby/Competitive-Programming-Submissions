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
//#define modulo ll (1e9 + 7)
#define modulo ll (1e6 + 3)
const long double PI = 3.141592653589793238L;


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int main(){
    init();

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt[3] = {0};
    for(int i = 0;i < n;i++)
        cnt[s[i] - '0']++;


    if(cnt[0] == cnt[1] && cnt[0] == cnt[2])
        return cout << s, 0;

    int changes[3];
    for(int i = 0;i < 3;i++)
        changes[i] = max(0, n / 3 - cnt[i]);


    for(int i = n - 1;i >= 0;i--){
        int x = s[i] - '0';
        if(x == 2)continue;
        if(cnt[x] > n / 3 && changes[2]){
            changes[2]--;
            cnt[x]--;
            cnt[2]++;
            s[i] = '2';
        }
    }

    for(int i = 0;i < n;i++){
        int x = s[i] - '0';
        if(x == 0)continue;
        if(cnt[x] > n / 3 && changes[0]){
            changes[0]--;
            cnt[x]--;
            cnt[0]++;
            s[i] = '0';
        }
    }

    vector<int> twos, zeros;
    for(int i = 0;i < n;i++)
        if(s[i] == '2')twos.push_back(i);
        else if(s[i] == '0')zeros.push_back(i);


    int i = 0;
    while(changes[1] && cnt[2] > n / 3){
        changes[1]--;
        s[twos[i++]] = '1';
        cnt[2]--;
        cnt[1]++;
    }

    i = zeros.size() - 1;
    while(changes[1] && cnt[0] > n / 3){
        changes[1]--;
        s[zeros[i--]] = '1';
        cnt[0]--;
        cnt[1]++;
    }
    cout << s;
}
