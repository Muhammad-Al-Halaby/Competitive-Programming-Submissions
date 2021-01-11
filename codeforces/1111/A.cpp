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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef pair<ll,int> plli;

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
    string s, t;
    cin >> s >> t;
    char vow[]= {'a', 'e', 'i', 'o' ,'u'};
    if(s.size() != t.size())
        return cout << "No", 0;
    for(int i = 0;i < s.size();i++){
        int x = 0, y = 0;
        for(int j = 0;j < 5;j++){
            if(s[i] == vow[j])x=1;
            if(t[i] == vow[j])y=1;
        }
        if(x != y)
            return cout << "No", 0;
    }
    cout << "Yes";
}
