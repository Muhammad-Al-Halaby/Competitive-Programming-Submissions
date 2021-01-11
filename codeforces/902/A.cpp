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
int fr[(int)1e5+5];

int main(){
    init();
    int n,m;
    int maxy=0,exist=1;
    cin >> n >> m;
    for(int i = 0;i < n; i++){
        int x,y;
        cin >> x >> y;
        if(x <= m && maxy < x)exist=0;
        for(int j = x;j<=y;j++)
            fr[j]=1;
        maxy = max(maxy,y);
    }
    for(int i = 0;i<=m;i++)if(fr[i] == 0)exist=0;
    if(exist) cout << "YES";
    else cout << "NO";
}