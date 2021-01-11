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

int fr[(int)1e6];
int slots[(int)1e6];

int main(){
    init();
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        if(x <= 0){
            ans += abs(x) + 1;
            fr[1]++;
            slots[1] = 1;
        }
        else if(x > n){
            ans += abs(x-n);
            fr[n]++;
            slots[n] = 1;
        }
        else{
            fr[x]++;
            slots[x] = 1;
        }
    }

    int i = 1, slot = 1;
    while(i <= n){
        if(fr[i] <= 1){
            i++;
            continue;
        }
        while(slots[slot] != 0 && slot <= n)slot++;
        ans += abs(i - slot);
        slots[slot] = 1;
        fr[slot]++;
        fr[i]--;
    }
    cout << ans;
}