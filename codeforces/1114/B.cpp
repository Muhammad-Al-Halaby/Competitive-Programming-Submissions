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

int fr[(int)1e7];
int main(){
    init();
    int n, m, k;
    map<int, int> mp;
    cin >> n >> m >> k;
    int a[n];
    pii b[n];
    for(int i =0 ;i < n;i++){
        cin >> a[i];
        b[i].F = a[i];
        b[i].S = i;
    }
    sort(b, b + n);

    reverse(b, b + n);
    for(int i = 0;i < m*k;i++){
        mp[b[i].S]=1;
    }
    int ele = 0;
    ll sum = 0;
    vector<int> ans;
    for(int i = 0;i < n;i++){
        if(mp[i] == 1){
                ele++;
                sum += a[i];
        }

        if(ele == m){
            ele = 0;
            ans.push_back(i+1);
        }
    }
    cout << sum << '\n';
    for(int i = 0;i < k-1;i++){
        cout << ans[i] << " ";
    }

}