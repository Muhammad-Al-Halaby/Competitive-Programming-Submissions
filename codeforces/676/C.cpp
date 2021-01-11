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
#define MOD ll (1e9 + 7)


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

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
    int n, k, ans = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[n];
    int b[n];
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for(int i = 0;i < n;i++){
        if(s[i] == 'a')a[i]++;
        else b[i]++;
    }

    partial_sum(a, a + n, a);
    partial_sum(b, b + n, b);

    for(int i = 0;i < n;i++){
        if(s[i] == 'a'){
            //make it a's
            int pos = upper_bound(b, b + n, b[i] + k)- b - 1;
            ans = max(ans, pos - i + 1);
            //make it b's
            pos = upper_bound(a, a + n, a[i] + k - 1)- a - 1;
            ans = max(ans, pos - i + 1);
        }
        else{
            //make it a's
            int pos = upper_bound(b, b + n, b[i] + k - 1)- b - 1;
            ans = max(ans, pos - i + 1);
            //make it b's
            pos = upper_bound(a, a + n, a[i] + k)- a - 1;
            ans = max(ans, pos - i + 1);
        }
    }
    cout << ans;
}