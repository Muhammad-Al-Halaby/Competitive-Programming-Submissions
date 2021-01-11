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

int fr[200];

int main(){
    init();
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        fr[x % k]++;
    }

    int ans = (fr[0] / 2) * 2;
    for(int i = 1;i < k;i++){
        if(i == k - i){
                ans += (fr[i] / 2) * 2;
                fr[i] = 0;
        }
        else{
            ans += min(fr[i],fr[k-i]) * 2;
            fr[i] = 0;
            fr[k-i] = 0;
        }
    }

    cout << ans;

}