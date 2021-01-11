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

vector<int> divisors[200];

int main(){
    init();
    int n;
    cin >> n;
    int arr[n], sum = 0;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
        for(int i = 1;i <= 100;i++){
        int n = i;
        for(ll j = 2;j * j <= n;j++){
            if(n % j == 0){
                divisors[i].push_back(j);
                divisors[i].push_back(n / j);
            }
        }
    }
    for(int i = 1;i <= 100;i++){
        sort(divisors[i].begin(), divisors[i].end());
    }
    
    int maxdiff = 0;
    
    sort(arr,arr + n);
    
    for(int i = n-1;i >= 0;i--){
        for(int j = 0;j < divisors[arr[i]].size();j++){
            int div = divisors[arr[i]][j];
            int diff = arr[i] * (div - 1) / div + arr[0] * (1 - div);
            maxdiff = max(maxdiff,diff);
        }
    }
    cout << sum - maxdiff;
}