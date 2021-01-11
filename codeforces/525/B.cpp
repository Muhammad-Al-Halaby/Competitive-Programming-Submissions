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
    init();
    string s;
    cin >> s;
    int ok[s.size()] = {0};
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int l, r;
        cin >> l;
        r = s.size() - l + 1;
        l--, r--;
        ok[l]++;
        if(r + 1 < s.size())ok[r + 1]--;
    }

    partial_sum(ok, ok + s.size(), ok);

    for(int i = 0;i < s.size();i++){
        if(ok[i] & 1)
            cout << s[s.size() - i - 1];
        else
            cout << s[i];
    }
}