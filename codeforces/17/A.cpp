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
#define MOD ll (1e9 + 7)


typedef long long ll;
typedef unsigned long long ull;
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

#define MAXN 1000+9

int primes[MAXN];
vector<int> p;
void sieve(){
    primes[0] = primes[1] = 1;
    int step = 1;
    for(ll i = 2;i <= MAXN;i+=step){
        if(!primes[i]){
            primes[i] = i;
            p.push_back(i);
            for(ll j = i * i;j < MAXN;j += i)
                primes[j] = i;
        }
        if(i == 3)step++;
    }
}

int main(){
    init();
    sieve();
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for(int i = 1;i < p.size();i++){
        if(p[i] + p[i-1] + 1 > n)break;
        if(primes[p[i] + p[i-1] + 1] == p[i] + p[i-1] + 1)
            cnt++;
    }

    if(cnt >= k)
        cout << "YES";
    else
        cout << "NO";
}