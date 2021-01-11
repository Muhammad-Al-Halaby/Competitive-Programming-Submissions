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
    int n, k, ans;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    char last = s[0];
    ans = s[0] - 'a' + 1;
    k--;
    for(int i = 1;k && i < n;i++){
        if(s[i] - last >= 2){
            k--;
            ans += s[i] - 'a' + 1;
            last = s[i];
        }
    }
    if(k)
        cout << -1;
    else
        cout << ans;
}