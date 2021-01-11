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
#define EPS 1e-6
#define modulo ll (1e9 + 7)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}
int Max = 1e7 + 5;
int prefix[(int)1e7+7];
int prime[(int)1e7+7];
int fr[(int)1e7+7];

void sieve(){
    prime[0] = prime[1] = 1;
    for(int i = 1;i<=Max;i++){
        if(prime[i])
            continue;
        else{
            for(int j = i*2;j<=Max;j+=i)
                prime[j] = 1;
        }
    }
}
int main(){
    init();
    ll n,m,suma=0,sumb=0;
    cin >> n >> m;
    int diff[n];
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        diff[i] = a - b;
        suma += a;
        sumb += b;
    }

    if(sumb > m)
        cout << -1;
    else if(suma <= m)
        cout << 0;
    else{
        int cnt = 0;
        sort(diff,diff+n);
        for(int i = n - 1;i>=0;i--){
            cnt++;
            suma -= diff[i];
            if(suma <= m)
                break;
        }
        cout << cnt;
    }
}