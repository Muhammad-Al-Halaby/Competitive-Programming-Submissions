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

int prefix[(int)1e5+5];
int seen[(int)1e5+5];
int freq[(int)1e5+5];

int main(){
    init();
    int n,k;
    long long sum = 0;
    cin >> n >> k;
    long long arr[n];
    for(int i =0 ;i<n;i++)
        cin >> arr[i];
    for(int i = 0;i<n;i++){
        if(k && arr[i] < 0){
            arr[i] *= -1;
            k--;
        }
        else if(k && arr[i] == 0)
            k = 0;
        else if(k && arr[i] > 0){
            if(k % 2 == 0)k=0;
            else{
                if(i == 0 || arr[i] < arr[i-1])
                    arr[i] *= -1;
                else
                    arr[i-1] *= -1;
                k=0;
            }
        }
    }
    if(k % 2)arr[n-1] *= -1;
    for(int i = 0;i<n;i++)
        sum += arr[i];
    cout << sum;
}