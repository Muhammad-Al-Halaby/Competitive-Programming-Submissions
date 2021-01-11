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

int main(){
    init();
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];
    vector<int> diff;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        if(i)
            diff.push_back(abs(arr[i]-arr[i-1]));
    }
    ll ans = n;
    if(ans <= k)
        return cout << ans, 0;
    int tapes = n;
    sort(diff.begin(),diff.end());
    for(int i  = 0;i < diff.size();i++){
        tapes--;
        ans--;
        ans += diff[i];
        if(tapes <= k)break;
    }
    cout << ans;
}