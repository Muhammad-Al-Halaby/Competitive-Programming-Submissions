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
    int n, ans = 0;
    cin >> n;
    ll arr[n+1];
    ll even[n+1] = {0};
    ll odd[n+1] = {0};
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        if(i & 1)
            odd[i] = arr[i];
        else
            even[i] = arr[i];

        odd[i] += odd[i-1];
        even[i] += even[i-1];
    }

    for(int i = 1;i <= n;i++){
        ll o = 0, e = 0;
        o += odd[i-1];
        e += even[i-1];

        e += odd[n] - odd[i];
        o += even[n] - even[i];

        if(o == e)
            ans++;
    }
    cout << ans;
}