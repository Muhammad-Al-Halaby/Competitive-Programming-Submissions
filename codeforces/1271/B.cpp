#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2e5 + 5, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int check(string s){
    int okw = 1, okb = 1;
    for(int i = 0;i < s.size();i++){
        okw &= s[i] == 'W';
        okb &= s[i] == 'B';
    }

//        if(okw) cout << "White\n" << endl;
//        if(okb) cout << "Black\n" << endl;
    return okw || okb;
}
int main(){
    init();

    int n;  cin >> n;
    string s;   cin >> s;

    //white
    string x = s;
    vector<int> ans;
    for(int i = 0;i + 1< n;i++){
        if(x[i] == 'B'){
            x[i] = 'W';
            if(x[i + 1] == 'B')  x[i + 1] = 'W';
            else x[i + 1] = 'B';
            ans.push_back(i + 1);
        }
    }

    if(check(x)){
        cout << ans.size() << '\n';
        for(auto v : ans)
            cout << v << " ";

        return 0;
    }

    ans.clear();
    x = s;
    for(int i = 0;i + 1< n;i++){
        if(x[i] == 'W'){
            x[i] = 'B';
            if(x[i + 1] == 'B')  x[i + 1] = 'W';
            else x[i + 1] = 'B';
            ans.push_back(i + 1);
        }
    }

    if(check(x)){
        cout << ans.size() << '\n';
        for(auto v : ans)
            cout << v << " ";

        return 0;
    }

    cout << -1;
}


