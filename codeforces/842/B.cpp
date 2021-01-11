#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge

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
    #ifndef OnlineJudge
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

int main(){
   init();
   int r,d,n,ans = 0;
   cin >> r >> d >> n;
   for(int i = 0;i<n;i++){
       int x,y,cr;
       cin >> x >> y >> cr;

       double dist = distanceTwoPoints(x,y,0,0);
       if(dist + cr <= r && dist-cr >= (r-d))
        ans++;
   }
   cout << ans;
}

double distanceTwoPoints(int x1,int y1, int x2, int y2){
    return sqrt(((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)));
}