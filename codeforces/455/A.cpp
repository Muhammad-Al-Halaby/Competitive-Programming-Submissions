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

bool isPrime(int n);
void listPrimes(int n);
int minDiff(int arr1[], int arr2[]);
int factorial(int n);
int binarySearch(int arr[], int l, int r, int d);
double distanceTwoPoints(int x1,int y1, int x2, int y2);

int fr[int(1e5)+5];
long long dp[int(1e5)+5];

int main(){
   init();
   int n,mx=0;
   cin >> n;
   for(int i = 0;i<n;i++){
       int x;
        cin >> x;
        fr[x]++;
        mx = max(mx,x);
   }
    dp[1] = fr[1];
    for(int i = 2;i<=(int)1e5+5;i++){
        dp[i] = max(dp[i-1],dp[i-2]+(long long)i*fr[i]);
    }
    cout << dp[mx];
}