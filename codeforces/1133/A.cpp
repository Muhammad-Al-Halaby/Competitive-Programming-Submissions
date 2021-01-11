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
    //init();
    int h1,m1,h2,m2;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);

    int totalduration = (h2 - h1) * 60 + (m2 - m1);
    totalduration /= 2;

    int hr = totalduration / 60;
    int mn = totalduration % 60;

    h1 += hr;
    m1 += mn;

    if(m1 > 59){
        h1 += m1 / 60;
        m1 = m1 % 60;
    }

    cout << ((h1 < 10)? "0":"");
    cout << h1;
    cout << ":";
    cout << ((m1 < 10)? "0":"");
    cout << m1;
}