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

bool cmp(pii a, pii b){
    if(a.F == b.F)
        return a.S < b.S;
    return a.F > b.F;
}

int main(){
    int n, k;
    cin >> n >> k;
    pii arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i].F >> arr[i].S;
    sort(arr, arr + n, cmp);

    int place = 1, p = arr[0].F, t = arr[0].S, ans = 1;
    int teams[100] = {0};

    for(int i = 1;i < n;i++){
        int pi = arr[i].F;
        int ti = arr[i].S;
        if(p == pi && t == ti)ans++;
        else{
            teams[place] = ans + teams[place-1];
            place++;
            ans = 1;
            p = pi;
            t = ti;
        }
    }
    teams[place] = ans + teams[place-1];

    for(int i = 1;i <= n;i++)
        if(teams[i] >= k){
            cout << teams[i]-teams[i-1] << endl;
            return 0;
        }
}