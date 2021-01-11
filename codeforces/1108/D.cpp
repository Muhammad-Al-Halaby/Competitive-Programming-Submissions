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

set<ll> divisors;
int fr[(int)1e5];

void divide(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            fr[i]--;
            fr[n/i]--;
        }
    }
}


int main(){
    init();
    int n, ans = 0;
    cin >> n;
    string s,t = "";
    cin >> s;
    char colors[] = {'R', 'G', 'B'};

    for(int i = 0;i < n-1;i++){
        if(s[i] == s[i+1]){
            ans++;
            //sequence
            if((i + 2 < n && s[i+1] == s[i+2]) || i + 2 >= n){
                for(int j = 0;j < 3;j++){
                    if(s[i+1] != colors[j]){
                        s[i+1] = colors[j];
                        break;
                    }
                }
            }

            else{
                    for(int j = 0;j < 3;j++){
                        if(s[i+1] != colors[j] && colors[j] != s[i+2]){
                            s[i+1] = colors[j];
                            break;
                        }
                    }

            }
        }
    }
    cout << ans << '\n' << s;
}
