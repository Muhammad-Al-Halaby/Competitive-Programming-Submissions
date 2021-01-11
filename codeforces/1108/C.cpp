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
    int n;
    cin >> n;
    string s,t = "";
    cin >> s;
    char colors[] = {'R', 'G', 'B'};
    int arr[3][3] = {0};
    for(int i = 0;i < n;i++){
        if(s[i] == 'R')
            arr[i%3][0]++;
        else if(s[i] == 'G')
            arr[i%3][1]++;
        else if(s[i] == 'B')
            arr[i%3][2]++;
    }

    int c1,c2,c3;
    int ans = INT_MAX;
    for(int i = 0;i < 3 ;i++){
        for(int j = 0;j < 3;j++){
            if(i == j)continue;
            for(int k = 0;k < 3;k++){
                if(i == k || j == k)continue;
                int cost = (arr[0][0] + arr[0][1] + arr[0][2]) - arr[0][i];
                cost += (arr[1][0] + arr[1][1] + arr[1][2]) - arr[1][j];
                cost += (arr[2][0] + arr[2][1] + arr[2][2]) - arr[2][k];
                if(cost < ans){
                    ans = cost;
                    c1 = colors[i];
                    c2 = colors[j];
                    c3 = colors[k];
                }
            }
        }
    }

    for(int i = 0;i < n;i++){
        if(i % 3 == 0){
            t += c1;
        }
        else if(i % 3 == 1){
            t += c2;

        }
        else{
            t += c3;
        }
    }
    cout << ans << '\n' << t;
}
