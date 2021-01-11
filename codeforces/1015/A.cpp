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

bool sortbysecond(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

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
    int n,m,cnt = 0;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int l,r;
        cin >> l >> r;
        fr[l]++;
        fr[r+1]--;
    }

    for(int i = 1;i<=m;i++){
        fr[i] += fr[i-1];
        if(fr[i] == 0)cnt++;
    }
    cout << cnt << '\n';
    for(int i = 1;i<=m;i++){
        if(fr[i] == 0)
            cout << i << " ";
    }
}