#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
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
    init();

    string s;
    cin >> s;

    int q;
    cin >> q;
    for(int i = 0;i < q;i++){
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        k %= (r - l + 1);

        if(!k)continue;
        else k--;

        string t = s;

        for(int j = r - k, p = l;j <= r;p++, j++)t[p] = s[j];
        for(int j = l, p = l + k + 1;j < r - k;j++, p++)t[p] = s[j];

        s = t;

    }
        cout << s << endl;
}