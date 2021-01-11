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
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    ll anst = 0, anscost = 1e18;
    for(int t = 1;t <= 100;t++){
        ll cost = 0;
        for(int i = 0;i < n;i++){
            if(abs(arr[i] - t) > 1)cost += abs(arr[i] - t) - 1;
        }
        if(cost < anscost){
            anscost = cost;
            anst = t;
        }
    }
    cout << anst << " " << anscost;
}