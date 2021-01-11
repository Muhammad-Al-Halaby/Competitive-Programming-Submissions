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

int prefix[1000];
int main(){
    init();
    int n,k;
    cin >> n >> k;
    int arr[n+1];
    for(int i = 1;i<=n;i++){
        int x;
        cin >> x;
        arr[i] = arr[i-1] + x;
    }
    double maximum = -1;
    for(int i = 1;i<=n;i++){
        for(int j = i+k-1;j<=n;j++){
            double sum = arr[j] - arr[i-1];
            double avg = sum / (j-i+1);
            maximum = max(maximum,avg);
        }
    }
    printf("%.6f",maximum);
}