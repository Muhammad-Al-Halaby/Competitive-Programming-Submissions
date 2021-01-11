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

int fr[200];
int main(){
    init();
    int n, m;
    cin >> n >> m;
    int arr[m];
    for(int i = 0;i < m;i++){
        int x;
        cin >> x;
        fr[x]++;
    }

    auto check = [&](int days){
        int can = 0;
        if(days)
            for(int i = 0;i < 105;i++){
                can += fr[i] / days;
            }
        if(can >= n)
            return 1;
        return 0;
    };

    int l = 0, r = 150;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(check(mid))l = mid + 1;
        else r = mid - 1;
    }
    cout << max(0,l - 1);
}