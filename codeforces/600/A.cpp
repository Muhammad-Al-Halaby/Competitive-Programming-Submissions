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

bool isInteger(string s){
    for(int i = 0;i < s.size();i++)
        if(!isdigit(s[i]))
            return 0;
    return 1;
}

int main(){
    init();
    string s;
    cin >> s;

    vector<string> a,b;
    string t = "";
    for(int i = 0;i < s.size() + 1;i++){
        if(i == s.size() || s[i] == ',' || s[i] == ';'){
            if(isInteger(t) && (t.size() == 1 || (t.size() > 1 && t[0] != '0')))
            a.push_back(t);
        else
            b.push_back(t);

            t = "";
        }
        else t += s[i];
    }

    if(a.size() == 0)cout << "-";
    else{cout << "\"";loop(i,0,a.size()){cout << a[i];if(i < a.size() - 1)cout << ',';}cout << "\"";}
    cout << '\n';
    if(b.size() == 0)cout << "-";
    else{cout << "\"";loop(i,0,b.size()){cout << b[i];if(i < b.size() - 1)cout << ',';}cout << "\"";}
}