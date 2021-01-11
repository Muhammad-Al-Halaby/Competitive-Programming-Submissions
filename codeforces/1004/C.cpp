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
    int n;
    long long sum=0;
    cin >> n;
    int arr[n];
    set< pair<int,int> > s;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for(int i = n-1;i>=0;i--){
        if(seen[arr[i]]){
            prefix[i] = prefix[i+1];
        }
        else{
            prefix[i]= prefix[i+1] + 1;
            seen[arr[i]] = 1;
        }
    }
    for(int i = 0;i<n;i++){
        if(freq[arr[i]] > 1){
            sum += prefix[i];
        }
        else if(freq[arr[i]] > 0)
            sum +=  prefix[i] - 1;
        freq[arr[i]] = 0;
    }
    cout << sum;
}