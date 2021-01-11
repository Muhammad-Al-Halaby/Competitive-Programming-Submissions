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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef pair<ll,int> plli;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
ll n, k, a, b;
int arr[100005];

ll fastPow(ll b, ll e){
    if(e == 0)
        return 1;
    ll partial = fastPow(b,e/2);
    partial = (partial * partial);
    if(e & 1)
        partial = (partial * b);
    return partial;
}

ll solve(int i, int j){
    if(j < i)return 0;
    int avengers = 0;

    avengers = upper_bound(arr, arr + k, j) - lower_bound(arr, arr + k, i);

    ll cost;

    if(avengers)
        cost = b * avengers * (j - i + 1);
    else{
        cost = a;
        return cost;
    }
    if(i != j){
        ll leftHalf = solve(i,(i + j) / 2);
        ll rightHalf = solve((i + j) / 2 + 1,j);
        cost = min(cost, leftHalf + rightHalf);
    }
    return cost;
}
int main(){
    init();
    cin >> n >> k >> a >> b;
    int len = fastPow(2,n);
    for(int i = 0;i < k;i++){
        cin >> arr[i];
    }
    sort(arr, arr + k);
    cout << solve(1, len);
}