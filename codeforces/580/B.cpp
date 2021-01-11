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

    int n, d;
    cin >> n >> d;

    pair<int, ll> arr[n];

    for(int i = 0;i < n;i++)
        cin >> arr[i].F >> arr[i].S;

    sort(arr, arr + n);

    for(int i = 0;i < n;i++)
        (i)?arr[i].S += arr[i-1].S:0;

    ll mx = 0;
    for(int i = 0;i < n;i++){
        int l = 0, r = n - 1;
        int val = arr[i].F + d - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(arr[mid].F > val)r = mid - 1;
            else l = mid + 1;
        }

        mx = max(mx,arr[l-1].S - ((i)?arr[i-1].S:0));

    }
    cout << mx;
}