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
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    int s  = 0;
    while(s < n && arr[s] == 1)s++;

    int e = n - 1;
    while(e >= 0 && arr[e] == 1)e--;

    int mx = 0, cnt = 0;
    for(int i = s;i <= e;i++){
        if(arr[i] == 1)
            cnt++;
        else{
            mx = max(mx,cnt);
            cnt = 0;
        }
    }

    int ans = (n - (e + 1)) +  s;
    ans = max(ans, mx);

    cout << ans;
}