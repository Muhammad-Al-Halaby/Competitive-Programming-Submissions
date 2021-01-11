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
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int main(){
    init();
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int strict = 1;
    for(int i = 0;i < n-1;i++)
        if(arr[i] >= arr[i+1])strict = 0;

    if(strict)
        return cout << 0, 0;

    cout << n + 1 << '\n';

    cout << 1 << " " << n << " " << 900000 << '\n';

    for(int i = 0;i < n;i++)
        cout << 2 << " " << i + 1 << " " << (900000 + arr[i]) - i << '\n';
}
