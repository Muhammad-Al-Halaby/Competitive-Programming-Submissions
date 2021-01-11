#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;


typedef long long ll;
typedef unsigned long long ull;
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

int main(){
    init();
    int n, mn = INT_MAX;
    cin >> n;
    int arr[n];
    arr[0] = 0;
    for(int i = 1;i < n;i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
        mn = min(mn, arr[i]);
    }

    if(mn < 0)
        arr[0] = abs(mn) + 1;
    else
        arr[0] = 1;

    vector<int> v;
    v.push_back(arr[0]);

    for(int i = 1;i < n;i++){
        arr[i] += arr[0];
        v.push_back(arr[i]);
    }

    sort(arr, arr + n);
    for(int i = 1;i <= n;i++)
        if(arr[i - 1] != i)
            return cout << -1, 0;

    for(int i = 0;i < n;i++)
        cout << v[i] << " ";
}