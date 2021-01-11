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

int main(){
    init();
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int pile = 1;
    int p[150] = {0};
    for(int i = 0;i < n;i++){
        if(arr[i] >= i)
            p[pile]++;
        else{
            int x = 1;
            for(int j = 1;j <= pile;j++){
                if(p[j] <= arr[i]){
                    p[j]++;
                    x = 0;
                    break;
                }
            }
            if(x){
                pile++;
                p[pile]++;
            }
        }
    }
    cout << pile;
}