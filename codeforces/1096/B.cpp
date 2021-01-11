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
typedef pair<int,int> pi;

void init()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

//int dx[] = {-1,1,0,0};
//int dy[] = {0,0,-1,1};

//int dx[] = {-1,1,0,0,1,-1,1,-1};
//int dy[] = {0,0,-1,1,1,-1,-1,1};

//    int powres[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};

ll power(ll b, ll p)
{
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    if(p & 1)res *= b;
    return res;
}

int freq[30];

int main()
{
    init();
    int n;
    cin >> n;
    ll ans = 0;
    string s;
    cin >> s;
    char c1 = s[0], c2 = s[n-1];
    int i;
    for(i = 1;i < n;i++)
        if(s[i] != s[0])break;
    int j;
    for(j = n-2;j >= 0;j--)
        if(s[j] != s[n-1])break;

    int left = i + 1;
    int right = n - (j + 1) + 1;

    if(c1 == c2){
        ans = (ll)left * right ;
    }
    else if(c1 != c2){
        ans += left + right - 1;
    }

    ans %= 998244353;

    cout << ans;
}

