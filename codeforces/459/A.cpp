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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == c)
        cout << a + hypot(a-c,b-d) << " " << b << " " << c + hypot(a-c,b-d) << " " << d;
    else if(b == d)
        cout << a << " " << b + hypot(a-c,b-d) << " " << c << " " << d + hypot(a-c,b-d);
    else if(abs(a - c) == abs(b - d))
        cout << a << " " << d << " " << c << " " << b << " ";
    else cout << -1;
}