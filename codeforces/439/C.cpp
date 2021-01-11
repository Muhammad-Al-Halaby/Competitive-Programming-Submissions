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
typedef unsigned long long ull;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 1e5 + 5, M = 1e6 + 5, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int main(){
    init();

    int n, k, p;  cin >> n >> k >> p;
    vector<int> e, o;
    vector<int> part[k];
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        if(x & 1)   o.push_back(x);
        else e.push_back(x);
    }

    for(int i = 0;i < p;i++){
        if(!e.empty())  part[i].PB(e.back()), e.pop_back();
        else{
            if(o.size() >= 2){
                part[i].PB(o.back()), o.pop_back();
                part[i].PB(o.back()), o.pop_back();
            }
            else
                return cout << "NO", 0;

        }
    }

    for(int i = p;i < k;i++){
        if(!o.empty())
            part[i].PB(o.back()), o.pop_back();
        else
            return cout << "NO", 0;
    }

    //odd always changes parity
    if(o.size() & 1)    return cout << "NO", 0;

    //even number of odds = even doesn't affect parity
    while(!o.empty())  part[0].PB(o.back()), o.pop_back();
    // even doesn't change parity
    while(!e.empty())  part[0].PB(e.back()), e.pop_back();

    //Finally
    cout << "YES\n";
    for(int i = 0;i < k;i++){
        cout << part[i].size() << " ";
        for(int j = 0;j < part[i].size();j++){
            cout << part[i][j] << " ";
        }
        cout << '\n';
    }
}
