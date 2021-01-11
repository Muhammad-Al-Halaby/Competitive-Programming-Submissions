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

int fr[int(1e6) + 1];

int main(){
    init();
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    int l = 0, r = 0, distinct = 0, ans = 0, ansl = 0, ansr = 0;

    while(r < n){
        if(!fr[arr[r]])distinct++;
        fr[arr[r]]++;
        while(distinct > k){
            fr[arr[l]]--;
            if(!fr[arr[l]])distinct--;
            l++;
        }
        if(r - l + 1 > ans){
            ans = r - l + 1;
            ansl = l + 1;
            ansr = r + 1;
        }
        r++;
    }
    cout << ansl << " " << ansr;
}