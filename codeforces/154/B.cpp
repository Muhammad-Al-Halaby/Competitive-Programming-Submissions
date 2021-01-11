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

#define MAXN 100000+9

int primes[MAXN];
vector<int> factors[MAXN];
void sieve(){
    //primes[0] = primes[1] = 1;
    factors[0].push_back(1);
    factors[1].push_back(1);
    int step = 1;
    for(ll i = 2;i <= MAXN;i+=step){
        if(!primes[i]){
            //primes[i] = i;
            for(ll j = i;j < MAXN;j += i){
                factors[j].push_back(i);
                if(j != i)primes[j] = i;
            }
        }
        if(i == 3)step++;
    }
}
set<int> factorsCnt[MAXN];
int status[MAXN];
int previouslyOn[MAXN];

int main(){
    init();
    sieve();

    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        char c;
        int x;
        cin >> c >> x;
        if(c == '+'){
            if(status[x])
                cout << "Already on\n";
            else{
                bool b = 1;
                for(int j = 0;j < factors[x].size();j++){
                    if(!factorsCnt[factors[x][j]].empty()){
                        cout << "Conflict with " << *factorsCnt[factors[x][j]].begin() << '\n';
                        b = 0;
                        break;
                    }
                }

                if(b){
                    for(int j = 0;j < factors[x].size();j++)
                        factorsCnt[factors[x][j]].insert(x);

                    status[x] = 1;
                    cout << "Success\n";
                }
            }
        }
        else{
            if(status[x]){
                status[x] = 0;
                for(int j = 0;j < factors[x].size();j++)
                    factorsCnt[factors[x][j]].erase(x);
                cout << "Success\n";
            }
            else
                cout << "Already off\n";
        }
    }
}